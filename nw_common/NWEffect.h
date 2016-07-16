#pragma once

#include "NWTypeDefinition.h"
#include "NWParticle.h"

namespace NW
{

class Effect : public Particle
{
public:
	Effect();
	virtual ~Effect();

public:
	void Set(WEAK_CARD card, AttackMethod::Type attackMethod, WEAK_BATTLE battle, AttackInformation& information, const light::POSITION_FLOAT& pos);

	virtual bool Update();

	virtual Particle::Information Info() const
	{
		return m_Info;
	}

private:
	int m_ValidTurn;

	AttackInformation m_AttackInformation;

	Particle::Information m_Info;

	AttackMethod::Type m_AttackMethod;
};

} // namespace NW