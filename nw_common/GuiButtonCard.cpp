#include "stdafx.h"
#include "GuiButtonCard.h"

#include "NWCard.h"
#include "NWItem.h"

namespace NW
{

GuiButtonCard::GuiButtonCard()
{
}

GuiButtonCard::~GuiButtonCard()
{
}

bool GuiButtonCard::Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_CARD card, const std::wstring& file_name, light::POSITION_INT Pos, Gui::Callback callback, const TCHAR* szClickSound /* = NULL */, const TCHAR* szOverSound /* = NULL */)
{
	Setting(pDirectX, callback, Pos, szClickSound, szOverSound); // 해당 메소드안의 SetPosition에서 상대 좌표 처리해줌.

	Property(PROPERTY::SHOW_ON_MOUSEOVER);
	Property(PROPERTY::MOVABLE_PLACEHOLDER);

	SetCard(card);
	return Load(file_name);
}

void GuiButtonCard::AppenderProcess()
{
	__super::AppenderProcess();
	if( m_gui_state == light::view::GUI_STATE::MOUSE_OVER)
	{
		if(m_append_gui.get())
		{
			std::wstringstream stream;
			stream << m_Card->Name() << _T("\n")
				<< _T("클래스:") << m_Card->Class() << _T("\n")
				<< m_Card->EquipEffect() << _T("\n");

			m_append_gui->Message(stream.str(), 12, D3DCOLOR_RGBA(255, 255, 255, 255));
		}
	}
}

void GuiButtonCard::Set()
{
	__super::Set();
}

WEAK_CARD GuiButtonCard::GetCard() const
{
	return m_Card;
}

void GuiButtonCard::SetCard(WEAK_CARD card)
{
	m_Card = card;
	if(m_Card.get())
	{
		m_Character.Load(m_direct_x, _T(".\\Image\\template_mini.spr"), m_Card->Thumbnail() );

		auto& ClassInfo = light::excel::Loader::Instance()->find<ExcelData::ClassData>()->Map()[card->Class()];
		m_Class.Load(m_direct_x, _T(".\\Gui\\CardMini\\Class.spr"), _T("..\\Class\\") + ClassInfo.Image() );
		m_Group.Load(m_direct_x, _T(".\\Gui\\CardMini\\Class.spr"), _T("..\\Class\\") + ClassInfo.Image() );
		m_Star.Load(m_direct_x, _T(".\\Gui\\CardMini\\Star.spr") );
		m_Name.Load(m_direct_x, _T(".\\Gui\\CardMini\\Name.spr") );
	}
}

void GuiButtonCard::OnDraw()
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


void GuiButtonCard::Draw(const light::POSITION_INT& Position, const float Alpha)
{
	DrawSprite( 0, Position, NowFrame(), false, 0.0f, Alpha );
	DrawString(Position, GetRect(), m_align);

	m_Character.DrawSprite(0, Position + light::POSITION_INT(2, 2), NowFrame(), false, 0.0f, Alpha);

	light::POSITION_INT StarPosition = Position + light::POSITION_INT(m_Class.GetRect(0).Width() + 2, 2);
	for( int n = 0; n < m_Card->Cost(); ++n)	
	{
		m_Star.DrawSprite(0, StarPosition, NowFrame(), false, 0.0f, Alpha);
		StarPosition.X(StarPosition.X() + m_Star.GetRect(0).Width() + 2);
	}

	m_Class.DrawSprite(0, Position, NowFrame(), false, 0.0f, Alpha);
	m_Group.DrawSprite(0, Position + light::POSITION_INT(0, 76), NowFrame(), false, 0.0f, Alpha);
	m_Name.DrawSprite(0, Position + light::POSITION_INT(4, m_Character.GetRect(0).Width()), NowFrame(), false, 0.0f, Alpha);

	std::wstringstream stream;
	stream << m_Card->Name();

	DrawString(stream.str(), Position + light::POSITION_INT(m_Group.GetRect(0).Width() + 4, m_Character.GetRect(0).Width()), m_Name.GetRect(0) - light::RECT_INT(0, 0, m_Group.GetRect(0).Width(), 0), 10, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::LEFT);

	if(m_Card->Locate() != Enum::Locate::DECK)
	{
		DrawSprite( 1, Position, NowFrame(), false, 0.0f);

		std::wstringstream stream;
		stream << m_Card->SlotNo() + 1 << _T("번 배치");
		DrawString( stream.str(), GetPosition() + light::POSITION_INT(0, GetRect().Height() / 2), GetRect(), 15, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::CENTER);
	}
}

} //namespace NW
