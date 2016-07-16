#pragma once

#include "ObjectPool.h"

#include "NWTypeDefinition.h"
#include "NWItem.h"

#if !defined(NDEBUG)
#define BOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING
#define BOOST_MULTI_INDEX_ENABLE_SAFE_MODE
#endif

#include <boost/multi_index/mem_fun.hpp>

#include <boost/multi_index_container.hpp> 
#include <boost/multi_index/tag.hpp> 
#include <boost/multi_index/indexed_by.hpp> 
#include <boost/multi_index/ordered_index.hpp> 
#include <boost/multi_index/member.hpp> 
#include <boost/multi_index/composite_key.hpp> 

namespace NW
{

class Inventory
{
private:
	typedef boost::multi_index::const_mem_fun<Item, ITEM_INDEX, &Item::Index>	idx_index;
	typedef boost::multi_index::const_mem_fun<Item, CARD_INDEX, &Item::CardIndex>	idx_card_index;
	typedef boost::multi_index::const_mem_fun<Item, SLOT_NO, &Item::SlotNo>	idx_slot_no;
	typedef boost::multi_index::const_mem_fun<Item, Enum::Storage::Type, &Item::Storage>	idx_storage;

	typedef boost::multi_index::composite_key<Item, idx_storage, idx_slot_no>	idx_composite_storage_slot;	
	typedef boost::multi_index::composite_key<Item, idx_card_index, idx_storage, idx_slot_no>	idx_composite_card_storage_slot;	

	typedef struct indices : public boost::multi_index::indexed_by
		<
		boost::multi_index::ordered_unique<idx_index>,
		boost::multi_index::ordered_non_unique<idx_card_index>,

		boost::multi_index::ordered_non_unique<idx_storage>,

		boost::multi_index::ordered_non_unique<idx_composite_storage_slot>,
		boost::multi_index::ordered_unique<idx_composite_card_storage_slot>

		>
	{
		enum type
		{
			IDX_INDEX					= 0,
			IDX_CARD_INDEX				= 1,
			IDX_COMP_STORAGE			= 2,
			IDX_COMP_STORAGE_SLOT		= 3,
			IDX_COMP_CARD_STORAGE_SLOT	= 4,

			IDX_END
		};
	};

	// definition container
	typedef boost::multi_index_container<Item*, indices>		containter;
	typedef containter::iterator							iter;
	typedef std::pair<iter, bool>							pair_value;

public:
	typedef std::vector<WEAK_ITEM> item_list;

public:
	Inventory(void);

	virtual ~Inventory(void);

	bool insert(Item* item);

	bool erase(IN const ITEM_INDEX val);

	bool update(WEAK_ITEM pItem);

	WEAK_ITEM find( IN const ITEM_INDEX val );

	// 리스트는 임시로 쓰고 버려야한다.
	size_t find( Enum::Storage::Type val, item_list& list );

	// 리스트는 임시로 쓰고 버려야한다.
	size_t find( IN const CARD_INDEX val, item_list& list );

	WEAK_ITEM find(Enum::Storage::Type val, SLOT_NO SlotNo);

	WEAK_ITEM find(CARD_INDEX CardIndex, Enum::Storage::Type StorageType, SLOT_NO SlotNo);

private:
	containter m_Container;
};


} // namespace NW