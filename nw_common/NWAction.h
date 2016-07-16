#pragma once

#include "NWTypeDefinition.h"

#include <vector>

#include "NWDecide.h"

namespace NW
{

class Action
{
public:
	struct Diretion
	{
		enum Type
		{
			NONE = -1,
			STRAIGHT,
			LEFT,
			RIGHT,
			UP,
			DOWN,
		};
	};

public:
	static const USHORT INFINITE_TARGETING_TIME = 0xFF;

	static const USHORT CHANGABLE_TARGETING_TIME = 10;

	static const USHORT DEFAULT_MOVING_TIME = 10;

public:
	Action();
	~Action();

	WEAK_CARD GetCard()
	{
		return m_Card;
	}

	WEAK_CARD GetTarget()
	{
		return m_Target;
	}

	Enum::Targeting::Type TargetingType() const
	{
		return m_TargetingType;
	}

	Enum::MoveDecide::Type MoveDecideType() const
	{
		return m_MoveDecideType;
	}

	void Set(WEAK_DECIDE decide, WEAK_CARD card, WEAK_CARD target, Enum::MoveDecide::Type moveDecideType, Enum::Targeting::Type targetingType);

	void SetBattle(WEAK_BATTLE battle)
	{
		m_Battle = battle;
	}

	void SetCard(WEAK_CARD card)
	{
		m_Card = card;
	}
	
	void DecideAttackMethod();

	bool Update();

	bool Attack();

	float Range();

	bool Move();

	bool Moving();

	USHORT TargetingTurn() const
	{
		return m_TargetingTurn;
	}

	float MoveValue();

private:
	bool Route(const light::POSITION_FLOAT& Destination);

private:
	WEAK_BATTLE m_Battle;

	WEAK_CARD m_Card;

	WEAK_CARD m_Target;

	bool m_PreDelay;

	USHORT m_TargetingTurn;

	Enum::MoveDecide::Type m_MoveDecideType;

	Enum::Targeting::Type m_TargetingType;

	WEAK_DECIDE m_Decide;

	USHORT m_MovingTime;

	float m_MoveValue;

	Diretion::Type m_Direction;

	AttackMethod::Type m_AttackMethod;
};

} // namespace NW