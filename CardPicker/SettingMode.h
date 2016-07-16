#pragma once

#include "Mode.h"

#include "GuiButtonCard.h"
#include "GuiEditBox.h"
#include "GuiButton.h"
#include "GuiTooltip.h"

#include <vector>

namespace NW
{

class SettingMode : public light::view::Mode
{
public:
	SettingMode(light::weak_raw_ptr<light::view::DirectX> pDirectX);

	virtual ~SettingMode();

	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	bool Select();

	bool Pick();

private:
	NW::UNIQUE_PLAYER m_Player;

	NW::UNIQUE_CARD m_PickCard;

	light::view::GuiTooltip m_PickTooltip;
	NW::GuiButtonCard m_PickCardButton;

	std::vector<light::view::GuiTooltip> m_gui_tooltips;
	std::vector<NW::GuiButtonCard> m_gui_button_cards;

	light::view::GuiButton m_SelectGuiButton;
	light::view::GuiButton m_PickGuiButton;

	light::view::GuiEditBox m_EditBoxDeck;

	light::view::GuiEditBox m_EditBoxName;
};

} // namespace NW