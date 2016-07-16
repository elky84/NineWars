#include "stdafx.h"
#include "NWEffect.h"

#include "NWCard.h"

namespace NW
{

Effect::Effect()
	: m_ValidTurn(0)
	, m_Info(false, Particle::NONE)
{

}

Effect::~Effect()
{

}

bool Effect::Update()
{
	return --m_ValidTurn <= 0;
}

void Effect::Set(WEAK_CARD card, AttackMethod::Type attackMethod, WEAK_BATTLE battle, AttackInformation& information, const light::POSITION_FLOAT& pos)
{
	m_Card = card;
	m_AttackMethod = attackMethod;
	m_position = pos;

	if(m_AttackMethod == AttackMethod::NORMAL)
	{
		m_ValidTurn = 10;
		m_Info = Particle::Information(false, Particle::TEXT, m_AttackInformation.Damage);

		m_Card->PlayDamage();
	}
	else
	{
		m_ValidTurn = m_Card->VectorSkill()[m_AttackMethod].Info()->HoldTime();
		m_Info = Particle::Information(false, Particle::AURA, m_AttackInformation.Damage); // 데미지가 아닌 효과 단위로 수정해야 될듯?
	}

	m_AttackInformation = information;
	SetBattle(battle);
}


} // namespace NW