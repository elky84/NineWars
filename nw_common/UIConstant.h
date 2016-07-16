#pragma once

#include "INILoader.h"
#include "Singleton.h"

namespace NW
{

class UIConstant
	: public light::INI::Data
{

public:
	bool Load()
	{
		return m_parser.load(_T(".\\INI\\UI.ini"));
	}
};

__declspec(selectany) UIConstant UIConstantData;

} // namespace NW