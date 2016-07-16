#pragma once

namespace Enum
{

class SettingID
{
public:
	enum Type
	{
		CHARACTER_SETTING = 0, // 캐릭터
		DISPOSITION = 1, // 배치
		TACICS = 2, // 전술
		MAX = 3, // 최대
	};
};

static const WCHAR* SettingID_STR[] = {
		L"캐릭터", 
		L"배치", 
		L"전술", 
		L"최대", 
};

} // Enum

