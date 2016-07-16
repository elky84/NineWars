#include "stdafx.h"
#include "NWPlayer.h"

#include "MetaData.h"
#include "NWCard.h"
#include "NWSquad.h"

#include "NWInventory.h"
#include "NWDeck.h"

#include <algorithm>

namespace NW
{

Player::Player()
    : m_Inventory(new Inventory)
    , m_Deck(new Deck)
    , m_Squad(new Squad)
{

}

Player::~Player()
{

}

WEAK_INVENTORY Player::get_inventory()
{
	return m_Inventory;
}

WEAK_DECK Player::get_deck()
{
	return m_Deck;
}

} // namespace NW