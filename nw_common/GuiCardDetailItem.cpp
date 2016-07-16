#include "stdafx.h"
#include "GuiCardDetailItem.h"

#include "NWInventory.h"
#include "NWPlayer.h"
#include "NWCard.h"

#include "UIConstant.h"

#include <boost/bind.hpp>

namespace NW
{

GuiCardDetailItem::GuiCardDetailItem()
{
}

GuiCardDetailItem::~GuiCardDetailItem()
{
}

bool GuiCardDetailItem::Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, light::POSITION_INT Pos)
{
	m_direct_x = pDirectX;
	m_position = Pos;
	m_EquipSlot.resize( light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_WIDTH") * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_HEIGHT"));
	m_EquipItems.resize(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_WIDTH") * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_HEIGHT"));
	return true;
}

void GuiCardDetailItem::Set()
{
	__super::Set();
	
	for(size_t n = 0; n < m_EquipSlot.size(); ++n)
	{
		m_EquipSlot[n].Set();
	}
}

void GuiCardDetailItem::Release()
{
	__super::Release();

	for(size_t n = 0; n < m_EquipSlot.size(); ++n)
	{
		m_EquipSlot[n].Release();
	}
}

void GuiCardDetailItem::SetCard(WEAK_CARD Card)
{
	for(size_t n = 0; n < m_EquipSlot.size(); ++n)
	{
		m_EquipSlot[n].Link(NULL);
	}

	__super::SetCard(Card);
	if(Card.get() == NULL)
	{
		return;
	}

	Inventory::item_list list;
	m_Player->get_inventory()->find(Card->GetIndex(), list);

	for each(auto val in list)
	{
		m_EquipItems[val->SlotNo()].Create(m_direct_x, val, _T(".\\Item\\template.spr"), val->Info()->Icon(), m_EquipSlot[val->SlotNo()].GetPosition());
		m_EquipItems[val->SlotNo()].Property(light::view::Gui::PROPERTY::MOVABLE_PLACEHOLDER);
		m_EquipSlot[val->SlotNo()].Link(&m_EquipItems[val->SlotNo()]);
	}
}

std::vector<GuiPlaceholderItem>& GuiCardDetailItem::EquipSlot()
{
	return m_EquipSlot;
}

std::vector<GuiButtonItem>& GuiCardDetailItem::EquipItem()
{
	return m_EquipItems;
}


} //namespace NW
