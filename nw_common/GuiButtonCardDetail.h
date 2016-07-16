#pragma once

#include "GuiButton.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiCard;

class GuiButtonCardDetail
	: public light::view::GuiButton
{
public:
	GuiButtonCardDetail();

	virtual ~GuiButtonCardDetail();

	bool Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, light::weak_raw_ptr<GuiCard> pGui, const std::wstring& file_name, const std::wstring& strTextureName, light::POSITION_INT Pos, Gui::Callback callback = NULL, const TCHAR* szClickSound = NULL,  const TCHAR* szOverSound = NULL);

	void SetPlayer(WEAK_PLAYER Player);

	void SetCard(WEAK_CARD Card);

	WEAK_CARD GetCard() const;

	virtual void Set();

	virtual void Release();

private:
	WEAK_PLAYER m_Player;

	WEAK_CARD m_Card;

	light::weak_raw_ptr<GuiCard> m_GuiCard;
};

} //namespace NW
