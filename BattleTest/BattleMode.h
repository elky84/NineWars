#pragma once

#include "Mode.h"

#include <vector>

#include "Animation2D.h"
#include "Sprite2D.h"

#include "NWParticle.h"
#include "NWBattle.h"

#include "GuiButton.h"
#include "GuiTooltip.h"
#include "GuiCardStatus.h"
#include "GuiEditBox.h"
#include "GuiListBox.h"

namespace light
{

namespace view
{

class TilePainter;
class DirectX;

} // namespace view

} // namespace light

struct BATTLE_STATE
{
	enum type
	{
		NONE = -1,
		PLAY = 0,
		STOP,
		REWIND,
		NEXT,
		MAX,
	};
};

namespace NW
{

class BattleMode : public light::view::Mode
{
public:
	typedef std::multimap<light::POSITION_FLOAT, WEAK_CARD> MAP_SORT_CARD;

private:
	static const int IMAGE_UNIT = 70;

	static const int TEXT_UNIT = 20;

	static const int FONT_SIZE = 12;

public:
	BattleMode(light::weak_raw_ptr<light::view::DirectX> pDirectX);

	virtual ~BattleMode();

private:
	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

	bool SetButton(TEAM::type team, WEAK_CARD card, light::POSITION_INT position, int n);

	light::POSITION_INT ConvertDrawingPosition(const light::POSITION_FLOAT& pos, const light::POSITION_FLOAT& Size);

	void RenderPlayer(MAP_SORT_CARD& mapSortCard);

	bool ChangeState(BATTLE_STATE::type State);

private:
	int RED_X;
	int BLUE_X;

	int BATTLE_UI_TOP;
	int BATTLE_UI_BOTTOM;

	int BATTLE_UI_LEFT;
	int BATTLE_UI_RIGHT;

private:
	std::vector<NW::GuiCardStatus> m_vectorGuiCardStatus;
	std::vector<light::view::GuiTooltip> m_gui_tooltips;

	WEAK_BATTLE m_Battle;

	light::view::Sprite2D m_Map;
	light::view::Sprite2D m_BG;

	light::view::GuiButton m_GuiButton[BATTLE_STATE::MAX];

	BATTLE_STATE::type m_BattleState;
	INT m_BattleStateLifeCycle;

	light::view::GuiImage m_ListBoxBG;
	light::view::GuiListBox m_ListBox;
	light::view::GuiEditBox m_EditBox;

private:
	light::view::FmodEx m_BGM;
};

} // namespace NW