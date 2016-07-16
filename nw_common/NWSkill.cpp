#include "stdafx.h"
#include "NWSkill.h"

#include "MetaData.h"

namespace NW
{

Skill::Skill()
	: m_Index(0)
	, m_Level(1)
{

}

Skill::Skill(const SKILL_INDEX index)
	: m_Index(index)
{

}

Skill::~Skill()
{

}

void Skill::Set(ExcelData::WEAK_SKILL skill)
{
	m_Skill = skill;
	m_Level = MAX;
	m_Chance = skill->BasicChance();
	for(INT n = 0; n < m_Level; ++n)
		m_Chance += m_Skill->Increase();
}

} // namespace NW