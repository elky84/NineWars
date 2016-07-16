#include "stdafx.h"
#include "NWTurn.h"

#include "NWCard.h"
#include "NWAction.h"
#include "NWDecide.h"

#include "NWSquad.h"

#include "NWFormula.h"

#include "NWBattle.h"
#include "NWProjectTile.h"

namespace NW
{

Turn::Turn()
    : m_Decide(new Decide)
{

}

Turn::~Turn()
{

}

void Turn::SetBattle(WEAK_BATTLE battle)
{
	m_Battle = battle;
	m_Decide->SetBattle(battle);
}

bool Turn::DecideTurn()
{
	VECTOR_SQUAD& vectorSquad = m_Battle->VectorSquad();

	for each(auto& squad in vectorSquad)
	{
		WEAK_SQUAD weak_squad = squad;
		WEAK_SQUAD RivalSquad = weak_squad == vectorSquad[TEAM::RED] ? vectorSquad[TEAM::RED] : vectorSquad[TEAM::BLUE];
		for each(auto& val in weak_squad->MapCard())
		{
			WEAK_CARD card = val.second;
			if( card->GetAction().get() ||
				card->isDead() )
				continue;

			card->DecreaseDelay();
			if(	card->isDelay() )
				continue;

			SHARED_ACTION action = m_Decide->SelectAction(card);
			m_vector_Action.push_back(action);
		}
	}

	return !m_vector_Action.empty();
}

bool Turn::ActionTurn()
{
	for(std::vector<SHARED_ACTION>::iterator it = m_vector_Action.begin(); it != m_vector_Action.end();)
	{
		WEAK_ACTION action = *it;
		action->GetCard()->DecreaseDelay();
		if( false == action->GetCard()->isDelay() &&
			false == action->Update() )
		{
			it = m_vector_Action.erase(it);
			continue;;
		}

		++it;
	}
	return true;
}

} // namespace NW