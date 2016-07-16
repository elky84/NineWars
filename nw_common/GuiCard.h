#pragma once

#include "Gui.h"
#include "NWTypeDefinition.h"

namespace NW
{

class GuiCard
	: public light::view::Gui
{
public:
	GuiCard();

	virtual ~GuiCard();

	virtual bool Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, light::POSITION_INT Pos);

	virtual void SetPlayer(WEAK_PLAYER Player);

	virtual void SetCard(WEAK_CARD Card);

	WEAK_CARD GetCard() const;

	virtual void OnLogic();

protected:
	WEAK_PLAYER m_Player;

	WEAK_CARD m_Card;
};

} //namespace NW
