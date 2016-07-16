#include "stdafx.h"
#include "NWSquad.h"

#include "NWCard.h"

namespace NW
{

Squad::Squad()
{

}

Squad::~Squad()
{

}

void Squad::AddCard(const WEAK_CARD& card)
{
	card->SetSquad(this);
	m_map_Card.insert(MAP_CARD::value_type(card->GetIndex(), card));
	m_map_AliveCard.insert(MAP_CARD::value_type(card->GetIndex(), card));
}

void Squad::ClearCards()
{
	m_map_Card.clear();
	m_map_AliveCard.clear();
}

bool Squad::isExist(const WEAK_CARD& card)
{
	return m_map_Card.find(card->GetIndex()) != m_map_Card.end();
}

void Squad::Die(WEAK_CARD card)
{
	m_map_AliveCard.erase(card->GetIndex());
}

bool Squad::isAllDie()
{
	return m_map_AliveCard.empty();
}

} // namespace NW