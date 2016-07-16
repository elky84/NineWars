#include "stdafx.h"
#include "NWBattle.h"

#include "NWSquad.h"

#include "NWTurn.h"
#include "NWCard.h"
#include "NWAction.h"
#include "NWDecide.h"

#include "NWProjectTile.h"
#include "NWEffect.h"
#include "NWSquad.h"

namespace NW
{

Battle::Battle()
    : m_Turn(new Turn)
    , m_vector_Squad(new VECTOR_SQUAD)
{
	m_Turn->SetBattle(this);
}

Battle::~Battle()
{

}

bool Battle::isGameEnd()
{
	for each( WEAK_SQUAD squad in *m_vector_Squad.get() )
	{
		if( true == squad->isAllDie() )
		{
			return true;
		}
	}
	return false;
}

void Battle::update_turn()
{
	for(LIST_PARTICLE::iterator it = m_list_Particle.begin(); it != m_list_Particle.end();)
	{
		WEAK_PARTICLE particle = *it;
		if(particle->Update())
		{
			it = m_list_Particle.erase(it);
			continue;
		}

		++it;
	}

	m_Turn->DecideTurn();

	m_Turn->ActionTurn();
}

void Battle::Add(const WEAK_SQUAD squad, TEAM::type team)
{
	m_vector_Squad->push_back(squad);
}

void Battle::Add(ProjectTile* projecttile)
{
	m_list_Particle.push_back(UNIQUE_PARTICLE(projecttile));
}

void Battle::Add(Effect* effect)
{
	m_list_Particle.push_back(UNIQUE_PARTICLE(effect));
}

} // namespace NW