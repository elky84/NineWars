#pragma once

#include "NWTypeDefinition.h"

namespace NW
{

class Skill
{
public:
	static const LEVEL MAX = 3;

public:
	Skill();

	Skill(const SKILL_INDEX index);

	~Skill();

	SKILL_INDEX Index() const
	{
		return m_Index;
	}

	SLOT_NO SlotNo() const
	{
		return m_SlotNo;
	}

	void Set(ExcelData::WEAK_SKILL skill);

	void Level(LEVEL level)
	{
		m_Level = level;
	}

	LEVEL Level() const
	{
		return m_Level;
	}

	INT Chance() const
	{
		return m_Chance;
	}

	ExcelData::WEAK_SKILL Info()
	{
		return m_Skill;
	}

private:
	LEVEL m_Level;

	INT m_Chance;

	SKILL_INDEX m_Index;

	SLOT_NO m_SlotNo;

	ExcelData::WEAK_SKILL m_Skill;
};

} // namespace NW