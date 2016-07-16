#include "stdafx.h"
#include "NWItemFactory.h"
#include "MetaData.h"

#include "NWItem.h"

namespace NW
{

ITEM_INDEX ItemFactory::m_Index = 0;

Item* ItemFactory::Pick(int No)
{
	if( No == -1 )
		return NULL;

	Item* item = new Item(m_Index++);
	auto& mapItemInfo = light::excel::Loader::Instance()->find<ExcelData::ItemInfoData>()->Map();
	item->Info(&mapItemInfo[No]);
	return item;
}

} // namespace NW