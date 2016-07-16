#pragma once

#include "Mode.h"

#include "SetupUI.h"
#include "CardUI.h"

#include "GuiButtonCard.h"
#include "GuiButtonCardDetail.h"

#include "GuiTooltip.h"
#include "GuiImage.h"

#include "GuiPlaceholderItem.h"

#include "GuiCardDetailBG.h"
#include "GuiCardDetailItem.h"
#include "GuiCardDetailMain.h"
#include "GuiCardDetailStatus.h"

namespace NW
{

class CharacterSettingMode 
	: public SetupUI
	, public CardUI
{
private:
	struct Direction
	{
		enum Type
		{
			NONE = -1,
			LEFT_NONE = 0,
			LEFT_FRONT,
			LEFT_BACK,
			RIGHT_NONE,
			RIGHT_FRONT,
			RIGHT_BACK,
			MAX,
		};
	};

public:
	CharacterSettingMode(light::weak_raw_ptr<light::view::DirectX> pDirectX);

	virtual ~CharacterSettingMode();

	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	virtual void Save();

private:
	virtual bool OnClickCardImpl(GuiButtonCard* Card);

	virtual bool OnDropCardImpl(SLOT_NO SlotNo);

private:
	bool OnClickCardDetail(Direction::Type direction);

	bool FlipCardDetail(Direction::Type direction);

	bool OnDropEquipItem(int x, int y);

	bool OnDropItem(int x, int y);

private:
	light::view::Sprite2D m_BG;
	light::view::Sprite2D m_BGInventory;

	GuiButtonCardDetail m_CardDetail[Direction::MAX];

	GuiCardDetailBG m_DetailBG;
	GuiCardDetailItem m_DetailItem;
	GuiCardDetailMain m_DetailMain;
	GuiCardDetailStatus m_DetailStatus;

	std::vector<GuiPlaceholderItem> m_ItemHolder;
	std::vector<GuiButtonItem> m_Items;
};

} // namespace NW