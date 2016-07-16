#include "stdafx.h"
#include "CharacterSettingMode.h"

#include "BattleManager.h"

#include "NWBattle.h"
#include "NWPlayer.h"
#include "NWSquad.h"
#include "NWCard.h"
#include "NWCardFactory.h"
#include "NWDeck.h"
#include "NWItem.h"
#include "NWItemFactory.h"
#include "NWInventory.h"

#include "DirectX.h"

#include "UIConstant.h"
#include "ConfigConstant.h"

namespace NW
{

CharacterSettingMode::CharacterSettingMode(light::weak_raw_ptr<light::view::DirectX> pDirectX)
: SetupUI(ModeID::CHARACTER_SETTING, pDirectX)
, CardUI()
{
	
}

CharacterSettingMode::~CharacterSettingMode()
{

}

void CharacterSettingMode::Begin()
{
	m_BG.Load(m_direct_x, _T(".\\Gui\\CharacterSetting\\BG.spr"));
	m_BGInventory.Load(m_direct_x, _T(".\\Gui\\CharacterSetting\\BGInventory.spr"));

	m_ItemHolder.resize( light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_WIDTH") * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_HEIGHT") );

	m_CardDetail[Direction::LEFT_NONE].Create(m_direct_x, NULL, _T(".\\Gui\\Card\\BigTemplate.spr"), _T("BigBG.png"), light::POSITION_INT(666, 58));
	m_CardDetail[Direction::LEFT_FRONT].Create(m_direct_x, &m_DetailMain, _T(".\\Gui\\Card\\BigTemplate.spr"), _T("LeftFront.png"), light::POSITION_INT(666, 58), boost::bind(&CharacterSettingMode::OnClickCardDetail, this, Direction::LEFT_FRONT));
	m_CardDetail[Direction::LEFT_BACK].Create(m_direct_x, &m_DetailBG, _T(".\\Gui\\Card\\BigTemplate.spr"), _T("LeftBack.png"), light::POSITION_INT(666, 58), boost::bind(&CharacterSettingMode::OnClickCardDetail, this, Direction::LEFT_BACK));

	m_CardDetail[Direction::RIGHT_NONE].Create(m_direct_x, NULL, _T(".\\Gui\\Card\\BigTemplate.spr"), _T("BigBG.png"), light::POSITION_INT(964, 58));
	m_CardDetail[Direction::RIGHT_FRONT].Create(m_direct_x, &m_DetailStatus, _T(".\\Gui\\Card\\BigTemplate.spr"), _T("RightFront.png"), light::POSITION_INT(964, 58), boost::bind(&CharacterSettingMode::OnClickCardDetail, this, Direction::RIGHT_BACK));
	m_CardDetail[Direction::RIGHT_BACK].Create(m_direct_x, &m_DetailItem, _T(".\\Gui\\Card\\BigTemplate.spr"), _T("RightBack.png"), light::POSITION_INT(964, 58), boost::bind(&CharacterSettingMode::OnClickCardDetail, this, Direction::RIGHT_FRONT));

	{
		std::vector<GuiPlaceholderItem>& EquipSlot = m_DetailItem.EquipSlot();
		light::POSITION_INT Position(m_CardDetail[Direction::RIGHT_BACK].GetPosition().X() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_START_X"), m_CardDetail[Direction::RIGHT_BACK].GetPosition().Y() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_START_Y") );
		for(int y = 0; y < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_HEIGHT"); ++y)
		{
			for(int x = 0; x <  light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_WIDTH"); ++x)
			{
				EquipSlot[y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_WIDTH") + x].Create(m_direct_x, _T(".\\Gui\\CharacterSetting\\ItemSlot.spr"), Position, boost::bind(&CharacterSettingMode::OnDropEquipItem, this, x, y));
				Position.X(Position.X() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_X_INTERVAL"));
			}

			Position.X( m_CardDetail[Direction::RIGHT_BACK].GetPosition().X() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_START_X"));
			Position.Y( Position.Y() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_Y_INTERVAL"));
		}
	}

	{
		light::POSITION_INT Position(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_START_X"), light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_START_Y"));
		for(int y = 0; y < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_HEIGHT"); ++y)
		{
			for(int x = 0; x <  light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_WIDTH"); ++x)
			{
				m_ItemHolder[y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_WIDTH") + x].Create(m_direct_x, _T(".\\Gui\\CharacterSetting\\ItemSlot.spr"), Position, boost::bind(&CharacterSettingMode::OnDropItem, this, x, y));

				Position.X(Position.X() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_X_INTERVAL"));
			}

			Position.X(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_START_X"));
			Position.Y( Position.Y() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_Y_INTERVAL"));
		}
	}

	SetupUI::Show(m_direct_x);

	m_CardDetail[Direction::LEFT_NONE].Set();
	m_CardDetail[Direction::RIGHT_NONE].Set();

	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	{
		Deck::card_list list;
		RedPlayer->get_deck()->get_list(list);
		CardUI::Show(m_direct_x, list);
	}

	for each(auto& val in m_CardDetail)
	{
		val.SetPlayer(RedPlayer);
	}

	{
		m_Items.resize(m_ItemHolder.size());
		Inventory::item_list list;
		RedPlayer->get_inventory()->find(Enum::Storage::INVENTORY, list);

		for(size_t n = 0; n < m_ItemHolder.size(); ++n)
		{
			m_ItemHolder[n].Set();
		}

		for each(auto val in list)
		{
			m_Items[val->SlotNo()].Create(m_direct_x, val, _T(".\\Item\\template.spr"), val->Info()->Icon(), m_ItemHolder[val->SlotNo()].GetPosition());
			m_Items[val->SlotNo()].Property(light::view::Gui::PROPERTY::MOVABLE_PLACEHOLDER);
			m_Items[val->SlotNo()].Set();
			m_ItemHolder[val->SlotNo()].Link(&m_Items[val->SlotNo()]);
		}
	}

	if( true == light::INI::Loader::Instance()->find<ConfigConstant>()->get<bool>("TEST.SKIP_SETTING") )
	{
		Start();
		return;
	}
}

void CharacterSettingMode::End()
{
}

void CharacterSettingMode::Render()
{
	m_BG.DrawSprite(0, light::POSITION_INT(0, 0), 0);
	m_BGInventory.DrawSprite(0, light::POSITION_INT( light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_START_X") - 6, light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_START_Y") - 6), 0);
}

void CharacterSettingMode::RenderPostUI()
{
	
}

void CharacterSettingMode::Logic()
{
}

bool CharacterSettingMode::OnClickCardImpl(GuiButtonCard* Card)
{
	for each(auto& val in m_CardDetail)
	{
		val.Release();
		val.SetCard(Card->GetCard());
	}

	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	Inventory::item_list list;
	RedPlayer->get_inventory()->find(Enum::Storage::INVENTORY, list);

	for(size_t n = 0; n < m_ItemHolder.size(); ++n)
	{
		m_ItemHolder[n].Release();
		m_ItemHolder[n].Link(NULL);
		m_ItemHolder[n].Set();
	}

	for each(auto val in list)
	{
		m_Items[val->SlotNo()].Create(m_direct_x, val, _T(".\\Item\\template.spr"), val->Info()->Icon(), m_ItemHolder[val->SlotNo()].GetPosition());
		m_Items[val->SlotNo()].Property(light::view::Gui::PROPERTY::MOVABLE_PLACEHOLDER);
		m_Items[val->SlotNo()].Set();
		m_ItemHolder[val->SlotNo()].Link(&m_Items[val->SlotNo()]);
	}

	m_CardDetail[Direction::LEFT_FRONT].Set();
	m_CardDetail[Direction::RIGHT_FRONT].Set();
	return true;
}

bool CharacterSettingMode::OnDropCardImpl(SLOT_NO SlotNo)
{
	UNREFERENCED_PARAMETER(SlotNo);
	return true;
}

bool CharacterSettingMode::FlipCardDetail(Direction::Type direction)
{
	if(m_CardDetail[direction].isShow())
	{
		m_CardDetail[direction].Release();
	}
	else
	{
		m_CardDetail[direction].Set();
	}
	return true;
}

bool CharacterSettingMode::OnClickCardDetail(Direction::Type direction)
{
	if(direction == Direction::LEFT_BACK ||
		direction == Direction::LEFT_FRONT )
	{
		FlipCardDetail(Direction::LEFT_BACK);
		FlipCardDetail(Direction::LEFT_FRONT);
	}
	else if(direction == Direction::RIGHT_BACK ||
		direction == Direction::RIGHT_FRONT)
	{
		FlipCardDetail(Direction::RIGHT_FRONT);
		FlipCardDetail(Direction::RIGHT_BACK);
	}
	return true;
}

bool CharacterSettingMode::OnDropEquipItem(int x, int y)
{
	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	std::vector<GuiPlaceholderItem>& EquipSlot = m_DetailItem.EquipSlot();

	SLOT_NO SlotNo = y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("EQUIP.ITEM_WIDTH") + x;

	light::weak_raw_ptr<light::view::Gui> pAppendGui = EquipSlot[SlotNo].AppendPtr();

	GuiButtonItem* pItemButton = light::view::Gui::Find<GuiButtonItem>(pAppendGui, m_Items);
	GuiButtonItem* pEquipItemButton = light::view::Gui::Find<GuiButtonItem>(pAppendGui, m_DetailItem.EquipItem());
	if(pItemButton)
	{
		WEAK_ITEM pItem = RedPlayer->get_inventory()->find(Enum::Storage::INVENTORY, pItemButton->GetItem()->Index());
		if(pItem.get())
		{
			pItem->Storage(m_DetailItem.GetCard()->GetIndex(), Enum::Storage::EQUIP, SlotNo);
			RedPlayer->get_inventory()->update(pItem);
		}
	}
	else if(pEquipItemButton)
	{
		WEAK_ITEM pItem = RedPlayer->get_inventory()->find(m_DetailItem.GetCard()->GetIndex(), Enum::Storage::EQUIP, pEquipItemButton->GetItem()->Index());
		if(pItem.get())
		{
			pItem->Storage(m_DetailItem.GetCard()->GetIndex(), Enum::Storage::EQUIP, SlotNo);
			RedPlayer->get_inventory()->update(pItem);
		}
	}

	return true;
}

bool CharacterSettingMode::OnDropItem(int x, int y)
{
	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	SLOT_NO SlotNo = y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("ITEM.PLACEHOLDER_WIDTH") + x;

	light::weak_raw_ptr<light::view::Gui> pAppendGui = m_ItemHolder[SlotNo].AppendPtr();

	GuiButtonItem* pItemButton = light::view::Gui::Find<GuiButtonItem>(pAppendGui, m_Items);
	GuiButtonItem* pEquipItemButton = light::view::Gui::Find<GuiButtonItem>(pAppendGui, m_DetailItem.EquipItem());

	if(pItemButton)
	{
		WEAK_ITEM pItem = RedPlayer->get_inventory()->find(pItemButton->GetItem()->Index());
		if(pItem.get())
		{
			pItem->Storage(m_DetailItem.GetCard()->GetIndex(), Enum::Storage::INVENTORY, SlotNo);
			RedPlayer->get_inventory()->update(pItem);

		}
	}
	else if(pEquipItemButton)
	{
		WEAK_ITEM pItem = RedPlayer->get_inventory()->find(pEquipItemButton->GetItem()->Index());
		if(pItem.get())
		{
			pItem->Storage(m_DetailItem.GetCard()->GetIndex(), Enum::Storage::INVENTORY, SlotNo);
			RedPlayer->get_inventory()->update(pItem);
		}
	}
	return true;
}

void CharacterSettingMode::Save()
{
	WEAK_PLAYER Player = BattleManager::Instance()->GetPlayer(TEAM::RED);
	Player->get_squad()->ClearCards();

	{
		Deck::card_list list;
		Player->get_deck()->find(Enum::Locate::SQUAD, list);

		for each(auto& Card in list)
		{
			Player->get_squad()->AddCard(Card);
		}
	}
}

} // namespace NW