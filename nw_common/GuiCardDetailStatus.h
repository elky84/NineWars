#pragma once

#include "GuiCard.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiCardDetailStatus
	: public GuiCard
{
public:
	GuiCardDetailStatus();

	virtual ~GuiCardDetailStatus();

	virtual void OnDraw();
};

} //namespace NW
