#pragma once

namespace Enum
{

class Storage
{
public:
	enum Type
	{
		NONE  = -1, // 없음
		INVENTORY = 0, // 인벤토리
		EQUIP = 1, // 장착
		RESERVE = 2, // 예약
	};
};

static const std::wstring Storage_STR[] = {
		L"없음", 
		L"인벤토리", 
		L"장착", 
		L"예약", 
};

} // Enum

