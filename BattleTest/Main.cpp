#include "stdafx.h"
#include "Main.h"

#include "BattleMode.h"
#include "CharacterSettingMode.h"
#include "SettingMode.h"
#include "DispositionMode.h"
#include "TacticsMode.h"

#include "ExcelLoader.h"

#include "BattleManager.h"
#include "NWPlayer.h"

#include "ConfigConstant.h"
#include "PickConstant.h"
#include "UIConstant.h"

Main::Main(const std::wstring& strProgramName, const std::wstring& strArg)
	: light::EnvironmentManager(strProgramName)
	, m_strArg(strArg)
{
}

Main::~Main()
{
}

bool Main::initialize()
{
	if( FALSE == m_direct_x.Init(get_program_name(), light::view::DEFAULT_FPS, TRUE) )
	{
		LOG_ERROR(_T("%s DirectX Init Failed."), __FUNCTIONW__);
		return false;
	}

	if( FALSE == m_direct_x.LoadFont(_T("Arita-Medium.ttf")))
	{
		LOG_ERROR(_T("DirectX::LoadFont() Failed"));
		return false;
	}

	if( false == light::INI::Loader::Instance()->Load() )
	{
		LOG_ERROR(L"called");
		return false;
	}


	if( false == light::excel::Loader::Instance()->Load() )
	{
        LOG_ERROR(L"called");
        return false;
	}

	m_BattleManager.reset(new NW::BattleManager);

//#ifdef _DEBUG
//#else // _DEBUG
//	m_BeginAnimation.Load(&m_direct_x, _T(".\\Gui\\Effect\\FadeIn.ani"));
//	m_EndAnimation.Load(&m_direct_x, _T(".\\Gui\\Effect\\FadeOut.ani"));
//
//	light::view::Mode::SetBeginAnimation(&m_BeginAnimation);
//	light::view::Mode::SetEndAnimation(&m_EndAnimation);
//#endif // _DEBUG

	m_direct_x.RegisterMode(new NW::SettingMode(&m_direct_x));
	m_direct_x.RegisterMode(new NW::CharacterSettingMode(&m_direct_x));
	m_direct_x.RegisterMode(new NW::BattleMode(&m_direct_x));
	m_direct_x.RegisterMode(new NW::DispositionMode(&m_direct_x));
	m_direct_x.RegisterMode(new NW::TacticsMode(&m_direct_x));

	m_direct_x.ActiveMode(NW::ModeID::SETTING);

	LOG_INFO(_T("%s Start %s Success"), __FUNCTIONW__, get_program_name());
	on_complete();
	return true;
}

void Main::on_update()
{
	m_direct_x.on_update();
}

void Main::release()
{
	LOG_INFO(_T("%s %s"), __FUNCTIONW__, get_program_name());
}
