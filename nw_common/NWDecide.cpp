#include "stdafx.h"
#include "NWDecide.h"

#include "NWCard.h"
#include "NWBattle.h"
#include "NWSquad.h"
#include "NWAction.h"

namespace NW
{

Decide::Decide()
{

}

Decide::~Decide()
{

}

// 클래스에 따른 선차 판단 + 현재 HP % + 스킬 전투력 판단 = A								
// (공격 성향 + 대담성 + 적극성 + 승부욕) - (방어 성향 + 집중력 + 침착성 + 예측력) = B								
//	A + ( A * ( B / 100 ) ) = 내 전투력								
void Decide::CalcPower()
{
	m_mapPower.clear();
	VECTOR_SQUAD& vectorSquad = m_Battle->VectorSquad();
	for each(auto& val in vectorSquad)
	{
		for each(auto& it in val->MapAliveCard())
		{
			WEAK_CARD card = it.second;

			Instance::CharacterStat& character = card->CharacterStat();
			INT BasePoint = 20;

			INT TendencyPoint = (character.AttackTendency() + character.Boldness() + character.Aggressive() + character.Competitive()) - (character.DefenseTendency() + character.Concentration() + character.Calm() + character.Prediction() );
			INT Point = BasePoint + (BasePoint * (TendencyPoint / 100));

			m_mapPower[card] = Point;

			TEAM::type teamtype = vectorSquad[TEAM::RED]->isExist(card) == false ? TEAM::RED : TEAM::BLUE;
			m_mapTeamPower[teamtype] += Point;
		}
	}
}

POWER_DECIDE_VALUE Decide::Power(WEAK_CARD card)
{
	return m_mapPower[card];
}

// ( 나를 타겟팅한 적군의 전투력 / 나를 타겟팅한 적군의 숫자 ) * ( 0.7 + ( 나를 타겟팅한 숫자 / 10 ) = A														
// ※ 나를 타겟팅한 적군의 전투력 = "내 전력 판단"에 있는 수식을 활용하는 것으로 내 전투력을 판단하는 것처럼 아군, 적군 모두 자신의 전투력을 판단한 값을 끌어온다.
// ( 방어 성향 + 집중력 + 침착성 + 판단력 ) / (공격 성향 + 대담성 + 적극성 + 승부욕 + 방어 성향 + 집중력 + 침착성 + 판단력 ) * 100 =  B ( 소수점 둘째짜리 까지 반올림 한 뒤 정수로 만듬 )														
// ( 50 + A ) / 100 = C
// A * C = 나를 타겟팅 한 적군의 전투력 판단
POWER_DECIDE_VALUE Decide::TargetedEnemyPower(WEAK_CARD card)
{
	INT SUM = 0;
	INT COUNT = 0;
	for each(auto& val in m_mapPower)
	{
		WEAK_CARD checkcard = val.first;
		if(checkcard->GetAction().get() &&
			checkcard->GetAction()->GetTarget() == card)
		{
			SUM += val.second;
			++COUNT;
		}
	}

	if(COUNT != 0)
	{
		return (POWER_DECIDE_VALUE)((SUM / COUNT) * (0.7 + (COUNT / 10)));
	}

	return 0;
}

POWER_DECIDE_VALUE Decide::TeamPower(WEAK_CARD card)
{
	TEAM::type teamtype = m_Battle->VectorSquad()[TEAM::RED]->isExist(card) == false ? TEAM::RED : TEAM::BLUE;
	return m_mapTeamPower[teamtype];
}

WEAK_CARD Decide::SelectTarget(WEAK_CARD card, Enum::Targeting::Type& targetingType)
{
	auto& mapTargetingDecide = light::excel::Loader::Instance()->find<ExcelData::TargetingDecideData>()->Map();
	ExcelData::TargetingDecide& targetingDecide = mapTargetingDecide[card->Class()];
	Instance::CharacterStat& character = card->CharacterStat();

	VECTOR_SQUAD& vectorSquad = m_Battle->VectorSquad();
	WEAK_SQUAD rival = vectorSquad[TEAM::RED]->isExist(card) == true ? vectorSquad[TEAM::BLUE] : vectorSquad[TEAM::RED];
	if(rival->isAllDie())
		return NULL;

	INT SUM = 0;
	MAP_TARGETING mapTargeting[Enum::Targeting::MAX];
	for each(auto& val in rival->MapAliveCard())
	{
		WEAK_CARD enemy = val.second;

		{
			INT Point = 0;
			INT TendencyPoint = character.DefenseTendency() + character.Concentration() + character.Competitive();

			Point = TendencyPoint + (INT)(TendencyPoint * targetingDecide.NearDistance());

			INT AdjustPoint = 0;
			float Gap = fabs(card->GetPosition().X() - enemy->GetPosition().X()) + fabs(card->GetPosition().Y() - enemy->GetPosition().Y());
			if( Gap <= card->Range() )
				AdjustPoint = 10;
			else
				AdjustPoint = 1;


			Point = Point * AdjustPoint;

			mapTargeting[Enum::Targeting::NEAR_DISTANCE].insert(MAP_TARGETING::value_type(Point, enemy));
			SUM += Point;
		}

		{
			INT Point = 0;
			INT TendencyPoint = character.Calm() + character.Concentration() + character.Judgement();

			Point = TendencyPoint + (INT)(TendencyPoint * targetingDecide.LessHP());


			float HP_Percentage = enemy->GetHP() / enemy->GetMaxHP() * 10;
			INT AdjustPoint = std::min(1, (INT)(10 - HP_Percentage));

			Point = Point * AdjustPoint;

			mapTargeting[Enum::Targeting::LESS_HP].insert(MAP_TARGETING::value_type(Point, enemy));
			SUM += Point;
		}

		{
			INT Point = 0;
			INT TendencyPoint = character.AttackTendency() + character.Boldness() + character.Prediction();

			Point = TendencyPoint + (INT)(TendencyPoint * targetingDecide.StrongClass());


			bool isWeakClass = false;
			for each(auto& val in light::excel::Loader::Instance()->find<ExcelData::ClassData>()->Map()[card->Class()].VectorStrong())
			{
				if( enemy->Class() == val )
				{
					isWeakClass = true;
					break;
				}
			}

			bool isStrongClass = false;
			for each(auto& val in light::excel::Loader::Instance()->find<ExcelData::ClassData>()->Map()[enemy->Class()].VectorStrong())
			{
				if( card->Class() == val )
				{
					isStrongClass = true;
					break;
				}
			}

			INT AdjustPoint = 0;
			if(isWeakClass)
				AdjustPoint = 10;
			else if(isStrongClass)
				AdjustPoint = 1;
			else
				AdjustPoint = 5;

			Point = Point * AdjustPoint;

			mapTargeting[Enum::Targeting::STRONG_CLASS].insert(MAP_TARGETING::value_type(Point, enemy));
			SUM += Point;
		}
	}

	INT n = rand() % SUM;
	for(int i = 0; i < _countof(mapTargeting); ++i)
	{
		auto& val = mapTargeting[i];
		for each(auto& it in val)
		{
			TARGETING_VALUE score = it.first;
			WEAK_CARD enemy = it.second;

			if( n < score)
			{
				targetingType = (Enum::Targeting::Type)i;
				return enemy;
			}
			n -= score;
		}
	}

	LOG_ERROR(_T("Coding error. check sum & mapTargeting"));
	return NULL;
}

Enum::MoveDecide::Type Decide::MoveDecide(WEAK_CARD card)
{
	auto& mapMoveDecide = light::excel::Loader::Instance()->find<ExcelData::MoveDecideData>()->Map();
	ExcelData::MoveDecide& moveDecide = mapMoveDecide[card->Class()];
	Instance::CharacterStat& character = card->CharacterStat();

	INT SUM = 0;
	MAP_MOVE mapMove;
	{
		INT TendencyPoint = character.AttackTendency() + character.Boldness() + character.Aggressive();

		INT Point = TendencyPoint + (INT)(TendencyPoint * moveDecide.ControlSpeed());

		mapMove[Enum::MoveDecide::CONTROL_SPEED] = Point;
		SUM += Point;
	}

	{
		INT TendencyPoint = character.TeamWork() + character.Prediction() + character.Judgement();

		INT Point = TendencyPoint + (INT)(TendencyPoint * moveDecide.MaintainSpeed());

		mapMove[Enum::MoveDecide::MAINTAIN_SPEED] = Point;
		SUM += Point;
	}

	{
		INT TendencyPoint = character.DefenseTendency() + character.Calm() + character.Concentration();

		INT Point = TendencyPoint + (INT)(TendencyPoint * moveDecide.MaintainRange());

		mapMove[Enum::MoveDecide::MAINTAIN_RANGE] = Point;
		SUM += Point;
	}

	INT n = rand() % SUM;
	for each(auto& it in mapMove)
	{
		Enum::MoveDecide::Type val = it.first;
		INT score = it.second;

		if( n < score)
		{
			return val;
		}
		n -= score;
	}

	LOG_ERROR(_T("Coding error. check sum & mapMove"));
	return Enum::MoveDecide::NONE;
}

SHARED_ACTION Decide::SelectAction(WEAK_CARD card)
{
	SHARED_ACTION action(new Action);
	action->SetBattle(m_Battle);

	Enum::Targeting::Type targetingType = Enum::Targeting::NONE;
	WEAK_CARD target = SelectTarget(card, targetingType);

	action->Set(this, card, target, MoveDecide(card), targetingType);
	return action;
}

} // namespace NW