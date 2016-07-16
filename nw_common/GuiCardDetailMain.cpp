#include "stdafx.h"
#include "GuiCardDetailMain.h"

#include "NWCard.h"

namespace NW
{

GuiCardDetailMain::GuiCardDetailMain()
{
}

GuiCardDetailMain::~GuiCardDetailMain()
{
}

void GuiCardDetailMain::OnDraw()
{
	if( m_Card.get() == NULL )
		return;

	{
		std::wstringstream stream;
		stream << m_Card->Name() << _T(" ")
			<< _T("LV:") << m_Card->GetLevel();
		DrawString(stream.str(), m_position + light::POSITION_INT(25, 25), light::RECT_INT(0, 0, 240, 40), 20, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::CENTER);
	}

	{
		m_sprite.DrawSprite(0, m_position + light::POSITION_INT(20, 50), 0);
	}

	{
		std::wstringstream stream;
		stream << _T("Str:") << m_Card->Str() << _T("\n")
			<< _T("Dex:") << m_Card->Dex() << _T("\n")
			<< _T("Int:") << m_Card->Int() << _T("\n")
			<< _T("Con:") << m_Card->Con() << _T("\n")
			<< _T("Wis:") << m_Card->Wis();

		DrawString(stream.str(), m_position + light::POSITION_INT(25, 250), light::RECT_INT(0, 0, 240, 100), 20, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::LEFT);
	}
}

void GuiCardDetailMain::SetCard(WEAK_CARD Card)
{
	__super::SetCard(Card);

	if(Card.get())
	{
		m_sprite.Load(m_direct_x, _T(".\\Image\\Template_Main.spr"), Card->Thumbnail());
	}
}

} //namespace NW
