#pragma once

#include "NWTypeDefinition.h"
#include <vector>

namespace NW
{

class Player
{
public:
	Player();
	~Player();

	WEAK_SQUAD get_squad()
	{
		return m_Squad;
	}

public:

	void Name(const std::wstring& str)
	{
		m_Name = str;
	}

	const std::wstring& Name() const
	{
		return m_Name;
	}

	WEAK_INVENTORY get_inventory();

	WEAK_DECK get_deck();

private:
	std::wstring m_Name;

	UNIQUE_SQUAD m_Squad;

	UNIQUE_INVENTORY m_Inventory;

	UNIQUE_DECK m_Deck;
};

} // namespace NW