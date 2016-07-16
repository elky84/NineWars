#include "stdafx.h"
#include "NWItem.h"

#include "MetaData.h"

namespace NW
{

Item::Item(const ITEM_INDEX index)
	: m_Index(index)
	, m_CardIndex(0)
	, m_SlotNo(0)
	, m_Storage(Enum::Storage::NONE)
{

}

Item::Item()
	: m_Index(0)
	, m_CardIndex(0)
	, m_SlotNo(0)
	, m_Storage(Enum::Storage::NONE)
{

}

Item::~Item()
{

}


std::wstring Item::Name() const
{
	return m_ItemInfo->Name();
}


} // namespace NW