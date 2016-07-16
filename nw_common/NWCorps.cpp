#include "stdafx.h"
#include "NWCorps.h"

#include "NWSquad.h"
#include "NWCard.h"

#include <algorithm>

namespace NW
{

Corps::Corps()
{

}

Corps::~Corps()
{

}

void Corps::AddCard(const WEAK_CARD& card)
{
	m_vector_Card.push_back(card);
}

bool Corps::isExist(const WEAK_CARD& card)
{
	for each(WEAK_CARD check in m_vector_Card)
	{
		if(check->GetCharacter()->Index() == card->GetCharacter()->Index())
		{
			return true;
		}
	}
	return false;
}

} // namespace NW