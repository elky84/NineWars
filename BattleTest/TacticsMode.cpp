#include "stdafx.h"
#include "TacticsMode.h"

#include "DirectX.h"
#include "Input.h"

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

TacticsMode::TacticsMode(light::weak_raw_ptr<light::view::DirectX> pDirectX)
: SetupUI(ModeID::TACICS, pDirectX)
, DispositionUI()
{
}

TacticsMode::~TacticsMode()
{

}

void TacticsMode::Begin()
{
	m_BG.Load(m_direct_x, _T(".\\Gui\\Tactics\\BG.spr"));

	auto& mapTactics = light::excel::Loader::Instance()->find<ExcelData::TacticsData>()->Map();
	m_GuiStrategySlider.resize(mapTactics.size());
	m_GuiStrategyName.resize(mapTactics.size());
	m_GuiStrategyState.resize(mapTactics.size());

	SetupUI::Show(m_direct_x);

	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	INT INTERVAL = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("STRATEGY.INTERVAL");
	INT SLIDER_INTERVAL = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("STRATEGY.SLIDER_INTERVAL");
	INT X = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("STRATEGY.X");
	INT Y = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("STRATEGY.Y");

	int n = 0;
	for( auto it = mapTactics.begin(); it != mapTactics.end(); ++it, ++n )
	{
		ExcelData::Tactics& tactics = it->second;

		m_GuiStrategyName[n].Create(m_direct_x, _T(".\\Gui\\Tactics\\AbilityName.spr"), light::POSITION_INT(X, Y));
		m_GuiStrategyName[n].Message(tactics.Name(), 20, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::CENTER);
		m_GuiStrategyName[n].MessageAdjust(light::POSITION_INT(0, 6));
		m_GuiStrategyName[n].Set();

		m_GuiStrategySlider[n].Create(m_direct_x, _T(".\\Gui\\Slider\\Slider.spr"), light::POSITION_INT(X + m_GuiStrategyName[n].GetRect().Width() + INTERVAL, Y + SLIDER_INTERVAL), boost::bind(&TacticsMode::OnClickSlider, this, n));
		m_GuiStrategySlider[n].Set();

		auto& mapTacticsString = light::excel::Loader::Instance()->find<ExcelData::TacticsStringData>()->Map();
		ExcelData::TacticsString& tacticsString = mapTacticsString[n + 1];

		m_GuiStrategyState[n].Create(m_direct_x, _T(".\\Gui\\Tactics\\AbilityCondition.spr"), light::POSITION_INT(X + m_GuiStrategyName[n].GetRect().Width() + INTERVAL + m_GuiStrategySlider[n].GetRect().Width() + INTERVAL, Y));
		m_GuiStrategyState[n].Message(tacticsString.VectorString()[0], 20, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::CENTER);
		m_GuiStrategyState[n].MessageAdjust(light::POSITION_INT(0, 6));
		m_GuiStrategyState[n].Set();

		Y += (m_GuiStrategyName[n].GetRect().Height() + INTERVAL);
	}

	{
		Deck::card_list list;
		RedPlayer->get_deck()->find(Enum::Locate::SQUAD, list);

		DispositionUI::Show(m_direct_x, list, light::POSITION_INT(WINDOWS_WIDTH / 2, 0));
	}

	CalcGraph();
}

void TacticsMode::End()
{
}

void TacticsMode::Render()
{
	m_BG.DrawSprite(0, light::POSITION_INT(0, 0), 0);
}

void TacticsMode::RenderPostUI()
{
	DrawGraph(light::POSITION_INT(WINDOWS_WIDTH / 2, 0));	
}

void TacticsMode::Logic()
{
	
}

bool TacticsMode::OnDropSquadCardImpl(SLOT_NO SlotNo)
{
	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);

	light::weak_raw_ptr<light::view::Gui> pAppendGui = m_squad_holder[SlotNo].AppendPtr();
	GuiButtonCard* pSquadCard = light::view::Gui::Find<GuiButtonCard>(pAppendGui, m_squad_cards);
	if(pSquadCard)
	{
		WEAK_CARD pCard = pSquadCard->GetCard();
		if(pCard.get())
		{
			pCard->Locate(Enum::Locate::SQUAD, SlotNo);
			RedPlayer->get_deck()->update(pCard);
		}
	}

	CalcGraph();
	return true;
}

bool TacticsMode::OnClickSlider(INT n)
{
	auto& mapTacticsString = light::excel::Loader::Instance()->find<ExcelData::TacticsStringData>()->Map();
	ExcelData::TacticsString& tacticsString = mapTacticsString[n + 1];
	
	size_t at = 0;
	for(; at < tacticsString.VectorPoint().size(); ++at)
	{
		if( m_GuiStrategySlider[n].GetValue() <= tacticsString.VectorPoint()[at] )
		{
			break;
		}
	}

	m_GuiStrategyState[n].Message(tacticsString.VectorString()[at], 20, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::CENTER);
	return true;
}

void TacticsMode::Save()
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