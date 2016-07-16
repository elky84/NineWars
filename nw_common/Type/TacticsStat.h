#pragma once

namespace Enum
{

class TacticsStat
{
public:
	enum Type
	{
		NONE = 0, // 없음
		ATTACK_TENDENCY = 1, // 공격 성향
		BOLDNESS = 2, // 대담성
		PREDICTION = 3, // 예측력
		DEFENSE_TENDENCY = 4, // 방어 성향
		AGGRESSIVE = 5, // 적극성
		COMPETITIVE = 6, // 승부욕
		CONCENTRATION = 7, // 집중력
		CALM = 8, // 침착함
		JUDGEMENT = 9, // 판단력
		TEAMWORK = 10, // 팀웍
		TACTICAL = 11, // 전술 수행 능력
		STRATEGY_TENDENCY = 12, // 전술 성향
		FREEDOM = 13, // 자유도
		ATTACK_DIRECTION = 14, // 공격 방향
	};
};

static const std::wstring TacticsStat_STR[] = {
		L"없음", 
		L"공격 성향", 
		L"대담성", 
		L"예측력", 
		L"방어 성향", 
		L"적극성", 
		L"승부욕", 
		L"집중력", 
		L"침착함", 
		L"판단력", 
		L"팀웍", 
		L"전술 수행 능력", 
		L"전술 성향", 
		L"자유도", 
		L"공격 방향", 
};

} // Enum

