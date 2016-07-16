#include "stdafx.h"
#include "NWParticle.h"

#include "NWCard.h"
#include "NWBattle.h"

namespace NW
{

Particle::Particle()
{
	memset(m_Direction, 0, sizeof(m_Direction));
}

Particle::~Particle()
{

}

void Particle::SetBattle(WEAK_BATTLE battle)
{
	m_Battle = battle;
}

void Particle::Draw(const light::POSITION_INT& Position, const bool Mirror, const bool FrameUpdate)
{
	m_Animation.Position(Position);
	if(FrameUpdate)
	{
		if( Info().m_Movable )
		{
			m_Animation.DrawLoop(Mirror);
		}
		else
		{
			m_Animation.Draw(Mirror);
			m_Animation.Update();
		}
	}
	else
	{
		m_Animation.Draw(Mirror);
	}
}

} // namespace NW