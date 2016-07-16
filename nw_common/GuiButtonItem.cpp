#include "stdafx.h"
#include "GuiButtonItem.h"

#include "NWCard.h"
#include "NWItem.h"

namespace NW
{

GuiButtonItem::GuiButtonItem()
{
}

GuiButtonItem::~GuiButtonItem()
{
}

bool GuiButtonItem::Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_ITEM item, const std::wstring& file_name, const std::wstring& strTextureName, light::POSITION_INT Pos, Gui::Callback callback, const TCHAR* szClickSound /* = NULL */, const TCHAR* szOverSound /* = NULL */)
{
	m_Item = item;
	Setting(pDirectX, callback, Pos, szClickSound, szOverSound);
	Property(PROPERTY::SHOW_ON_MOUSEOVER);
	Property(PROPERTY::MOVABLE_PLACEHOLDER);
	return Load(file_name, strTextureName);
}

void GuiButtonItem::AppenderProcess()
{
	__super::AppenderProcess();
	if( m_gui_state == light::view::GUI_STATE::MOUSE_OVER)
	{
		if(m_append_gui.get())
		{
			std::wstringstream stream;
			//stream << m_Card->Name() << _T("\n")
			//	<< _T("Å¬·¡½º:") << m_Card->Class() << _T("\n")
			//	<< m_Card->EquipEffect() << _T("\n");

			//for each(WEAK_ITEM item in m_Card->VectorItem())
			//{
			//	stream << item->Name() << _T("\n");
			//}

			m_append_gui->Message(stream.str(), 12, D3DCOLOR_RGBA(255, 255, 255, 255));
		}
	}
}

WEAK_ITEM GuiButtonItem::GetItem() const
{
	return m_Item;
}

} //namespace NW
