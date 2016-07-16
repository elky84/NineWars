#include "stdafx.h"
#include "CardUI.h"

#include "UIConstant.h"
#include "boost/bind.hpp"

namespace NW
{

CardUI::CardUI()
{
}

CardUI::~CardUI()
{

}

void CardUI::Show(light::weak_raw_ptr<light::view::DirectX> pDirectX, Deck::card_list& list)
{
	m_CardHolder.resize( light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_WIDTH") * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_HEIGHT") );

	{
		// 카드 GUI 세팅
		light::POSITION_INT Position( light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_START_X"),  light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_START_Y") );
		for(int y = 0; y <  light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_HEIGHT") ; ++y)
		{
			for(int x = 0; x <  light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_WIDTH") ; ++x)
			{
				m_CardHolder[y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_WIDTH") + x].Create(pDirectX, _T(".\\Gui\\Card\\Template.spr"), _T("BG.png"), Position, boost::bind(&CardUI::OnDropCard, this, y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_WIDTH") + x));
				Position.X(Position.X() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_X_INTERVAL"));
			}

			Position.X(  light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_START_X") );
			Position.Y( Position.Y() +  light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CARD.PLACEHOLDER_Y_INTERVAL") );
		}
	}


	m_Cards.resize(list.size());

	for(size_t n = 0; n < m_CardHolder.size(); ++n)
	{
		m_CardHolder[n].Set();
	}

	for( size_t n = 0; n < m_CardHolder.size(); ++n )
	{
		m_Cards[n].Create(pDirectX, list[n], _T(".\\Gui\\CardMini\\BG.spr"), m_CardHolder[n].GetPosition(), boost::bind(&CardUI::OnClickCard, this, &m_Cards[n]) );
		m_Cards[n].Set();

		m_CardHolder[n].Link(&m_Cards[n]);
	}
}

bool CardUI::OnDropCard(SLOT_NO n)
{
	return OnDropCardImpl(n);
}

bool CardUI::OnClickCard(GuiButtonCard* Card)
{
	return OnClickCardImpl(Card);
}

} // namespace NW