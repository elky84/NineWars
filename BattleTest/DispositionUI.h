#pragma once

#include "NWDeck.h"

#include "GuiPlaceholderCard.h"
#include "GuiPlaceholderPosition.h"

#include "GuiButtonCard.h"
#include "GuiButtonPosition.h"

#include "GuiImage.h"

#include "Sprite2D.h"

namespace NW
{

class DispositionUI
{
protected:
	struct GRAPH_ICON
	{
		enum Type
		{
			NONE = -1,
			LOW = 0,
			MID,
			HIGH,
			MAX,
		};
	};

public:
	DispositionUI();
	virtual ~DispositionUI();

protected:
	void Show(light::weak_raw_ptr<light::view::DirectX> pDirectX, Deck::card_list& list, const light::POSITION_INT& Adjust = light::POSITION_INT(0, 0));

	virtual bool OnDropSquadCard(SLOT_NO n);

	virtual bool OnDropSquadCardImpl(SLOT_NO n) = 0;

protected:
	void CalcGraph();

	void DrawGraph(const light::POSITION_INT& Adjust);

private:
	int RelationPoint(light::weak_raw_ptr<GuiButtonCard> pCard, light::weak_raw_ptr<GuiButtonCard> pTarget);

protected:
	GuiPlaceholderCard m_squad_holder[MAX_SQUAD_CARD];

	std::vector<GuiButtonCard> m_squad_cards;

	std::vector<GuiPlaceholderPosition> m_position_holder;

	GuiButtonPosition m_position_card[MAX_SQUAD_CARD];

	light::view::GuiImage m_BGGraph;

	light::view::GuiImage m_BGDisposition;

	light::view::Sprite2D m_GraphIcon;

	std::vector<INT> m_RelationPoint;
};

} // namespace NW