#pragma once

#include "Mode.h"

#include "SetupUI.h"
#include "CardUI.h"
#include "DispositionUI.h"

#include <vector>

#include "Animation2D.h"
#include "Sprite2D.h"

#include "NWParticle.h"
#include "NWBattle.h"

#include "GuiButton.h"

#include "GuiImage.h"
#include "GuiTooltip.h"
#include "GuiSlider.h"

namespace light
{

namespace view
{

class DirectX;

} // namespace view

} // namespace light

namespace NW
{

class DispositionMode 
	: public SetupUI
	, public CardUI
	, public DispositionUI
{
public:
	typedef std::multimap<light::POSITION_FLOAT, WEAK_CARD> MAP_SORT_CARD;

public:
	DispositionMode(light::weak_raw_ptr<light::view::DirectX> pDirectX);

	virtual ~DispositionMode();

private:
	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	virtual void Save();

	virtual bool OnDropSquadCardImpl(SLOT_NO SlotNo);

	virtual bool OnDropCardImpl(SLOT_NO SlotNo);

	virtual bool OnClickCardImpl(GuiButtonCard* Card);

private:
	int EmptySquadPosition();

	int MatchingPosition(GuiButtonPosition* pButtonPosition);

private:
	light::view::Sprite2D m_BG;
};

} // namespace NW