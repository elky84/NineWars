#pragma once

#include "NWTypeDefinition.h"
#include "NWParticle.h"

#include "Animation2D.h"

namespace NW
{

class ProjectTile : public Particle
{
public:
	ProjectTile();
	virtual ~ProjectTile();

public:
	void Set(WEAK_CARD card, WEAK_CARD target, WEAK_BATTLE battle, AttackMethod::Type attackMethod);

	virtual bool Update();

	virtual Particle::Information Info() const
	{
		return m_Info;
	}

private:
	bool Move();

	bool Attack();

private:
	WEAK_CARD m_Target;

	AttackMethod::Type m_AttackMethod;

	Particle::Information m_Info;
};

} // namespace NW