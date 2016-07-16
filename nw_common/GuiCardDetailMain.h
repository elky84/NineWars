#pragma once

#include "GuiCard.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiCardDetailMain
	: public GuiCard
{
public:
	GuiCardDetailMain();

	virtual ~GuiCardDetailMain();

	virtual void OnDraw();

	virtual void SetCard(WEAK_CARD Card);

private:
	light::view::Sprite2D m_sprite;
};

} //namespace NW
