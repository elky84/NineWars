#include "stdafx.h"
#include "GuiButtonCardDetail.h"

#include "GuiCard.h"
#include "NWCard.h"

namespace NW
{

GuiButtonCardDetail::GuiButtonCardDetail()
{
}

GuiButtonCardDetail::~GuiButtonCardDetail()
{
}

bool GuiButtonCardDetail::Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, light::weak_raw_ptr<GuiCard> pGui, const std::wstring& file_name, const std::wstring& strTextureName, light::POSITION_INT Pos, Gui::Callback callback, const TCHAR* szClickSound /* = NULL */, const TCHAR* szOverSound /* = NULL */)
{
	m_GuiCard = pGui;

	if(m_GuiCard.get())
	{
		m_GuiCard->Create(pDirectX, Pos);
	}

	Setting(pDirectX, callback, Pos, szClickSound, szOverSound); 
	return Load(file_name, strTextureName);
}

WEAK_CARD GuiButtonCardDetail::GetCard() const
{
	return m_Card;
}

void GuiButtonCardDetail::SetPlayer(WEAK_PLAYER Player)
{
	m_Player = Player;
	if(m_GuiCard.get())
	{
		m_GuiCard->SetPlayer(Player);
	}
}

void GuiButtonCardDetail::SetCard(WEAK_CARD Card)
{
	m_Card = Card;
	if(m_GuiCard.get())
	{
		m_GuiCard->SetCard(m_Card);
	}
}

void GuiButtonCardDetail::Set()
{
	__super::Set();
	if(m_GuiCard.get())
	{
		m_GuiCard->Set();
	}
}

void GuiButtonCardDetail::Release()
{
	__super::Release();
	if(m_GuiCard.get())
	{
		m_GuiCard->Release();
	}
}

} //namespace NW
