#include "stdafx.h"
#include "GuiButtonPosition.h"

#include "NWCard.h"
#include "NWItem.h"

namespace NW
{

GuiButtonPosition::GuiButtonPosition()
{
}

GuiButtonPosition::~GuiButtonPosition()
{
}

bool GuiButtonPosition::Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_CARD card, const std::wstring& file_name, const std::wstring& strTextureName, light::POSITION_INT Pos, Gui::Callback callback, const TCHAR* szClickSound /* = NULL */, const TCHAR* szOverSound /* = NULL */)
{
	m_Card = card;
	Setting(pDirectX, callback, Pos, szClickSound, szOverSound);
	Property(PROPERTY::SHOW_ON_MOUSEOVER);
	Property(PROPERTY::MOVABLE_PLACEHOLDER);
	return Load(file_name, strTextureName);
}

void GuiButtonPosition::OnDraw()
{
	if( m_sprite.isLoad() == false)
		return;

	if( m_Card.get() == NULL )
		return;

	if(m_gui_state == light::view::GUI_STATE::MOUSE_DRAG)
	{
		Draw(GetPosition(), 128.0f);

		light::POSITION_INT Position = m_mouse_position;
		ToCenter(Position);

		Draw(Position, 255.0f);
	}
	else
	{
		Draw(GetPosition(), light::view::ALPHA_USE_ORIGINAL);
	}
}

void GuiButtonPosition::Draw(const light::POSITION_INT& Position, const float Alpha)
{
	DrawSprite( 0, Position, NowFrame(), false, 0.0f, Alpha );
	DrawString(Position, GetRect(), m_align);

	if(m_Card->Locate() != Enum::Locate::DECK)
	{
		DrawSprite( 0, Position, NowFrame(), false, 0.0f);

		std::wstringstream stream;
		stream << m_Card->SlotNo() + 1 << _T("¹ø ") << m_Card->Name();
		DrawString( stream.str(), GetPosition() + light::POSITION_INT(0, GetRect().Height() / 2), GetRect(), 15, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::CENTER);
	}
}

void GuiButtonPosition::AppenderProcess()
{
	__super::AppenderProcess();
	if( m_gui_state == light::view::GUI_STATE::MOUSE_OVER)
	{
		// blah ?
	}
}

WEAK_CARD GuiButtonPosition::GetCard() const
{
	return m_Card;
}

} //namespace NW
