#include "stdafx.h"
#include "GuiCardDetailBG.h"

namespace NW
{

GuiCardDetailBG::GuiCardDetailBG()
{
}

GuiCardDetailBG::~GuiCardDetailBG()
{
}

void GuiCardDetailBG::OnDraw()
{
	if( m_Card.get() == NULL )
		return;

	DrawString(_T("캐릭터 배경~"), m_position + light::POSITION_INT(20, 20), 20, D3DCOLOR_RGBA(255, 255, 255, 255));
	DrawString(_T("캐릭터 코멘트~"), m_position + light::POSITION_INT(20, 370), 20, D3DCOLOR_RGBA(255, 255, 255, 255));
}

} //namespace NW
