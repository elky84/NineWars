#pragma once

#include "NWTypeDefinition.h"

#include <vector>

namespace NW
{

class Turn
{
public:
	Turn();
	~Turn();

	bool DecideTurn();
	bool ActionTurn();

	void SetBattle(WEAK_BATTLE battle);

private:
	UNIQUE_DECIDE m_Decide;

	WEAK_BATTLE m_Battle;

	std::vector<WEAK_CARD> m_vector_Card;

	std::vector<SHARED_ACTION> m_vector_Action;
};

} // namespace NW