#pragma once

#include "Mode.h"

#include "MetaData.h"

#include "GuiButton.h"
#include "GuiImage.h"

namespace NW
{

class SetupUI
	: public light::view::Mode
{
public:
	SetupUI(const ModeId Id, light::weak_raw_ptr<light::view::DirectX> pDirectX);
	virtual ~SetupUI();

protected:
	bool Start();

	virtual void Save() = 0;

	void Show(light::weak_raw_ptr<light::view::DirectX> pDirectX);

private:
	bool Tab(Enum::SettingID::Type type);

protected:
	light::view::GuiButton m_Tab[Enum::SettingID::MAX];
	light::view::GuiImage m_TabOutline[Enum::SettingID::MAX];

	light::view::GuiButton m_Start;
	light::view::GuiButton m_StartOutline;
};

} // namespace NW