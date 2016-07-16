#pragma once

#include "NWTypeDefinition.h"

namespace NW
{

namespace Util
{

namespace Math
{

D3DXVECTOR3 LookAt(const light::POSITION_FLOAT& pos, const float Gap);

D3DXVECTOR3 LookAt(const light::POSITION_FLOAT& Src, const light::POSITION_FLOAT& Dest);

float PositionGap(const light::POSITION_FLOAT& Src, const light::POSITION_FLOAT& Dest);


} // namespace Math

} // namespace Util

} // namespace NW