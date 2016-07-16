#pragma once

#include "NWTypeDefinition.h"

#include <map>

namespace NW
{

class Squad
{
public:
	typedef std::map<CARD_INDEX, WEAK_CARD> MAP_CARD;

public:
	Squad();
	~Squad();

	void AddCard(const WEAK_CARD& card);

	void ClearCards();

	bool isExist(const WEAK_CARD& card);

	bool isAllDie();

	void Die(WEAK_CARD card);

	MAP_CARD& MapCard()
	{
		return m_map_Card;
	}

	MAP_CARD& MapAliveCard()
	{
		return m_map_AliveCard;
	}

private:
	MAP_CARD m_map_Card;

	MAP_CARD m_map_AliveCard;
};

} // namespace NW