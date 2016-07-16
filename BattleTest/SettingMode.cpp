#include "stdafx.h"
#include "SettingMode.h"

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
#include "PickConstant.h"

namespace NW
{

SettingMode::SettingMode(light::weak_raw_ptr<light::view::DirectX> pDirectX)
: light::view::Mode(ModeID::SETTING, pDirectX)
{
}

SettingMode::~SettingMode()
{

}

static const TCHAR* NAME[Battle::MAX_TEAM] = {_T("RED"), _T("BLUE")};

void AddToInventoryAndEquip(WEAK_PLAYER Player, WEAK_CARD Card, Item* item, SLOT_NO SlotNo)
{
	if( item )
	{
		item->Storage(Card->GetIndex(), Enum::Storage::EQUIP, SlotNo);
		Player->get_inventory()->insert(item);
	}
}

void SettingMode::Begin()
{
	for(int n = 0; n < Battle::MAX_TEAM; ++n)
	{
		Player* player = new Player();
        player->Name(NAME[n]);

		if( n == TEAM::RED)
		{
			for(size_t index = 0; index < CardFactory::AllCount(); ++index )
			{
				UNIQUE_CARD Card(CardFactory::PickIndex(index, m_direct_x));

				auto& mapEquip = light::excel::Loader::Instance()->find<ExcelData::EquipData>()->Map();
				ExcelData::Equip& equip = mapEquip[Card->Class()];

				SLOT_NO SlotNo = 0;
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.RightHand()), SlotNo++);
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.LeftHand()), SlotNo++);
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Helmet()), SlotNo++);
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Armor()), SlotNo++);
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Shirts()), SlotNo++);
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Boots()), SlotNo++);
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Robe()), SlotNo++);
				AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Glove()), SlotNo++);

				if(Card->GetIndex() < light::INI::Loader::Instance()->find<ConfigConstant>()->get<int>("TEST.MAX_CHARACTER") )
				{
					Card->Locate(Enum::Locate::SQUAD, index);
					Card->SetDisposition(light::POSITION_INT(index / light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_HEIGHT"), index % light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_HEIGHT")));
				}
				else
				{
					Card->Locate(Enum::Locate::DECK, index);
				}

				/// 요 코드가 밑쪽에 있어야됨. Card의 라이프 사이클을 넘겨주는 코드임.
                player->get_deck()->insert(Card.release());
			}
		}
		else if(n == TEAM::BLUE)
		{
			INT index = 0;

			if(light::INI::Loader::Instance()->find<ConfigConstant>()->get<int>("TEST.RANDOM_PICK"))
			{
				while( (INT)player->get_deck()->size() < light::INI::Loader::Instance()->find<ConfigConstant>()->get<int>("TEST.MAX_CHARACTER") )
				{
                    Card* Card(CardFactory::Pick(m_direct_x));
					if(player->get_deck()->find(Card->GetIndex()).get())
					{
						continue;
					}

					auto& mapEquip = light::excel::Loader::Instance()->find<ExcelData::EquipData>()->Map();
					ExcelData::Equip& equip = mapEquip[Card->Class()];

					SLOT_NO SlotNo = 0;
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.RightHand()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.LeftHand()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Helmet()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Armor()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Shirts()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Boots()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Robe()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Glove()), SlotNo++);
					Card->SetPosition(BluePosition[index]);

					Card->Locate(Enum::Locate::DECK, index);

					++index;

					/// 요 코드가 맨 밑쪽에 있어야됨. Card의 라이프 사이클을 넘겨주는 코드임.
                    player->get_deck()->insert(Card);
				}
			}
			else
			{
				for(int i = 0; i < light::INI::Loader::Instance()->find<ConfigConstant>()->get<int>("TEST.MAX_CHARACTER"); ++i)
				{
					std::stringstream stream;
					stream << "NPC.PICK" << i;
					int CardNo = light::INI::Loader::Instance()->find<PickConstant>()->get<int>(stream.str().c_str());

					Card* Card(CardFactory::Pick(CardNo, m_direct_x));

					auto& mapEquip = light::excel::Loader::Instance()->find<ExcelData::EquipData>()->Map();
					ExcelData::Equip& equip = mapEquip[Card->Class()];

					SLOT_NO SlotNo = 0;
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.RightHand()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.LeftHand()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Helmet()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Armor()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Shirts()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Boots()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Robe()), SlotNo++);
					AddToInventoryAndEquip(player, Card, ItemFactory::Pick(equip.Glove()), SlotNo++);
					Card->SetPosition(BluePosition[index]);

					Card->Locate(Enum::Locate::DECK, index);

					++index;

					/// 요 코드가 맨 밑쪽에 있어야됨. Card의 라이프 사이클을 넘겨주는 코드임.
                    player->get_deck()->insert(Card);
				}
			}

			Deck::card_list list;
            player->get_deck()->get_list(list);
			for each(auto& val in list)
			{
                player->get_squad()->AddCard(val);
			}
		}

		BattleManager::Instance()->AddPlayer(player);
	}

	ChangeMode(ModeID::CHARACTER_SETTING);
}

void SettingMode::End()
{
	
}

void SettingMode::Render()
{
}

void SettingMode::RenderPostUI()
{
	
}

void SettingMode::Logic()
{
}

} // namespace NW