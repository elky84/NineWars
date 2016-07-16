#pragma once

#include "ObjectPool.h"

#include "NWTypeDefinition.h"
#include "NWCard.h"

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

class Deck
{
private:
	typedef boost::multi_index::const_mem_fun<Card, CARD_INDEX, &Card::GetIndex>	idx_index;
	typedef boost::multi_index::const_mem_fun<Card, SLOT_NO, &Card::SlotNo>			idx_slot_no;
	typedef boost::multi_index::const_mem_fun<Card, Enum::Locate::Type, &Card::Locate>	idx_locate;

	typedef boost::multi_index::composite_key<Card, idx_locate, idx_slot_no>	idx_composite_locate_slot;	

	typedef struct indices : public boost::multi_index::indexed_by
		<
		boost::multi_index::ordered_unique<idx_index>,
		boost::multi_index::ordered_non_unique<idx_locate>,

		boost::multi_index::ordered_non_unique<idx_composite_locate_slot>
		>
	{
		enum type
		{
			IDX_INDEX = 0,
			IDX_COMP_LOCATE,
			IDX_COMP_LOCATE_SLOT,
			IDX_END
		};
	};

	// definition container
	typedef boost::multi_index_container<Card*, indices>	containter;
	typedef containter::iterator iter;
	typedef std::pair<iter, bool> pair_value;

public:
	typedef std::vector<WEAK_CARD> card_list;

public:
	Deck(void);

	virtual ~Deck(void);

	bool insert(Card* card);

	bool erase(IN const CARD_INDEX val);

	bool update(WEAK_CARD card);

	// 리스트는 임시로 쓰고 버려야한다.
	size_t find( Enum::Locate::Type val, card_list& list );

	WEAK_CARD find( Enum::Locate::Type val, SLOT_NO SlotNo);

	WEAK_CARD find(CARD_INDEX val);

	// 리스트는 임시로 쓰고 버려야한다.
	size_t get_list(card_list& list);

	size_t size();

private:
	containter m_Container;
};


} // namespace NW