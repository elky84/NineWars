#pragma once

#include "Sprite2D.h"
#include "GuiButton.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiButtonCard 
	: public light::view::GuiButton
{
public:
	GuiButtonCard();

	virtual ~GuiButtonCard();

	bool Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_CARD card, const std::wstring& file_name, light::POSITION_INT Pos,  Gui::Callback callback = NULL,  const TCHAR* szClickSound = NULL,  const TCHAR* szOverSound = NULL);

	WEAK_CARD GetCard() const;

	void SetCard(WEAK_CARD card);

	virtual void OnDraw();

	virtual void Set();

protected:
	virtual void AppenderProcess();

private:
	void Draw(const light::POSITION_INT& Position, const float Alpha);

private:
	WEAK_CARD m_Card;

	light::view::Sprite2D m_Name;

	light::view::Sprite2D m_Star;

	light::view::Sprite2D m_Character;

	light::view::Sprite2D m_Class;

	light::view::Sprite2D m_Group;
};

} //namespace NW
