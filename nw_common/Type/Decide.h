#pragma once

namespace Enum
{

class Targeting
{
public:
	enum Type
	{
		NEAR_DISTANCE = 0, // 가까운 적
		STRONG_CLASS = 1, // 상성
		LESS_HP = 2, // 적은 체력
		MAX = 3, // 최대
		NONE = 4, // 없음
	};
};

static const std::wstring Targeting_STR[] = {
		L"가까운 적", 
		L"상성", 
		L"적은 체력", 
		L"최대", 
		L"없음", 
};

} // Enum

namespace Enum
{

class MoveDecide
{
public:
	enum Type
	{
		MAINTAIN_SPEED = 0, // 속도 유지
		CONTROL_SPEED = 1, // 속도 조절
		MAINTAIN_RANGE = 2, // 거리 유지
		MAX = 3, // 최대
		NONE = 4, // 없음
	};
};

static const std::wstring MoveDecide_STR[] = {
		L"속도 유지", 
		L"속도 조절", 
		L"거리 유지", 
		L"최대", 
		L"없음", 
};

} // Enum

namespace Enum
{

class MaintainSpeed
{
public:
	enum Type
	{
		CURRENT_STATE = 0, // 현재 상황
		MOVE_TENDENCY = 1, // 이동 성향
		WAR_SITUATION = 2, // 전투 상황
		MAX = 3, // 최대
		NONE = 4, // 없음
	};
};

static const std::wstring MaintainSpeed_STR[] = {
		L"현재 상황", 
		L"이동 성향", 
		L"전투 상황", 
		L"최대", 
		L"없음", 
};

} // Enum

