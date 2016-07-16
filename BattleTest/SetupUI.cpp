#include "stdafx.h"
#include "SetupUI.h"

#include "UIConstant.h"
#include "boost/bind.hpp"

namespace NW
{

SetupUI::SetupUI(const ModeId Id, light::weak_raw_ptr<light::view::DirectX> pDirectX)
	: light::view::Mode(Id, pDirectX)
{
		INT X = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("BATTLE_START.BUTTON_X");
		INT Y = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("BATTLE_START.BUTTON_Y");
		INT X_INTERVAL = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("BATTLE_START.BUTTON_OUTLINE_INTERVAL_X");
		INT Y_INTERVAL = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("BATTLE_START.BUTTON_OUTLINE_INTERVAL_Y");

		m_StartOutline.Create(pDirectX, _T(".\\Gui\\PlayControl\\StartOutline.spr"), NULL, light::POSITION_INT(X, Y));
		m_Start.Create(pDirectX, _T(".\\Gui\\PlayControl\\Start.spr"), boost::bind(&SetupUI::Start, this), light::POSITION_INT(X + X_INTERVAL, Y + Y_INTERVAL));

		light::POSITION_INT TabPosition(659, 13);
		for (size_t n = 0; n < _countof(m_Tab); ++n)
		{
			m_Tab[n].Create(m_direct_x, _T(".\\Gui\\Common\\Tab.spr"), boost::bind(&SetupUI::Tab, this, (Enum::SettingID::Type)n), TabPosition + light::POSITION_INT(6, 3));
			m_TabOutline[n].Create(m_direct_x, _T(".\\Gui\\Common\\TabOutline.spr"), TabPosition);

			TabPosition.X(TabPosition.X() + 105 + 2);
		}
}

SetupUI::~SetupUI()
{

}

void SetupUI::Show(light::weak_raw_ptr<light::view::DirectX> pDirectX)
{
	UNREFERENCED_PARAMETER(pDirectX);
	for(size_t n = 0; n < _countof(m_Tab); ++n)
	{
		m_Tab[n].Message(Enum::SettingID_STR[n], 20, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::CENTER);
		m_TabOutline[n].Set();
	}

	m_Start.Set();
	m_StartOutline.Set();
}

bool SetupUI::Start()
{
	Save();
	ChangeMode(ModeID::BATTLE);
	return true;
}

bool SetupUI::Tab(Enum::SettingID::Type type)
{
	Save();
	switch(type)
	{
	case Enum::SettingID::CHARACTER_SETTING:
		ChangeMode(ModeID::CHARACTER_SETTING);
		break;
	case Enum::SettingID::DISPOSITION:
		ChangeMode(ModeID::DISPOSITION);
		break;
	case Enum::SettingID::TACICS:
		ChangeMode(ModeID::TACICS);
		break;
	}
	return true;
}

} // namespace NW