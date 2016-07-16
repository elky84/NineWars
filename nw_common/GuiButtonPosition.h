#pragma once

#include "GuiButton.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiButtonPosition
	: public light::view::GuiButton
{
public:
	GuiButtonPosition();

	virtual ~GuiButtonPosition();

	bool Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_CARD card, const std::wstring& file_name, const std::wstring& strTextureName, light::POSITION_INT Pos,  Gui::Callback callback = NULL, const TCHAR* szClickSound = NULL,  const TCHAR* szOverSound = NULL);

	WEAK_CARD GetCard() const;
	
	virtual void OnDraw();

	void Draw(const light::POSITION_INT& Position, const float Alpha);

protected:
	virtual void AppenderProcess();

private:
	WEAK_CARD m_Card;
};

} //namespace NW
