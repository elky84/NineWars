#pragma once

#include "NWTypeDefinition.h"
#include "MetaData.h"
#include <map>

namespace NW
{

class Decide
{
public:
	typedef std::multimap< TARGETING_VALUE, WEAK_CARD> MAP_TARGETING;

public:
	typedef std::map< Enum::MoveDecide::Type, MOVE_DECIDE_VALUE> MAP_MOVE;

public:
	typedef std::map< WEAK_CARD, POWER_DECIDE_VALUE>  MAP_POWER;

	typedef std::map< TEAM::type, POWER_DECIDE_VALUE>  MAP_TEAM_POWER;

public:
	Decide();
	~Decide();

	SHARED_ACTION SelectAction(WEAK_CARD card);

	void SetBattle(WEAK_BATTLE battle)
	{
		m_Battle = battle;
	}

	void CalcPower();

	POWER_DECIDE_VALUE Power(WEAK_CARD card);
	POWER_DECIDE_VALUE TargetedEnemyPower(WEAK_CARD card);
	POWER_DECIDE_VALUE TeamPower(WEAK_CARD card);

private:
	WEAK_CARD SelectTarget(WEAK_CARD card, Enum::Targeting::Type& targetingType);

	Enum::MoveDecide::Type MoveDecide(WEAK_CARD card);

private:
	WEAK_BATTLE m_Battle;

	MAP_POWER m_mapPower;

	MAP_TEAM_POWER m_mapTeamPower;
};

} // namespace NW