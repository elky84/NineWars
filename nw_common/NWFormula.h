#pragma once

#include "NWTypeDefinition.h"

namespace ExcelData
{

class Character_Formula;

} // namespace ExcelData

namespace NW
{

class Formula
{
public:
	Formula();
	~Formula();

	static float HP(const INT Class);

	static DAMAGE::Type DAMAGE_TYPE(const INT Class);

	static float AD_DAMAGE(const INT Class);
	static float AP_DAMAGE(const INT Class);

	static int AD_DEFENSE(const INT Class);
	static int AP_DEFENSE(const INT Class);

	static float AD_REDUCE(const int AdDefense, const INT Class);
	static float AP_REDUCE(const int ApDefense, const INT Class);
};

} // namespace NW