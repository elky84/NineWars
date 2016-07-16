#include "stdafx.h"
#include "DispositionMode.h"

#include "DirectX.h"
#include "Input.h"
#include "FileUtil.h"

#include "BattleManager.h"

#include "NWBattle.h"
#include "NWPlayer.h"
#include "NWCard.h"
#include "NWSquad.h"
#include "NWDeck.h"

#include "UIConstant.h"

#include <boost/bind.hpp>

namespace NW
{

DispositionMode::DispositionMode(light::weak_raw_ptr<light::view::DirectX> pDirectX)
: SetupUI(ModeID::DISPOSITION, pDirectX)
, CardUI()
, DispositionUI()
{
}

DispositionMode::~DispositionMode()
{

}

void DispositionMode::Begin()
{
	m_BG.Load(m_direct_x, _T(".\\Gui\\Disposition\\BG.spr"));

	SetupUI::Show(m_direct_x);

	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	{
		Deck::card_list list;
		RedPlayer->get_deck()->get_list(list);
		CardUI::Show(m_direct_x, list);
	}

	{
		Deck::card_list list;
		RedPlayer->get_deck()->find(Enum::Locate::SQUAD, list);

		DispositionUI::Show(m_direct_x, list);
	}

	CalcGraph();
}


void DispositionMode::End()
{
	for each(auto& val in m_position_card)
		val.Append(NULL);
}

void DispositionMode::Render()
{
	m_BG.DrawSprite(0, light::POSITION_INT(0, 0), 0);
}

void DispositionMode::RenderPostUI()
{
	DrawGraph(light::POSITION_INT(0, 0));	
}

void DispositionMode::Logic()
{
	
}

int DispositionMode::EmptySquadPosition()
{
	for(int x = 0; x < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH"); ++x)
	{
		for(int y = 0; y < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_HEIGHT"); ++y)
		{
			int i = y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH") + x;
			if(m_position_holder[i].AppendPtr().get())
				continue;

			return i;
		}
	}
	return -1;
}

int DispositionMode::MatchingPosition(GuiButtonPosition* pButtonPosition)
{
	for(size_t i = 0; i < m_position_holder.size(); ++i)
	{
		if(m_position_holder[i].AppendPtr() == pButtonPosition)
		{
			return i;
		}
	}
	return -1;
}


bool DispositionMode::OnDropSquadCardImpl(SLOT_NO SlotNo)
{
	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	light::weak_raw_ptr<light::view::Gui> pAppendGui = m_squad_holder[SlotNo].AppendPtr();

	GuiButtonCard* pCardButton = light::view::Gui::Find<GuiButtonCard>(pAppendGui, m_Cards);
	GuiButtonCard* pSquadCard = light::view::Gui::Find<GuiButtonCard>(pAppendGui, m_squad_cards);

	WEAK_CARD pCard;
	if(pCardButton)
		pCard = pCardButton->GetCard();
	else if(pSquadCard)
		pCard = pSquadCard->GetCard();

	{
		int atPosition = MatchingPosition(&m_position_card[SlotNo]);
		if(atPosition != -1)
		{
			m_position_card[SlotNo].Release();
			m_position_holder[atPosition].Link(NULL);
		}
	}

	if( pAppendGui.get() )
	{
		int atPosition = EmptySquadPosition();

        std::wstring strThumbnail = pCard->Thumbnail();
        strThumbnail.erase(strThumbnail.begin(), strThumbnail.begin() + 2);

		m_position_card[SlotNo].Create(m_direct_x, pCard, _T(".\\Character\\template_position.spr"), light::get_file_name_without_ext(pCard->Thumbnail()) + _T("\\ANI_CH_IDLE_00") + strThumbnail, m_position_holder[atPosition].GetPosition());
		m_position_holder[atPosition].Append(&m_position_card[SlotNo]);
		m_position_card[SlotNo].Set();

		WEAK_CARD pOld = RedPlayer->get_deck()->find(Enum::Locate::SQUAD, SlotNo);
		if( pOld.get() )
		{
			pOld->Locate(Enum::Locate::DECK, SlotNo);
			RedPlayer->get_deck()->update(pOld);
		}

		pCard->Locate(Enum::Locate::SQUAD, SlotNo);
		RedPlayer->get_deck()->update(pCard);

		if(pCardButton)
		{
			m_squad_cards[SlotNo].SetCard(pCard);
			m_squad_cards[SlotNo].Set();
			m_squad_holder[SlotNo].Link(&m_squad_cards[SlotNo]);
		}
	}
	
	CalcGraph();
	if( pCardButton )
		return false;

	return true;
}


bool DispositionMode::OnDropCardImpl(SLOT_NO SlotNo)
{
	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	light::weak_raw_ptr<light::view::Gui> pAppendGui = m_CardHolder[SlotNo].AppendPtr();

	GuiButtonCard* pCardButton = light::view::Gui::Find<GuiButtonCard>(pAppendGui, m_Cards);
	GuiButtonCard* pSquadCard = light::view::Gui::Find<GuiButtonCard>(pAppendGui, m_squad_cards);
	if(pCardButton)
	{
	}
	else if(pSquadCard)
	{
		SLOT_NO target_slot_no = light::view::Gui::At<GuiButtonCard>(pSquadCard, m_squad_cards);
		int atPosition = MatchingPosition(&m_position_card[target_slot_no]);
		if(atPosition != -1)
		{
			m_position_card[target_slot_no].Release();
			m_position_holder[atPosition].Link(NULL);
		}

		m_squad_cards[target_slot_no].Release();
		m_squad_holder[target_slot_no].Link(NULL);

		WEAK_CARD pCard = RedPlayer->get_deck()->find(pSquadCard->GetCard()->GetIndex());
		if(pCard.get())
		{
			pCard->Locate(Enum::Locate::DECK, target_slot_no);
			RedPlayer->get_deck()->update(pCard);
		}
	}
	return true;
}

bool DispositionMode::OnClickCardImpl(GuiButtonCard* Card)
{
	UNREFERENCED_PARAMETER(Card);
	return true;
}

void DispositionMode::Save()
{
	WEAK_PLAYER Player = BattleManager::Instance()->GetPlayer(TEAM::RED);
	Player->get_squad()->ClearCards();

	for(int y = 0; y < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_HEIGHT"); ++y)
	{
		for(int x = 0; x < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH"); ++x)
		{
			GuiButtonPosition* pButtonPosition = light::view::Gui::Find<GuiButtonPosition>(m_position_holder[y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH") + x].AppendPtr(), m_position_card);
			if(pButtonPosition &&
				pButtonPosition->GetCard().get() )
			{
				WEAK_CARD Card = pButtonPosition->GetCard();
				Card->SetDisposition(light::POSITION_INT(x, y));

				Player->get_squad()->AddCard(Card);
			}
		}
	}
}

} // namespace NW