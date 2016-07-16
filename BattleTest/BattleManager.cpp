#include "stdafx.h"
#include "BattleManager.h"

#include "NWPlayer.h"

namespace NW
{

BattleManager::BattleManager()
    : m_Battle(new Battle)
{
}

BattleManager::~BattleManager()
{

}

void BattleManager::AddPlayer(Player* player)
{
	m_vector_Player.push_back(SHARED_PLAYER(player));
}

WEAK_PLAYER BattleManager::GetPlayer(TEAM::type teamtype)
{
	return m_vector_Player[teamtype].get();
}

} // namespace NW