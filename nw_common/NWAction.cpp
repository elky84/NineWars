#include "stdafx.h"
#include "NWAction.h"

#include "NWCard.h"
#include "NWProjectTile.h"
#include "NWBattle.h"
#include "NWSquad.h"

#include "NWDecide.h"

namespace NW
{

Action::Action()
	: m_PreDelay(true)
	, m_TargetingTurn(INFINITE_TARGETING_TIME)
	, m_TargetingType(Enum::Targeting::NONE)
	, m_MovingTime(0)
	, m_MoveValue(0.0f)
	, m_Direction(Diretion::NONE)
	, m_AttackMethod(AttackMethod::NONE)
{

}

Action::~Action()
{
	if( m_Card.get() )
	{
		m_Card->SetAction(NULL);
	}
}

void Action::DecideAttackMethod()
{
	//if( rand() % 100 < m_Card->VectorSkill()[0].Chance() )
	//{
	//	m_AttackMethod = AttackMethod::SKILL1;
	//}
	//else if( rand() % 100 < m_Card->VectorSkill()[1].Chance() )
	//{
	//	m_AttackMethod = AttackMethod::SKILL2;
	//}
	//else if( rand() % 100 < m_Card->VectorSkill()[2].Chance() )
	//{
	//	m_AttackMethod = AttackMethod::SKILL3;
	//}
	//else
	{
		m_AttackMethod = AttackMethod::NORMAL;
	}
}

void Action::Set(WEAK_DECIDE decide, WEAK_CARD card, WEAK_CARD target, Enum::MoveDecide::Type moveDecideType, Enum::Targeting::Type targetingType)
{
	m_Decide = decide;
	m_Card = card;
	m_Target = target;
	m_MoveDecideType = moveDecideType;
	m_TargetingType = targetingType;

	DecideAttackMethod();

	m_Card->SetAction(WEAK_ACTION(this));

	if ( 0 == rand() % 5 )
	{
		m_TargetingTurn = INFINITE_TARGETING_TIME;
	}
	else
	{
		Instance::CharacterStat character = m_Card->CharacterStat();
		INT n = ((character.Competitive() + character.Concentration() + character.AttackTendency()) - (character.Judgement() + character.Prediction() + character.DefenseTendency())) / 3;
		INT adjust = std::max(std::min(-5, n), -5);
		m_TargetingTurn = rand() % adjust + CHANGABLE_TARGETING_TIME;
	}
}

bool Action::Update()
{
	if( m_Card->isDead() ||
		m_Target.get() == NULL || 
		m_Target->isDead() )
	{
		m_Card->MoveEndAnimation();
		return false;
	}

	if( 0 < m_MovingTime )
	{
		--m_MovingTime;
		if( m_MoveValue == 0.0f)
		{
			Move();
			return true;
		}
		else
		{
			Moving();
			return true;
		}
	}

	if(INFINITE_TARGETING_TIME != m_TargetingTurn)
	{
		if( --m_TargetingTurn <= 0 )
			return false;
	}

	if ( fabs( Util::Math::PositionGap(m_Card->GetPosition(), m_Target->GetPosition() )) <= Range() )
	{
		if( true == Attack() )
		{
			m_MovingTime = DEFAULT_MOVING_TIME;
		}
		return true;
	}
	else // 사거리 밖일 때
	{
		if( false == Move() )
		{
			m_Card->MoveEndAnimation();
			return false;
		}

		m_MovingTime = DEFAULT_MOVING_TIME;
		return true;
	}
}

float Action::Range()
{
	switch(m_AttackMethod)
	{
	case AttackMethod::NORMAL:
		return m_Card->Range();
	case AttackMethod::SKILL1:
	case AttackMethod::SKILL2:
	case AttackMethod::SKILL3:
		return m_Card->VectorSkill()[m_AttackMethod].Info()->Range() * (CHARACTER_SIZE / 1.5f);
	default:
		return 0.0f;
	}	
}

bool Action::Attack()
{
	m_Card->Direction( Util::Math::LookAt(m_Card->GetPosition(), m_Target->GetPosition() ) );

	if(m_PreDelay)
	{
		switch(m_AttackMethod) // 딜레이 세팅
		{
		case AttackMethod::NORMAL:
			m_Card->PreDelay();
			break;
		case AttackMethod::SKILL1:
		case AttackMethod::SKILL2:
		case AttackMethod::SKILL3:
			m_Card->PostDelay(m_Card->VectorSkill()[m_AttackMethod].Info()->CastingTime());
			break;
		}

		m_PreDelay = false;
		return false;
	}

	m_Card->AttackAnimation();

	switch(m_AttackMethod) // 딜레이 세팅
	{
	case AttackMethod::NORMAL:
		m_Card->PostDelay();
		break;
	case AttackMethod::SKILL1:
	case AttackMethod::SKILL2:
	case AttackMethod::SKILL3:
		m_Card->PostDelay(m_Card->VectorSkill()[m_AttackMethod].Info()->Delay());
		break;
	}

	ProjectTile* projectile = new ProjectTile();
	projectile->Set(m_Card, m_Target, m_Battle, m_AttackMethod);
	m_Battle->Add(projectile);
	return true;
}

float Action::MoveValue()
{
	Instance::CharacterStat stat = m_Card->CharacterStat();
	switch(m_MoveDecideType)
	{
	case Enum::MoveDecide::CONTROL_SPEED: // 50 + ( ( ( 공격 성향 / ( 공격 성향 + 방어 성향 ) ) * 100 ) / 2 ) = 이렇게 나온 값이 그대로 % 이동속도로 적용된다.
		return (50.0f + ( ( stat.AttackTendency() / ( stat.AttackTendency() + stat.DefenseTendency() ) * 100.0f) / 2.0f)) / 100.0f * stat.Speed();
	case Enum::MoveDecide::MAINTAIN_SPEED: 
		{
			auto& mapMaintainSpeed = light::excel::Loader::Instance()->find<ExcelData::MaintainSpeedData>()->Map();
			float Adjust = 0.0f;

			float CurrentState = 0.0f;

			// ( 내 전투력 / ( 내 전투력 + 나를 타겟팅한 적군의 전투력 ) ) * 100 = 현재 상황 (정수만을 사용하며, 소수점 둘째자리부터 반 올림 한다. / 0.45 면 소수점 둘째자리까지 반올림 하여 1이 된다.)
			INT MyPower = m_Decide->Power(m_Card);
			INT TargetedPower = m_Decide->TargetedEnemyPower(m_Card);
			INT Devide = ( MyPower + TargetedPower);
			if( Devide != 0 )
			{
				CurrentState = (MyPower / Devide * 100.0f);
			}
			else
			{
				CurrentState = 100.0f;
			}

			CurrentState = std::max(0.0f, CurrentState);
			CurrentState = std::min(100.0f, CurrentState);

			for each(auto& val in mapMaintainSpeed)
			{
				auto& maintainSpeed = val.second;
				if( CurrentState <= maintainSpeed.Min() && maintainSpeed.Max() <= CurrentState )
				{
					Adjust += maintainSpeed.CurrentState();
				}
			}

			// ( 공격 성향 / ( 공격 성향 + 방어 성향 ) ) * 100 = 이동 성향 (정수만을 사용하며, 소수점 둘째자리부터 반 올림 한다. / 0.45 면 소수점 둘째자리까지 반올림 하여 1이 된다.)															
			float MoveTendency = stat.AttackTendency() / ( stat.AttackTendency() + stat.DefenseTendency() ) * 100.0f;

			for each(auto& val in mapMaintainSpeed)
			{
				auto& maintainSpeed = val.second;
				if( MoveTendency <= maintainSpeed.Min() && maintainSpeed.Max() <= MoveTendency )
				{
					Adjust += maintainSpeed.MoveTendency();
				}
			}

			// ( 아군 전투력 / ( 아군 전투력 + 적군 전투력 ) ) * 100 = 전체 흐름 (정수만을 사용하며, 소수점 둘째자리부터 반 올림 한다. / 0.45 면 소수점 둘째자리까지 반올림 하여 1이 된다.)															
			INT MyTeamPower = m_Decide->TeamPower(m_Card);
			INT EnemyTeamPower = m_Decide->TeamPower(m_Target);
			float WarSituation = 0.0f;
			if(EnemyTeamPower != 0)
			{
				WarSituation = MyTeamPower / (MyTeamPower + EnemyTeamPower) * 100.0f;
			}
			else
			{
				WarSituation = 100.0f;
			}

			WarSituation = std::max(0.0f, WarSituation);
			WarSituation = std::min(100.0f, WarSituation);

			for each(auto& val in mapMaintainSpeed)
			{
				auto& maintainSpeed = val.second;
				if( WarSituation <= maintainSpeed.Min() && maintainSpeed.Max() <= WarSituation )
				{
					Adjust += maintainSpeed.WarSituation();
				}
			}

			return Adjust * stat.Speed();
		}
	case Enum::MoveDecide::MAINTAIN_RANGE: // 50 + ( ( 방어 성향 / ( 공격 성향 + 방어 성향 ) ) * 100 ) / 2 = 이렇게 나온 값이 그대로 % 이동속도로 적용된다.
		{
			float moveValue = (50.0f + ( ( stat.DefenseTendency() / ( stat.AttackTendency() + stat.DefenseTendency() ) * 100.0f) / 2.0f)) / 100.0f * stat.Speed();

			float Gap = Util::Math::PositionGap( m_Card->GetPosition(), m_Target->GetPosition() );
			if( Gap - moveValue < Range() )
			{
				return -moveValue;
			}
			else
			{
				return moveValue;
			}
		}
	default:
		LOG_ERROR(_T("%s Invalid Move Value. [%d]"), __FUNCTIONW__, m_MoveDecideType);
		return 0.0f;
	}
}

bool Action::Moving()
{
	m_Card->MoveAnimation();
	switch(m_Direction)
	{
	case Diretion::STRAIGHT:
		return Route(m_Target->GetPosition());
	case Diretion::LEFT:
		return Route( light::POSITION_FLOAT(0.0f, m_Card->GetPosition().Y()) );
	case Diretion::RIGHT:
		return Route( light::POSITION_FLOAT((float)MAP_WIDTH, m_Card->GetPosition().Y()) );
	case Diretion::UP:
		return Route( light::POSITION_FLOAT(m_Card->GetPosition().X(), 0.0f) );
	case Diretion::DOWN:
		return Route( light::POSITION_FLOAT(m_Card->GetPosition().X(), (float)MAP_HEIGHT) );
	default:
		return false;
	}
}

bool Action::Move()
{
	m_MoveValue = MoveValue();

	if( fabs(m_MoveValue) <= 0.01f )
	{
		m_Card->MoveEndAnimation();
		return false;
	}

	m_Card->MoveAnimation();

	// 직선
	if( true == Route(m_Target->GetPosition()))
	{
		m_Direction = Diretion::STRAIGHT;
		return true;
	}

	// 직선을 우선시하고, 기존의 이동 방향은 이후에 유지한다.
	if( true == Moving() )
	{
		return true;
	}

	if( 0 < m_Target->GetPosition().Y() - m_Card->GetPosition().Y())
	{
		if( 0 < m_MoveValue)
		{
			// 아래로
			if( true == Route( light::POSITION_FLOAT(m_Card->GetPosition().X(), (float)MAP_HEIGHT) ) )
			{
				m_Direction = Diretion::DOWN;
				return true;
			}
		}
	}
	else
	{
		if( 0 < m_MoveValue)
		{
			// 위로
			if( true == Route( light::POSITION_FLOAT(m_Card->GetPosition().X(), 0.0f) ) )
			{
				m_Direction = Diretion::UP;
				return true;
			}
		}
	}

	if(	0 < m_Target->GetPosition().X() - m_Card->GetPosition().X() )
	{
		if( 0 < m_MoveValue)
		{
			// 오른쪽
			if( true == Route( light::POSITION_FLOAT((float)MAP_WIDTH, m_Card->GetPosition().Y()) ) )
			{
				m_Direction = Diretion::RIGHT;
				return true;
			}
		}
	}
	else
	{
		if( 0 < m_MoveValue)
		{
			// 왼쪽
			if( true == Route( light::POSITION_FLOAT(0.0f, m_Card->GetPosition().Y()) ) )
			{
				m_Direction = Diretion::LEFT;
				return true;
			}
		}
	}

	// 다 못감
	return false;
}

bool Action::Route(const light::POSITION_FLOAT& Destination)
{
	light::POSITION_FLOAT Position = m_Card->GetPosition();
	Position.Force(m_MoveValue, Destination);
	Position = light::POSITION_FLOAT(std::min(std::max(Position.X(), 0.0f), (float)MAP_WIDTH), std::min(std::max(Position.Y(), 0.0f), (float)MAP_HEIGHT));

	for each(WEAK_SQUAD squad in m_Battle->VectorSquad())
	{
		for each(auto& val in squad->MapAliveCard())
		{
			WEAK_CARD card = val.second;
			if(card == m_Card)
				continue;

			light::POSITION_FLOAT& CheckPosition = card->GetPosition();
			const INT XCheckSize = CHARACTER_SIZE / 4;
			const INT YCheckSize = CHARACTER_SIZE / 6;
			if( true == crash_check(light::RECT_FLOAT(CheckPosition.X() - XCheckSize, CheckPosition.Y() - YCheckSize, CheckPosition.X() + XCheckSize, CheckPosition.Y() + YCheckSize), Position) )
			{
				return false;
			}
		}
	}

	m_Card->SetPosition(Position);
	float Gap = Util::Math::PositionGap( m_Card->GetPosition(), Destination );
	if( Gap != 0.0f )
	{
		if( m_MoveValue <= 0.0f )
			m_Card->Direction( Util::Math::LookAt(m_Target->GetPosition(), m_Card->GetPosition() ) );
		else
			m_Card->Direction( Util::Math::LookAt(m_Card->GetPosition(), m_Target->GetPosition() ) );	
	}
	return true;
}

} // namespace NW