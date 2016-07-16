#include "stdafx.h"
#include "NWFormula.h"

#include "MetaData.h"

#include "Random.hpp"

namespace NW
{

Formula::Formula()
{

}

Formula::~Formula()
{

}

float Formula::HP(const INT Class)
{
	auto& mapHP = light::excel::Loader::Instance()->find<ExcelData::HPData>()->Map();
	return (float)mapHP[Class].Point();
}

DAMAGE::Type Formula::DAMAGE_TYPE(const INT Class)
{
	auto& mapDamageType = light::excel::Loader::Instance()->find<ExcelData::DamageTypeData>()->Map();
	return (DAMAGE::Type)(mapDamageType[Class].Type());
}

float Formula::AD_DAMAGE(const INT Class)
{
	auto& mapAdDamage = light::excel::Loader::Instance()->find<ExcelData::AdDamageData>()->Map();
	return (float)(rand() % mapAdDamage[Class].Max() + mapAdDamage[Class].Min());
}

float Formula::AP_DAMAGE(const INT Class)
{
	auto& mapApDamage = light::excel::Loader::Instance()->find<ExcelData::ApDamageData>()->Map();
	return (float)(rand() % mapApDamage[Class].Max() + mapApDamage[Class].Min());
}

int Formula::AD_DEFENSE(const INT Class)
{
	auto& mapAdDefense = light::excel::Loader::Instance()->find<ExcelData::AdDefenseData>()->Map();
	return mapAdDefense[Class].Point();
}
 
int Formula::AP_DEFENSE(const INT Class)
{
	auto& mapApDefense = light::excel::Loader::Instance()->find<ExcelData::ApDefenseData>()->Map();
	return mapApDefense[Class].Point();
}

float Formula::AD_REDUCE(const int AdDefense, const INT Class)
{
	auto& mapAdReduce = light::excel::Loader::Instance()->find<ExcelData::AdReduceData>()->Map();
	return mapAdReduce[AdDefense].Reduce();
}

float Formula::AP_REDUCE(const int ApDefense, const INT Class)
{
	auto& mapApReduce = light::excel::Loader::Instance()->find<ExcelData::ApReduceData>()->Map();
	return mapApReduce[ApDefense].Reduce();
}

} // namespace NW