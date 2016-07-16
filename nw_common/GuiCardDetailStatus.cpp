#include "stdafx.h"
#include "GuiCardDetailStatus.h"

#include "NWCard.h"

namespace NW
{

GuiCardDetailStatus::GuiCardDetailStatus()
{
}

GuiCardDetailStatus::~GuiCardDetailStatus()
{
}

void GuiCardDetailStatus::OnDraw()
{
	if( m_Card.get() == NULL )
		return;

	{
		std::wstringstream stream;
		stream << m_Card->Name() << _T(" ")
			<< _T("LV:") << m_Card->GetLevel();
		DrawString(stream.str(), m_position + light::POSITION_INT(30, 28), 20, D3DCOLOR_RGBA(255, 255, 255, 255));
	}

	{
		std::wstringstream stream;
		stream << _T("종족:") << _T("\n")
			<< _T("성별:")  << _T("\n")
			<< _T("직업:") << m_Card->Class();

		DrawString(stream.str(), m_position + light::POSITION_INT(30, 80), light::RECT_INT(0, 0, 240, 60), 20, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::LEFT);
	}

	{
		Instance::CharacterStat& stat = m_Card->CharacterStat();

		std::wstringstream stream;
		stream << _T("공격성향:") << stat.AttackTendency() << _T("\n")
			<< _T("대담성:") << stat.Boldness() << _T("\n")
			<< _T("예측력:") << stat.Prediction() << _T("\n")
			<< _T("방어성향:") << stat.DefenseTendency() << _T("\n")
			<< _T("적극성:") << stat.Aggressive() << _T("\n")
			<< _T("승부욕:") << stat.Competitive() << _T("\n")
			<< _T("집중력:") << stat.Concentration() << _T("\n")
			<< _T("판단력:") << stat.Judgement() << _T("\n")
			<< _T("침착함:") << stat.Calm() << _T("\n")
			<< _T("리더쉽:") << stat.Leadership() << _T("\n")
			<< _T("팀워크:") << stat.TeamWork() << _T("\n")
			<< _T("전술수행능력:") << stat.Tactical();

		DrawString(stream.str(), m_position + light::POSITION_INT(30, 150), light::RECT_INT(0, 0, 240, 180), 14, D3DCOLOR_RGBA(255, 255, 255, 255), light::view::FreeType2::Align::LEFT);
	}
}


} //namespace NW
