#include "stdafx.h"
#include "SettingMode.h"

#include "WindowUtil.h"
#include "Input.h"
#include "ImeInput.h"

#include "GuiTooltip.h"

#include "NWCard.h"
#include "NWCardFactory.h"
#include "NWBattle.h"
#include "NWPlayer.h"
#include "NWDeck.h"

#include <boost/bind.hpp>

#include "Profiler.h"

namespace NW
{

static const int IMAGE_UNIT = 80;
static const int TEXT_UNIT = 20;

SettingMode::SettingMode(light::weak_raw_ptr<light::view::DirectX> pDirectX)
    : light::view::Mode(NW::ModeID::CHARACTER_SETTING, pDirectX)
    , m_Player(new Player)
{
	
}

SettingMode::~SettingMode()
{

}

void SettingMode::Begin()
{
	m_Player->Name(_T("Picker"));
	m_gui_button_cards.resize(MAX_SQUAD_CARD);
	m_gui_tooltips.resize(MAX_SQUAD_CARD);

	m_EditBoxName.Create(m_direct_x, _T(".\\Gui\\EditBox\\editbox.spr"), light::POSITION_INT(200, 620), 20, D3DCOLOR_RGBA(255, 255, 255, 255));
    m_EditBoxName.Set();

	m_EditBoxDeck.Create(m_direct_x, _T(".\\Gui\\EditBox\\editbox.spr"), light::POSITION_INT(200, 680), 20, D3DCOLOR_RGBA(255, 255, 255, 255));
	m_EditBoxDeck.Set();

	m_PickGuiButton.Create(m_direct_x, _T(".\\Gui\\Button\\button.spr"), boost::bind(&SettingMode::Pick, this), light::POSITION_INT(1024 / 2, 680));
	m_PickGuiButton.Message(_T("Pick"), 20, D3DCOLOR_RGBA(255, 255, 255, 255));

	m_SelectGuiButton.Create(m_direct_x, _T(".\\Gui\\Button\\button.spr"), boost::bind(&SettingMode::Select, this), light::POSITION_INT(1024 / 2, 720));
	m_SelectGuiButton.Message(_T("Select"), 20, D3DCOLOR_RGBA(255, 255, 255, 255));
}

void SettingMode::End()
{
}

void SettingMode::Render()
{
	if(m_gui_button_cards.size() <= 	m_Player->get_deck()->size() )
	{
		DWORD color = D3DCOLOR_RGBA(0, 0, 0, 255);

		std::wstringstream strstream;
		strstream << _T("Complete. Press ESC key to Exit. Pick cards saved ") << m_EditBoxDeck.GetString() << _T(".db file.");

		DrawString(strstream.str(), light::POSITION_INT(0, 768 / 2 + IMAGE_UNIT / 2), 20, color);
	}

	DrawString(_T("PlayerName"), light::POSITION_INT(0, 620), 20);
	DrawString(_T("DeckName"), light::POSITION_INT(0, 680), 20);
}

void SettingMode::RenderPostUI()
{
	
}

void SettingMode::Logic()
{
	if(m_gui_button_cards.size() <= m_Player->get_deck()->size() )	
	{
		if(light::Input::Keyboard::Pressing(VK_ESCAPE))
		{
			PostQuitMessage(0);
		}
		return;
	}
}

bool SettingMode::Select()
{
	if(m_gui_button_cards.size() <= m_Player->get_deck()->size())
		return false;

	if(m_PickCard.get() == NULL)
		return false;

	size_t cardcount = m_Player->get_deck()->size();

	static const int slice_count = 12;

	int X = (IMAGE_UNIT + 5) * (cardcount % slice_count); 
	int Y = IMAGE_UNIT * (cardcount / slice_count);

    Card* card = new Card();
    card = m_PickCard.release();

    card->Locate(Enum::Locate::DECK, cardcount);
	m_Player->get_deck()->insert(card);

	m_gui_button_cards[cardcount].Create(m_direct_x, card, _T(".\\Gui\\CardMini\\BG.spr"), light::POSITION_INT(X, Y));
	m_gui_button_cards[cardcount].Set();

	m_gui_tooltips[cardcount].Create(m_direct_x, _T(".\\Gui\\ToolTip\\ToolTip.spr"));
	m_gui_button_cards[cardcount].Append(&m_gui_tooltips[cardcount], light::POSITION_INT(32, 32));

	m_PickCardButton.Release();
	return true;
}

bool SettingMode::Pick()
{
	light::ScopeProfiler profiler(__FUNCTIONW__);
	if(m_gui_button_cards.size() <= m_Player->get_deck()->size() )
		return false;

	do
	{
		m_PickCard.reset(NW::CardFactory::Pick(m_direct_x));
		m_PickCard->Locate(Enum::Locate::DECK, 0);
	}
	while( NULL != m_Player->get_deck()->find( m_PickCard->GetIndex() ).get() );

	if(m_PickCard.get())
	{
		m_PickCardButton.Create(m_direct_x, m_PickCard, _T(".\\Gui\\CardMini\\BG.spr"), light::POSITION_INT(1024 / 2 - IMAGE_UNIT / 2, 768 / 2 - IMAGE_UNIT / 2));
		m_PickCardButton.Set();

		m_PickTooltip.Create(m_direct_x, _T(".\\Gui\\ToolTip\\ToolTip.spr"));
		m_PickCardButton.Append(&m_PickTooltip, light::POSITION_INT(32, 32));
	}
	return true;
}

} // namespace NW
