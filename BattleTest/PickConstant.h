#pragma once

#include "INILoader.h"
#include "Singleton.h"

namespace NW
{

class PickConstant
	: public light::INI::Data
{

public:
	bool Load()
	{
		return m_parser.load(_T(".\\INI\\Pick.ini"));
	}
};

__declspec(selectany) PickConstant PickConstantData;

} // namespace NW