#pragma once

#include "NWTypeDefinition.h"

namespace light
{

namespace view
{


class DirectX;

} // namespace view

} // namespace light

namespace NW
{

class CardFactory
{
public:
	static Card* Pick(light::weak_raw_ptr<light::view::DirectX> directX);

	static Card* PickIndex(INT index, light::weak_raw_ptr<light::view::DirectX> directX);

	static Card* Pick(INT CardNo, light::weak_raw_ptr<light::view::DirectX> directX);

public:
	static size_t AllCount();

	static CARD_INDEX m_Index;
};

} // namespace NW