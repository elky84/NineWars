#pragma once

namespace Enum
{

class Locate
{
public:
	enum Type
	{
		NONE  = -1, // ¾øÀ½
		DECK = 0, // µ¦
		CORPS = 1, // Äß½º
		SQUAD = 2, // ½ºÄõµå
		RESERVE = 3, // ¿¹¾à
	};
};

static const std::wstring Locate_STR[] = {
		L"¾øÀ½", 
		L"µ¦", 
		L"Äß½º", 
		L"½ºÄõµå", 
		L"¿¹¾à", 
};

} // Enum

