#include "stdafx.h"
#include "NWUtil.h"

namespace NW
{

namespace Util
{

namespace Math
{

	D3DXVECTOR3 LookAt(const light::POSITION_FLOAT& pos, const float Gap)
	{
		return D3DXVECTOR3(pos.X() / Gap, pos.Y() / Gap, 0);
	}

	D3DXVECTOR3 LookAt(const light::POSITION_FLOAT& Src, const light::POSITION_FLOAT& Dest)
	{
		const light::POSITION_FLOAT TargetPos = Dest - Src;
		float Gap = PositionGap(Src, Dest);
		return D3DXVECTOR3(TargetPos.X() / Gap, TargetPos.Y() / Gap, 0);
	}

	float PositionGap(const light::POSITION_FLOAT& Src, const light::POSITION_FLOAT& Dest)
	{
		const light::POSITION_FLOAT TargetPos = Dest - Src;
		return sqrt((TargetPos.X() * TargetPos.X()) + (TargetPos.Y() * TargetPos.Y()));
	}

} // namespace Math

} // namespace Util

} // namespace NW