#pragma once

#include "Mode.h"

#include "SetupUI.h"
#include "DispositionUI.h"

#include <vector>

#include "Animation2D.h"
#include "Sprite2D.h"

#include "NWParticle.h"
#include "NWBattle.h"

#include "GuiButton.h"

#include "GuiTooltip.h"
#include "GuiSlider.h"

#include "GuiImage.h"

namespace light
{

namespace view
{

class DirectX;

} // namespace view

} // namespace light

namespace NW
{

class TacticsMode 
	: public SetupUI
	, public DispositionUI
{
public:
	typedef std::multimap<light::POSITION_FLOAT, WEAK_CARD> MAP_SORT_CARD;

public:
	TacticsMode(light::weak_raw_ptr<light::view::DirectX> pDirectX);

	virtual ~TacticsMode();

private:
	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	virtual bool OnDropSquadCardImpl(SLOT_NO SlotNo);

	bool OnClickSlider(INT n);

	virtual void Save();

private:
	light::view::Sprite2D m_BG;

	std::vector<light::view::GuiSlider> m_GuiStrategySlider;

	std::vector<light::view::GuiImage> m_GuiStrategyName;

	std::vector<light::view::GuiImage> m_GuiStrategyState;
};

} // namespace NW