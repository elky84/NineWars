#pragma once

#include "NWTypeDefinition.h"
#include "Animation2D.h"

namespace NW
{

class Particle
{
public:
	enum TYPE
	{
		NONE = -1,
		TEXT = 0,
		WARRIOR = 1,
		KNIGHT = 2,
		ASSASSIN = 3,
		RIDER = 4,
		BOW = 5,
		HEALER = 6,
		MAGICIAN = 7,
		SKILL,
		AURA,
	};

	struct Information
	{
	public:
		Information(const bool Movable, Particle::TYPE type = NONE, float value = 0.0f)
			: m_Movable(Movable)
			, m_Type(type)
			, m_Value(value)
		{
		}

	public:
		Particle::TYPE m_Type;

		float m_Value;

		bool m_Movable;
	};

public:
	Particle();

	virtual ~Particle();

public:
	light::POSITION_FLOAT& GetPosition()
	{
		return m_position;
	}

	D3DXVECTOR3 Direction()
	{
		return m_Direction;
	}

	float X() const
	{
		return m_position.X();
	}

	float Y() const
	{
		return m_position.Y();
	}

	void Draw(const light::POSITION_INT& Position, const bool Mirror, const bool FrameUpdate);

public:
	virtual bool Update() = 0;

	virtual Particle::Information Info() const = 0;

protected:
	void SetBattle(WEAK_BATTLE battle);

protected:
	WEAK_BATTLE m_Battle;

	D3DXVECTOR3 m_Direction;

	light::POSITION_FLOAT m_position;

	WEAK_CARD m_Card;

	light::view::Animation2D m_Animation;
};

} // namespace NW