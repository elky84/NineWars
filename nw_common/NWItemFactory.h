#pragma once

#include "NWTypeDefinition.h"

namespace NW
{

class ItemFactory
{
public:
	static Item* Pick(int No);

public:
	static ITEM_INDEX m_Index;
};

} // namespace NW