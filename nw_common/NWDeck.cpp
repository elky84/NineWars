#include "stdafx.h"
#include "NWDeck.h"

#include "NWCard.h"

namespace NW
{

Deck::Deck()
{

}

Deck::~Deck()
{

}

bool Deck::insert(Card* card)
{
	if(card == NULL)
	{
		LOG_ERROR(_T("Cannot insert object | src Card is null"));
		return false;
	}

	pair_value pair = m_Container.insert(card);
	if (pair.second == false)
	{
		LOG_ERROR(_T("Cannot insert object | Index[%d]"), card->GetIndex());
        SAFE_DELETE(card);
		return false;
	}

	return true;
}


bool Deck::erase(IN const CARD_INDEX val)
{
	static const indices::type n = indices::IDX_INDEX;

	containter::nth_index<n>::type& indexBy = m_Container.get<n>();
	containter::nth_index_iterator<n>::type it = indexBy.find(val);
	if (indexBy.end() == it)
		return false;

	m_Container.erase(it);
	return true;
}

bool Deck::update(WEAK_CARD card)
{
	Card* temp = card.get();

	static const indices::type n = indices::IDX_INDEX;
	containter::nth_index<n>::type& indexBy = m_Container.get<n>();
	containter::nth_index_iterator<n>::type it = indexBy.find(card->GetIndex());
	if (indexBy.end() == it)
		return false;

	m_Container.erase(it);

	pair_value pair = m_Container.insert(temp);
	if (pair.second == false)
	{
		LOG_ERROR(_T("Cannot insert object | Index[%d]"), temp->GetIndex());
		return false;
	}

	return true;
}

WEAK_CARD Deck::find( IN const CARD_INDEX val)
{
	static const indices::type n = indices::IDX_INDEX;

	containter::nth_index<n>::type& indexBy = m_Container.get<n>();
	containter::nth_index_iterator<n>::type it = indexBy.find(val);
	if (indexBy.end() == it)
	{
		LOG_DEBUG(_T("not find Card | Value[%d]"), val);
		return NULL;
	}

	return const_cast<Card*>(*it);
}

size_t Deck::find( IN const Enum::Locate::Type val, card_list& list )
{
	static const indices::type n = indices::IDX_COMP_LOCATE;

	containter::nth_index<n>::type& indexBy = m_Container.get<n>();

	std::pair<
		containter::nth_index_iterator<n>::type, 
		containter::nth_index_iterator<n>::type
	> pair;

	containter::nth_index_iterator<n>::type iter;

	pair = indexBy.equal_range(val);
	for (iter = pair.first; iter != pair.second; iter++)
	{
		WEAK_CARD p = const_cast<Card*>(*iter);
		list.push_back(p);
	}
	return list.size();
}


WEAK_CARD Deck::find( Enum::Locate::Type val, SLOT_NO SlotNo )
{
	static const indices::type n = indices::IDX_COMP_LOCATE_SLOT;

	containter::nth_index<n>::type& indexBy = m_Container.get<n>();

	containter::nth_index_iterator<n>::type iter = 
		indexBy.find(boost::make_tuple(val, SlotNo));

	if (indexBy.end() != iter)
		return const_cast<Card*>(*iter);

	return NULL;
}

size_t Deck::get_list(card_list& list)
{
	for each(auto& val in m_Container)
	{
		list.push_back(const_cast<Card*>(val));
	}
	return list.size();
}

size_t Deck::size()
{
	return m_Container.size();
}

} // namespace NW