#pragma once

#include "GuiCard.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiCardDetailBG
	: public GuiCard
{
public:
	GuiCardDetailBG();

	virtual ~GuiCardDetailBG();

	virtual void OnDraw();
};

} //namespace NW
