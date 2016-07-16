#pragma once

#include "GuiPlaceholderCard.h"
#include "GuiButtonCard.h"

#include "NWDeck.h"

namespace NW
{

class CardUI
{
public:
	CardUI();
	virtual ~CardUI();

protected:
	void Show(light::weak_raw_ptr<light::view::DirectX> pDirectX, Deck::card_list& list);

	virtual bool OnDropCard(SLOT_NO n);

	virtual bool OnDropCardImpl(SLOT_NO n) = 0;

	virtual bool OnClickCard(GuiButtonCard* Card);

	virtual bool OnClickCardImpl(GuiButtonCard* Card) = 0;

protected:
	std::vector<GuiPlaceholderCard> m_CardHolder;

	std::vector<GuiButtonCard> m_Cards;
};

} // namespace NW