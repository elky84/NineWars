#pragma once

#include "GuiButton.h"

#include "NWTypeDefinition.h"

namespace NW
{

class GuiButtonItem 
	: public light::view::GuiButton
{
public:
	GuiButtonItem();

	virtual ~GuiButtonItem();

	bool Create(light::weak_raw_ptr<light::view::DirectX> pDirectX, WEAK_ITEM item, const std::wstring& file_name, const std::wstring& strTextureName, light::POSITION_INT Pos,  Gui::Callback callback = NULL, const TCHAR* szClickSound = NULL,  const TCHAR* szOverSound = NULL);

	WEAK_ITEM GetItem() const;

protected:
	virtual void AppenderProcess();

private:
	WEAK_ITEM m_Item;
};

} //namespace NW
