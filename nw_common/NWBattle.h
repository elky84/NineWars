#pragma once

#include "NWTypeDefinition.h"

#include <list>

namespace NW
{

class Battle
{
public:
	static const int MAX_TEAM = 2;

public:
	typedef std::list<UNIQUE_PARTICLE> LIST_PARTICLE;
public:
	Battle();
	~Battle();

public:
	void update_turn();

	void Add(const WEAK_SQUAD squad, TEAM::type team);

	void Add(ProjectTile* projecttile);

	void Add(Effect* effect);

	LIST_PARTICLE& ListParticle()
	{
		return m_list_Particle;
	}

	VECTOR_SQUAD& VectorSquad()
	{
		return *m_vector_Squad.get();
	}

	bool isGameEnd();

private:
	LIST_PARTICLE m_list_Particle;

	UNIQUE_TURN m_Turn;

	UNIQUE_VECTOR_SQUAD m_vector_Squad;
};

} // namespace NW