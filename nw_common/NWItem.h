#pragma once

#include "NWTypeDefinition.h"
#include "MetaData.h"

namespace NW
{

class Item
{
public:
	Item(const ITEM_INDEX index);

	Item();

	~Item();

	ITEM_INDEX Index() const
	{
		return m_Index;
	}

	std::wstring Name() const;

	void Info(ExcelData::WEAK_ITEMINFO iteminfo)
	{
		m_ItemInfo = iteminfo;
	}

	ExcelData::WEAK_ITEMINFO Info()
	{
		return m_ItemInfo;
	}

	void CardIndex(CARD_INDEX index)
	{
		m_CardIndex = index;
	}

	CARD_INDEX CardIndex() const
	{
		return m_CardIndex;
	}

	void Storage(CARD_INDEX Index, Enum::Storage::Type storage, SLOT_NO no)
	{
		m_Storage = storage;
		if(storage == Enum::Storage::INVENTORY)
			m_CardIndex = 0;
		else
			m_CardIndex = Index;

		m_SlotNo = no;
	}

	SLOT_NO SlotNo() const
	{
		return m_SlotNo;
	}

	Enum::Storage::Type Storage() const
	{
		return m_Storage;
	}

private:
	ITEM_INDEX m_Index;

	CARD_INDEX m_CardIndex;

	SLOT_NO m_SlotNo;

	Enum::Storage::Type m_Storage;

	ExcelData::WEAK_ITEMINFO m_ItemInfo;
};

} // namespace NW