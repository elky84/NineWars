#include "stdafx.h"
#include "NWCardFactory.h"
#include "MetaData.h"

#include "NWCard.h"

namespace NW
{

CARD_INDEX CardFactory::m_Index = 0;

Card* CardFactory::Pick(light::weak_raw_ptr<light::view::DirectX> directX)
{
    Card* card = new Card(directX, m_Index++);

	auto& Map = light::excel::Loader::Instance()->find<ExcelData::CharacterData>()->Map();
	int n = rand() % Map.size();
	auto it = Map.begin();
	for(int i = 0; i < n; ++i)
	{
		++it;
	}

	card->SetCharacter(it->second);
	return card;
}

Card* CardFactory::PickIndex(INT index, light::weak_raw_ptr<light::view::DirectX> directX)
{
    Card* card = new Card(directX, m_Index++);
	auto& Map = light::excel::Loader::Instance()->find<ExcelData::CharacterData>()->Map();

	auto it = Map.begin();
	for(int i = 0; i < index; ++i)
	{
		++it;
	}

	card->SetCharacter(it->second);
	return card;
}

Card* CardFactory::Pick(INT No, light::weak_raw_ptr<light::view::DirectX> directX)
{
	auto& Map = light::excel::Loader::Instance()->find<ExcelData::CharacterData>()->Map();
	if( Map.end() == Map.find(No))
	{
		return NULL;
	}

    Card* card = new Card(directX, m_Index++);
	card->SetCharacter(Map[No]);
	return card;
}

size_t CardFactory::AllCount()
{
	auto& Map = light::excel::Loader::Instance()->find<ExcelData::CharacterData>()->Map();
	return Map.size();
}


} // namespace NW