#pragma once

#include "NWTypeDefinition.h"
#include "GuiImage.h"
#include "GuiProgressBar.h"

namespace NW
{

class GuiCardStatus 
	: public light::view::Gui
{
public:
	struct IMAGE
	{
		enum Type
		{
			NONE = -1,
			CHARACTER_OUTLINE = 0,
			CHARACTER,
			CLASS,
			SKILL_1,
			SKILL_2,
			SKILL_3,
			HP_OUTLINE,
			MAX,
		};
	};

public:
	GuiCardStatus();

	virtual ~GuiCardStatus();

	bool Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_CARD card, const std::wstring& file_name, light::POSITION_INT Pos, light::view::Gui::Direction::Type direction);

	WEAK_CARD GetCard() const;

	virtual void Set();

	virtual void Release();

protected:
	virtual light::view::GUI_STATE::Type Check();

	virtual void AppenderProcess();

	virtual void OnLogic();

	virtual void OnDraw();

private:
	WEAK_CARD m_Card;

	light::view::GuiImage m_Image[IMAGE::MAX];

	light::view::GuiImage m_CharacterDead;

	light::view::GuiProgressBar m_HP;

	light::view::Gui::Direction::Type m_Direction;
};

} //namespace NW
