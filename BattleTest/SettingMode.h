#pragma once

#include "Mode.h"

#include "GuiButtonCard.h"
#include "GuiButton.h"
#include "GuiTooltip.h"

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
};

} // namespace NW