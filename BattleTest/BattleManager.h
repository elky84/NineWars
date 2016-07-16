#pragma once

#include "Singleton.h"
#include "NWBattle.h"

namespace NW
{

class BattleManager 
	: public light::Singleton<BattleManager>
{
public:
    BattleManager();
    ~BattleManager();

	WEAK_BATTLE GetBattle()
	{
		return m_Battle;
	}

	void AddPlayer(Player* player);

	WEAK_PLAYER GetPlayer(TEAM::type teamtype);

private:
	UNIQUE_BATTLE m_Battle;

	std::vector<SHARED_PLAYER> m_vector_Player;
};

} // namespace NW