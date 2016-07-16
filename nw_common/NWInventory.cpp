#include "stdafx.h"
#include "NWInventory.h"

#include "NWItem.h"

namespace NW
{

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

bool Inventory::insert(Item* item)
{
	if( item == NULL)
	{
		LOG_ERROR(_T("Cannot insert object | src Card is null"));
		return false;
	}

	pair_value pair = m_Container.insert(item);
	if (pair.second == false)
	{
		LOG_ERROR(_T("Cannot insert object | Index[%d]"), item->Index());
        SAFE_DELETE(item);
		return false;
	}

	return true;
}


bool Inventory::erase(IN const ITEM_INDEX val)
{
	static const indices::type n = indices::IDX_INDEX;

	containter::nth_index<n>::type& indexBy = m_Container.get<n>();
	containter::nth_index_iterator<n>::type it = indexBy.find(val);
	if (indexBy.end() == it)
		return false;

	m_Container.erase(it);
	return true;
}

bool Inventory::update(WEAK_ITEM pItem)
{
	Item* temp = pItem.get();

	static const indices::type n = indices::IDX_INDEX;
	containter::nth_index<n>::type& indexBy = m_Container.get<n>();
	containter::nth_index_iterator<n>::type it = indexBy.find(pItem->Index());
	if (indexBy.end() == it)
		return false;

	m_Container.erase(it);

	pair_value pair = m_Container.insert(temp);
	if (pair.second == false)
	{
		LOG_ERROR(_T("Cannot insert object | Index[%d]"), temp->Index());
		return false;
	}

	return true;
}

WEAK_ITEM Inventory::find( IN const ITEM_INDEX val)
{
	static const indices::type n = indices::IDX_INDEX;

	containter::nth_index<n>::type& indexBy = m_Container.get<n>();
	containter::nth_index_iterator<n>::type it = indexBy.find(val);
	if (indexBy.end() == it)
	{
		LOG_DEBUG(_T("not find item | Value[%d]"), val);
		return NULL;
	}

	return const_cast<Item*>(*it);
}

size_t Inventory::find( IN const Enum::Storage::Type val, item_list& list)
{
	static const indices::type n = indices::IDX_COMP_STORAGE;

	containter::nth_index<n>::type& indexBy = m_Container.get<n>();

	std::pair<
		containter::nth_index_iterator<n>::type, 
		containter::nth_index_iterator<n>::type
	> pair;

	containter::nth_index_iterator<n>::type iter;

	pair = indexBy.equal_range(val);
	for (iter = pair.first; iter != pair.second; ++iter)
	{
		WEAK_ITEM p = const_cast<Item*>(*iter);
		list.push_back(p);
	}
	return list.size();
}


size_t Inventory::find( IN const CARD_INDEX val, item_list& list)
{
	static const indices::type n = indices::IDX_CARD_INDEX;

	containter::nth_index<n>::type& indexBy = 
		m_Container.get<n>();

	std::pair<
		containter::nth_index_iterator<n>::type, 
		containter::nth_index_iterator<n>::type
	> pair;

	containter::nth_index_iterator<n>::type iter;

	pair = indexBy.equal_range(val);
	for (iter = pair.first; iter != pair.second; iter++)
	{
		WEAK_ITEM p = const_cast<Item*>(*iter);
		list.push_back(p);
	}
	return list.size();
}


WEAK_ITEM Inventory::find(CARD_INDEX CardIndex, Enum::Storage::Type StorageType, SLOT_NO SlotNo)
{
	static const indices::type n = indices::IDX_COMP_CARD_STORAGE_SLOT;

	containter::nth_index<n>::type& indexBy = 
		m_Container.get<n>();

	containter::nth_index_iterator<n>::type iter = 
		indexBy.find(boost::make_tuple(CardIndex, StorageType, SlotNo));

	if (indexBy.end() != iter)
		return const_cast<Item*>(*iter);

	return NULL;
}


///< EQUIP는 계정에 unique가 아님. 그래서 첫 번째 파라미터에 EQUIPPED를 사용할 수 없음
WEAK_ITEM Inventory::find(Enum::Storage::Type val, SLOT_NO SlotNo)
{
	static const indices::type n = indices::IDX_COMP_STORAGE_SLOT;

	containter::nth_index<n>::type& indexBy = 
		m_Container.get<n>();

	containter::nth_index_iterator<n>::type iter = 
		indexBy.find(boost::make_tuple(val, SlotNo));

	if (indexBy.end() != iter)
		return const_cast<Item*>(*iter);

	return NULL;
}



} // namespace NW