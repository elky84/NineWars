#include "stdafx.h"
#include "NWProjectTile.h"

#include "NWCard.h"

#include "NWEffect.h"
#include "NWBattle.h"
#include "NWFormula.h"

namespace NW
{

ProjectTile::ProjectTile()
	: m_AttackMethod(AttackMethod::NONE)
	, m_Info(Particle::Information(false, Particle::NONE))
{

}

ProjectTile::~ProjectTile()
{

}

bool ProjectTile::Update()
{
	if( Info().m_Movable == false)
	{
		if( false == m_Animation.NowPlaying() )
		{
			return Attack();
		}
		else
		{
			return false;
		}
	}

	return Move();
}

void ProjectTile::Set(WEAK_CARD card, WEAK_CARD target, WEAK_BATTLE battle, AttackMethod::Type attackMethod)
{
	m_Card = card;
	m_Target = target;

	light::POSITION_FLOAT TargetPos = m_Target->GetPosition() - m_Card->GetPosition();
	float Gap = sqrt((TargetPos.X() * TargetPos.X()) + (TargetPos.Y() * TargetPos.Y()));
	m_Direction.x = TargetPos.X() / Gap;
	m_Direction.y = TargetPos.Y() / Gap;

	if( light::LookAtToDegree(m_Direction.x, m_Direction.y) < 180.0f)
	{
		m_position = m_Card->GetPosition() - light::POSITION_FLOAT(CHARACTER_SIZE / 4.0f, 0.0f); // 왼쪽 보는거임
	}
	else
	{
		m_position = m_Card->GetPosition() + light::POSITION_FLOAT(CHARACTER_SIZE / 4.0f, 0.0f); // 오른쪽 보는거임
	}

	SetBattle(battle);

	m_AttackMethod = attackMethod;

	{
		bool Movable = false;
		switch( Particle::TYPE(m_Card->Class()) )
		{
		case Particle::WARRIOR:
		case Particle::ASSASSIN:
		case Particle::KNIGHT:
		case Particle::RIDER:
			Movable = false;
			break;
		case Particle::HEALER:
		case Particle::MAGICIAN:
		case Particle::BOW:
			Movable = true;
			break;
		case Particle::SKILL:
			Movable = 1 < m_Card->VectorSkill()[m_AttackMethod].Info()->Range() ? true : false;
			break;
		default:
			Movable = false;
			break;
		}

		m_Info = Particle::Information(Movable, Particle::TYPE(m_Card->Class()));
	}

	if(m_AttackMethod == AttackMethod::NORMAL)
	{
		auto& mapClassEffect = light::excel::Loader::Instance()->find<ExcelData::ClassEffectData>()->Map();

		if( m_Info.m_Movable == true )
			m_Animation.Load(m_Card->DirectXPtr(), mapClassEffect[Info().m_Type].Image());

		m_Card->PlayAttack();
	}
	else
	{
		m_Animation.Load(m_Card->DirectXPtr(), m_Card->VectorSkill()[m_AttackMethod].Info()->EffectFile());
	}
}

bool ProjectTile::Attack()
{
	AttackInformation information;
	if( Formula::DAMAGE_TYPE(m_Card->Class()) == DAMAGE::AD )
	{
		float fDamage = std::max(1.0f, Formula::AD_DAMAGE( m_Card->Class()) + (rand() % m_Card->Damage() + 1));
		information = m_Target->Damage(DAMAGE::AD, fDamage);
	}
	else
	{
		float fDamage = std::max(1.0f, Formula::AP_DAMAGE( m_Card->Class()) + (rand() % m_Card->Damage() + 1));
		information = m_Target->Damage(DAMAGE::AP, fDamage);
	}

    Effect* effect = new Effect;
	effect->Set(m_Card, m_AttackMethod, m_Battle, information, GetPosition());

	m_Battle->Add(effect);
	return true;
}

bool ProjectTile::Move()
{
	light::POSITION_FLOAT TargetPos = m_Target->GetPosition() - GetPosition();
	if( m_Target->isDead() )
		return true;

	float Gap = sqrt((TargetPos.X() * TargetPos.X()) + (TargetPos.Y() * TargetPos.Y()));
	if( fabs(Gap) < 10.0f ) // 사거리 내에 있으면 공격 시키자.
	{
		return Attack();
	}


	GetPosition().Force(std::min(5.0f, Gap), m_Target->GetPosition());

	m_Direction.x = TargetPos.X() / Gap;
	m_Direction.y = TargetPos.Y() / Gap;
	return false;
}

} // namespace NW