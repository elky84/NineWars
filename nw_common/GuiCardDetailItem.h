#pragma once

#include "GuiCard.h"
#include "GuiButton.h"
#include "GuiPlaceholderItem.h"
#include "GuiButtonItem.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiCardDetailItem
	: public GuiCard
{
public:
	typedef boost::function<void(int, int)> DROP_ITEM_CALLBACK;

public:
	GuiCardDetailItem();

	virtual ~GuiCardDetailItem();

	virtual bool Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, light::POSITION_INT Pos);

	virtual void Set();

	virtual void Release();

	virtual void SetCard(WEAK_CARD Card);

	std::vector<GuiPlaceholderItem>& EquipSlot();

	std::vector<GuiButtonItem>& EquipItem();

private:
	std::vector<GuiPlaceholderItem> m_EquipSlot;

	std::vector<GuiButtonItem> m_EquipItems;
};

} //namespace NW
