#include "stdafx.h"
#include "GuiCard.h"

#include "NWCard.h"

namespace NW
{

GuiCard::GuiCard()
{
}

GuiCard::~GuiCard()
{
}

bool GuiCard::Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, light::POSITION_INT Pos)
{
	m_direct_x = pDirectX;
	m_position = Pos;
	return true;
}

void GuiCard::SetPlayer(WEAK_PLAYER Player)
{
	m_Player = Player;
}

WEAK_CARD GuiCard::GetCard() const
{
	return m_Card;
}

void GuiCard::SetCard(WEAK_CARD Card)
{
	m_Card = Card;
}

void GuiCard::OnLogic()
{

}

} //namespace NW
