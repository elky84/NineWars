#include "stdafx.h"
#include "BattleMode.h"

#include "DirectX.h"

#include "NWCard.h"
#include "NWPlayer.h"
#include "NWSquad.h"
#include "NWAction.h"
#include "NWParticle.h"

#include "BattleManager.h"

#include "TilePainter.h"

#include <boost/bind.hpp>

#include "Input.h"
#include "GuiTooltip.h"

#include "Profiler.h"

namespace NW
{

BattleMode::BattleMode(light::weak_raw_ptr<light::view::DirectX> pDirectX)
    : light::view::Mode(ModeID::BATTLE, pDirectX)
    #ifdef _DEBUG
    , m_BattleState(BATTLE_STATE::PLAY)
    #else // _DEBUG
    , m_BattleState(BATTLE_STATE::NONE)
    #endif //_DEBUG
    , RED_X(10)
    , BLUE_X(pDirectX->Width() - 147 - 10)
    , BATTLE_UI_TOP(0)
    , BATTLE_UI_BOTTOM(0)
    , BATTLE_UI_LEFT(0)
    , BATTLE_UI_RIGHT(0)
    , m_BattleStateLifeCycle(0)
{
	m_BGM.LoadStream(_T("Sound\\Battle.ogg"), true);	
}

BattleMode::~BattleMode()
{

}

bool BattleMode::SetButton(TEAM::type team, WEAK_CARD card, light::POSITION_INT position, int n)
{
	light::ScopeProfiler profiler(__FUNCTIONW__);
	card->SetTeam(team, n);
	card->GuiSet();

	if( false == m_vectorGuiCardStatus[n].Create(m_direct_x, card, _T(".\\Gui\\Character\\Background.spr"), position, TEAM::RED == team ? light::view::Gui::Direction::LEFT : light::view::Gui::Direction::RIGHT ) )
		return false;

	m_gui_tooltips[n].Create(m_direct_x, _T(".\\Gui\\Tooltip\\ToolTip.spr"));

	m_vectorGuiCardStatus[n].Append(&m_gui_tooltips[n], light::POSITION_INT(32, 32));
	m_vectorGuiCardStatus[n].Set();
	return true;
}

void BattleMode::Begin()
{
	m_vectorGuiCardStatus.resize(MAX_SQUAD_CARD * TEAM::MAX);
	m_gui_tooltips.resize(MAX_SQUAD_CARD * TEAM::MAX);

	m_ListBoxBG.Create(m_direct_x, _T(".\\Gui\\Chat\\BG.spr"), light::POSITION_INT(10, 580));
	m_ListBox.Create(m_direct_x, _T(".\\Gui\\Chat\\ListBox.spr"), _T(".\\Gui\\Chat\\ScrollBar.spr"), light::POSITION_INT(10 + 2, 580), light::view::Gui::Direction::UP);
	m_EditBox.Create(m_direct_x, _T(".\\Gui\\Chat\\editbox.spr"), light::POSITION_INT(10, 685), FONT_SIZE, D3DCOLOR_RGBA(255, 255, 255, 255));
	m_EditBox.Append(&m_ListBox);

	m_GuiButton[BATTLE_STATE::PLAY].Create(m_direct_x, _T(".\\Gui\\PlayControl\\Play.spr"), boost::bind(&BattleMode::ChangeState, this, BATTLE_STATE::PLAY), light::POSITION_INT(900, 670));
	m_GuiButton[BATTLE_STATE::STOP].Create(m_direct_x, _T(".\\Gui\\PlayControl\\Stop.spr"), boost::bind(&BattleMode::ChangeState, this, BATTLE_STATE::STOP), light::POSITION_INT(950, 670));
	m_GuiButton[BATTLE_STATE::REWIND].Create(m_direct_x, _T(".\\Gui\\PlayControl\\Rewind.spr"), boost::bind(&BattleMode::ChangeState, this, BATTLE_STATE::REWIND), light::POSITION_INT(1000, 670));
	m_GuiButton[BATTLE_STATE::NEXT].Create(m_direct_x, _T(".\\Gui\\PlayControl\\next.spr"), boost::bind(&BattleMode::ChangeState, this, BATTLE_STATE::NEXT), light::POSITION_INT(1050, 670));

	m_BG.Load(m_direct_x, _T(".\\Map\\BG.spr"));
	BATTLE_UI_TOP = m_BG.GetRect(0, 0).Height();

	m_Map.Load(m_direct_x, _T(".\\Map\\Map.spr"));
	BATTLE_UI_BOTTOM = WINDOWS_HEIGHT - BATTLE_UI_TOP;
	BATTLE_UI_LEFT = CHARACTER_SIZE * 2;
	BATTLE_UI_RIGHT = m_Map.GetRect(0, 0).Width() - CHARACTER_SIZE;

	m_Battle = BattleManager::Instance()->GetBattle();

	WEAK_PLAYER RedPlayer = BattleManager::Instance()->GetPlayer(TEAM::RED);
	WEAK_PLAYER BluePlayer = BattleManager::Instance()->GetPlayer(TEAM::BLUE);

	for(int i = 0; i < BATTLE_STATE::MAX; ++i)
	{
		m_GuiButton[i].Set();
	}

	for each( auto& val in RedPlayer->get_squad()->MapCard())
	{
		WEAK_CARD Card = val.second;
		SetButton(TEAM::RED, Card, light::POSITION_INT(RED_X, Card->SlotNo() * (56 + 2)), Card->SlotNo());

		Inventory::item_list list;
		RedPlayer->get_inventory()->find(Card->GetIndex(), list);
		Card->CalcuateEquipEffect(list);

		Card->CalcAddStat();

		Card->LoadAnimation();
	}

	for each( auto& val in BluePlayer->get_squad()->MapCard())
	{
		WEAK_CARD Card = val.second;
		SetButton(TEAM::BLUE, Card, light::POSITION_INT(BLUE_X, Card->SlotNo() * (56 + 2)), Card->SlotNo() + MAX_SQUAD_CARD);

		Inventory::item_list list;
		BluePlayer->get_inventory()->find(Card->GetIndex(), list);
		Card->CalcuateEquipEffect(list);

		Card->CalcAddStat();

		Card->LoadAnimation();
	}

	m_Battle->Add(RedPlayer->get_squad(), TEAM::RED);
	m_Battle->Add(BluePlayer->get_squad(), TEAM::BLUE);

	m_ListBoxBG.Set();
	m_ListBox.Set();
	m_EditBox.Set();

	m_BGM.Play();
}

void BattleMode::End()
{
}

bool BattleMode::ChangeState(BATTLE_STATE::type State)
{
	m_BattleState = State;
	m_BattleStateLifeCycle = 10;
	return true;
}

void BattleMode::Render()
{
	m_BG.DrawSprite(0, light::POSITION_INT(0, 0), 0);
	m_Map.DrawSprite(0, light::POSITION_INT(0, m_BG.GetRect(0, 0).Height()), 0);

	MAP_SORT_CARD mapSortCard;
	{
		Squad::MAP_CARD& mapCard = BattleManager::Instance()->GetPlayer(TEAM::RED)->get_squad()->MapCard();
		for each(auto& val in mapCard)
		{
			WEAK_CARD card = val.second;
			mapSortCard.insert(MAP_SORT_CARD::value_type(card->GetPosition(), card));
		}
	}
	{
		Squad::MAP_CARD& mapCard = BattleManager::Instance()->GetPlayer(TEAM::BLUE)->get_squad()->MapCard();
		for each(auto& val in mapCard)
		{
			WEAK_CARD card = val.second;
			mapSortCard.insert(MAP_SORT_CARD::value_type(card->GetPosition(), card));
		}
	}

	RenderPlayer(mapSortCard);

	Battle::LIST_PARTICLE& listParticle = m_Battle->ListParticle();
	for each(WEAK_PARTICLE particle in listParticle)
	{
		light::POSITION_INT convPos = ConvertDrawingPosition(particle->GetPosition(), light::POSITION_FLOAT(CHARACTER_SIZE / 2, CHARACTER_SIZE / 1.3f));

		Particle::Information info = particle->Info();
		if( info.m_Value != 0.0f )
		{
			std::wstringstream strstream;
			strstream << floor(info.m_Value);

			DWORD dwColor = D3DCOLOR_RGBA(255, 255, 255, 255);

			DrawString(strstream.str(), convPos - light::POSITION_INT(0, CHARACTER_SIZE / 4), light::RECT_INT(0, 0, CHARACTER_SIZE, CHARACTER_SIZE / 4), 20, dwColor);
		}
		else
		{
			bool Mirror = false;
			if( light::LookAtToDegree(particle->Direction().x, particle->Direction().y) < 180.0f)
				Mirror = true;

			particle->Draw(convPos, Mirror, m_BattleState != BATTLE_STATE::STOP);
		}
	}

	if(m_BattleState == BATTLE_STATE::NEXT)
	{
		if(m_BattleStateLifeCycle <= 0)
		{
			m_BattleState = BATTLE_STATE::STOP;
		}
	}
}

void BattleMode::RenderPlayer(MAP_SORT_CARD& mapSortCard)
{
	for each(auto& val in mapSortCard)
	{
		WEAK_CARD card = val.second;

		light::POSITION_INT GuiPosition = m_vectorGuiCardStatus[card->GetButtonIndex()].GetPosition();

		std::wstringstream strstream;
		NW::WEAK_ACTION action = card->GetAction();
		if(action.get())
		{
			WEAK_CARD target = action->GetTarget();
			if( target.get() )
			{
				strstream << _T("\n") << _T("타겟:") << target->Name();

				if( 0 <= action->TargetingType() && action->TargetingType() < Enum::Targeting::MAX )
					strstream << _T("\n") << _T("타게팅:") << Enum::Targeting_STR[action->TargetingType()];

				if( 0 <= action->MoveDecideType() && action->MoveDecideType() < Enum::MoveDecide::MAX )
					strstream << _T("\n") << _T("이동:") << Enum::MoveDecide_STR[action->MoveDecideType()];

				if(action->TargetingTurn() == NW::Action::INFINITE_TARGETING_TIME)
					strstream << _T("\n") << _T("턴:") << _T("INFINITE");
				else
					strstream << _T("\n") << _T("턴:") << action->TargetingTurn();
			}
		}

		if( card->GetTeam() == TEAM::RED)
			DrawString(strstream.str(), GuiPosition + light::POSITION_INT(CHARACTER_SIZE, 0), light::RECT_INT(0, 0, IMAGE_UNIT + IMAGE_UNIT, IMAGE_UNIT), 10, D3DCOLOR_RGBA(255, 255, 255, 255));
		else
			DrawString(strstream.str(), GuiPosition - light::POSITION_INT(CHARACTER_SIZE, 0), light::RECT_INT(0, 0, IMAGE_UNIT + IMAGE_UNIT, IMAGE_UNIT), 10, D3DCOLOR_RGBA(255, 255, 255, 255));

		card->Draw(ConvertDrawingPosition(card->GetPosition(), light::POSITION_FLOAT((float)card->Width() / 2, (float)card->Height()) ), m_BattleState != BATTLE_STATE::STOP);
	}
}

void BattleMode::RenderPostUI()
{
	
}

void BattleMode::Logic()
{
	if(m_BattleStateLifeCycle != 0)
		--m_BattleStateLifeCycle;

	switch(m_BattleState)
	{
	case BATTLE_STATE::PLAY:
		{
			m_Battle->update_turn();
		}
		break;
	case BATTLE_STATE::NEXT:
		{
			m_Battle->update_turn();
		}
		break;
	}
}

light::POSITION_INT BattleMode::ConvertDrawingPosition(const light::POSITION_FLOAT& pos, const light::POSITION_FLOAT& Size)
{
	float fBattleUIWidth = (float)BATTLE_UI_RIGHT - BATTLE_UI_LEFT;
	float fBattleUIHeight = (float)BATTLE_UI_BOTTOM - BATTLE_UI_TOP;
	float fWidthRatio = fBattleUIWidth / MAP_WIDTH;
	float fHeightRatio = fBattleUIHeight / MAP_HEIGHT;

	light::POSITION_INT rect;
	rect.X(BATTLE_UI_LEFT + (long)((pos.X() - Size.X()) * fWidthRatio));
	rect.Y(BATTLE_UI_TOP + (long)((pos.Y() - Size.Y()) * fHeightRatio));
	return rect;
}

} // namespace NW