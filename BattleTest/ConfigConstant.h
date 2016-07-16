#pragma once

#include "INILoader.h"
#include "Singleton.h"

namespace NW
{

class ConfigConstant
	: public light::INI::Data
{
public:
	virtual bool Load()
	{
		return m_parser.load(_T(".\\INI\\Config.ini"));
	}
};

__declspec(selectany) ConfigConstant ConfigConstantData;

} // namespace NW