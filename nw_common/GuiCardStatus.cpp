#include "stdafx.h"
#include "GuiCardStatus.h"

#include "NWCard.h"
#include "NWItem.h"

namespace NW
{

GuiCardStatus::GuiCardStatus()
{
}

GuiCardStatus::~GuiCardStatus()
{
}


void GuiCardStatus::Set()
{
	__super::Set();
	for each(auto& val in m_Image)
		val.Set();

	m_HP.Set();
}

void GuiCardStatus::Release()
{
	__super::Release();
	for each(auto& val in m_Image)
		val.Release();

	m_HP.Release();
}

bool GuiCardStatus::Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_CARD card, const std::wstring& file_name, light::POSITION_INT Pos, light::view::Gui::Direction::Type direction)
{
	m_Card = card;
	m_direct_x = pDirectX;
	m_position = Pos;
	m_Direction = direction;

	Property(PROPERTY::SHOW_ON_MOUSEOVER);

	if(direction == light::view::Gui::Direction::RIGHT)
	{
		if( false == m_Image[IMAGE::CHARACTER].Create(pDirectX, _T(".\\Image\\template.spr"), card->Thumbnail(), Pos + light::POSITION_INT(2, 2)) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::CHARACTER_OUTLINE].Create(pDirectX, _T(".\\Gui\\Character\\SnapOutline.spr"), Pos) )
		{
			return false;
		}

		auto& ClassInfo = light::excel::Loader::Instance()->find<ExcelData::ClassData>()->Map()[card->Class()];
		if( false == m_Image[IMAGE::CLASS].Create(pDirectX, _T(".\\Gui\\Character\\Class.spr"), _T("..\\Class\\") + ClassInfo.Image(), Pos) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::SKILL_1].Create(pDirectX, _T(".\\Gui\\Character\\Slot.spr"), Pos + light::POSITION_INT(2 * 3 + 62 + 46, 2 + 13)) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::SKILL_2].Create(pDirectX, _T(".\\Gui\\Character\\Slot.spr"), Pos + light::POSITION_INT(2 * 3 + 62 + 19, 2 ) ) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::SKILL_3].Create(pDirectX, _T(".\\Gui\\Character\\Slot.spr"), Pos + light::POSITION_INT(2 * 3 + 62 + 19, 2 + 30) ) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::HP_OUTLINE].Create(pDirectX, _T(".\\Gui\\Character\\HPOutline.spr"), Pos + light::POSITION_INT(2 * 2 + 62, 0) ) )
		{
			return false;
		}

		if( false == m_HP.Create(pDirectX, _T(".\\Gui\\Character\\HP.spr"), Pos + light::POSITION_INT(2 * 2 + 62 + 3, 0), 100.0f, 2, light::view::Gui::Direction::UP) )
		{
			return false;
		}

		return Load(file_name);
	}
	else
	{
		if( false == m_Image[IMAGE::CHARACTER].Create(pDirectX, _T(".\\Image\\template.spr"), card->Thumbnail(), Pos + light::POSITION_INT(85 + 2, 2)) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::CHARACTER_OUTLINE].Create(pDirectX, _T(".\\Gui\\Character\\SnapOutline.spr"), Pos + light::POSITION_INT(85, 0)) )
		{
			return false;
		}

		auto& ClassInfo = light::excel::Loader::Instance()->find<ExcelData::ClassData>()->Map()[card->Class()];
		if( false == m_Image[IMAGE::CLASS].Create(pDirectX, _T(".\\Gui\\Character\\Class.spr"), _T("..\\Class\\") + ClassInfo.Image(), Pos + light::POSITION_INT(85, 0) ) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::SKILL_1].Create(pDirectX, _T(".\\Gui\\Character\\Slot.spr"), Pos + light::POSITION_INT(2 * 3, 2 + 13) ) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::SKILL_2].Create(pDirectX, _T(".\\Gui\\Character\\Slot.spr"), Pos + light::POSITION_INT(2 * 3 + 27, 2) ) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::SKILL_3].Create(pDirectX, _T(".\\Gui\\Character\\Slot.spr"), Pos + light::POSITION_INT(2 * 3 + 27, 2 + 30) ) )
		{
			return false;
		}

		if( false == m_Image[IMAGE::HP_OUTLINE].Create(pDirectX, _T(".\\Gui\\Character\\HPOutline.spr"), Pos + light::POSITION_INT(2 * 2 + 65, 0) ) )
		{
			return false;
		}

		if( false == m_HP.Create(pDirectX, _T(".\\Gui\\Character\\HP.spr"), Pos + light::POSITION_INT(2 * 2 + 65 + 3, 0), 100.0f, 2, light::view::Gui::Direction::UP) )
		{
			return false;
		}

		return Load(file_name);
	}
}

void GuiCardStatus::OnLogic()
{
	m_HP.SetProgress(1, 100.0f * (m_Card->GetHP() / m_Card->GetMaxHP()));
}


void GuiCardStatus::OnDraw()
{
	DrawSprite(0, GetPosition(), NowFrame(), m_Direction == light::view::Gui::Direction::RIGHT ? false : true);
	DrawString(GetPosition(), GetRect(), m_align);
}

void GuiCardStatus::AppenderProcess()
{
	__super::AppenderProcess();
	if( m_gui_state == light::view::GUI_STATE::MOUSE_OVER)
	{
		if(m_append_gui.get())
		{
			std::wstringstream stream;
			stream << m_Card->Name() << _T("\n")
				<< _T("Å¬·¡½º:") << m_Card->Class() << _T("\n")
				<< m_Card->EquipEffect() << _T("\n");

			//for each(WEAK_ITEM item in m_Card->VectorItem())
			//{
			//	stream << item->Name() << _T("\n");
			//}

			m_append_gui->Message(stream.str(), 12, D3DCOLOR_RGBA(255, 255, 255, 255));
		}
	}
}

WEAK_CARD GuiCardStatus::GetCard() const
{
	return m_Card;
}

light::view::GUI_STATE::Type GuiCardStatus::Check()
{
	__super::Check();
	m_frame = m_gui_state != light::view::GUI_STATE::NONE ? 1 : 0;
	return m_gui_state;
}


} //namespace NW