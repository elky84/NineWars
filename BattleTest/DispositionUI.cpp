#include "stdafx.h"
#include "DispositionUI.h"

#include "UIConstant.h"
#include "FileUtil.h"

#include "boost/bind.hpp"

namespace NW
{

DispositionUI::DispositionUI()
{
}

DispositionUI::~DispositionUI()
{

}

void DispositionUI::Show(light::weak_raw_ptr<light::view::DirectX> pDirectX, Deck::card_list& list, const light::POSITION_INT& Adjust /* = light::POSITION_INT */)
{
	INT POSITION_PLACEHOLDER_INTERVAL = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_INTERVAL");
	m_BGDisposition.Create(pDirectX, _T(".\\Gui\\Common\\BGDisposition.spr"), light::POSITION_INT(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_START_X") - POSITION_PLACEHOLDER_INTERVAL, light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_START_Y") - POSITION_PLACEHOLDER_INTERVAL) - Adjust );
	m_BGGraph.Create(pDirectX, _T(".\\Gui\\Disposition\\BGGraph.spr"), light::POSITION_INT(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("DISPOSITION.GRAPH_BG_X"), light::INI::Loader::Instance()->find<UIConstant>()->get<int>("DISPOSITION.GRAPH_BG_Y")) - Adjust );

	m_position_holder.resize( light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH") * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_HEIGHT") );

	{
		// 스쿼드 GUI 세팅
		light::POSITION_INT Position(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("SQUAD.PLACEHOLDERS_X"), light::INI::Loader::Instance()->find<UIConstant>()->get<int>("SQUAD.PLACEHOLDERS_Y"));
		Position -= Adjust;
		for(size_t n = 0; n < MAX_SQUAD_CARD; ++n)
		{
			m_squad_holder[n].Create(pDirectX, _T(".\\Gui\\Card\\Template.spr"), _T("BG.png"), Position, boost::bind(&DispositionUI::OnDropSquadCard, this, n));
			Position.X(Position.X() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("SQUAD.PLACEHOLDERS_X_INTERVAL"));
		}
	}


	{
		// 포지션 GUI 세팅
		light::POSITION_INT Position(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_START_X"), light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_START_Y"));
		Position -= Adjust;

		for(int y = 0; y < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_HEIGHT"); ++y)
		{
			for(int x = 0; x < light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH"); ++x)
			{
				m_position_holder[y * light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH") + x].Create(pDirectX, _T(".\\Gui\\Disposition\\Position.spr"), Position);

				Position.X(Position.X() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_X_INTERVAL"));
			}

			Position.X(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_START_X"));
			Position.X(Position.X() - Adjust.X());

			Position.Y( Position.Y() + light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_Y_INTERVAL"));
		}
	}

	m_squad_cards.resize(MAX_SQUAD_CARD);

	m_GraphIcon.Load(pDirectX, _T(".\\Gui\\Disposition\\GraphPoint.spr"));

	m_BGGraph.Set();
	m_BGDisposition.Set();

	for(size_t n = 0; n < _countof(m_squad_holder); ++n)
	{
		m_squad_holder[n].Set();
		m_squad_holder[n].Link(NULL);
		m_squad_cards[n].Create(pDirectX, NULL, _T(".\\Gui\\CardMini\\BG.spr"), m_squad_holder[n].GetPosition());
	}

	for( size_t n = 0; n < m_position_holder.size(); ++n )
	{
		m_position_holder[n].Set();
	}

	for(size_t n = 0; n < list.size(); ++n)
	{
		SLOT_NO SlotNo = list[n]->SlotNo();

		m_squad_cards[SlotNo].SetCard(list[n]);
		m_squad_cards[SlotNo].Set();
		m_squad_holder[SlotNo].Link(&m_squad_cards[SlotNo]);

		light::POSITION_INT& Disposition = list[n]->GetDisposition();
		INT AtFormation = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("POSITION.PLACEHOLDER_WIDTH") * Disposition.Y() + Disposition.X();

		std::wstring strThumbnail = list[n]->Thumbnail();
		strThumbnail.erase(strThumbnail.begin(), strThumbnail.begin() + 2);
		m_position_card[SlotNo].Create(pDirectX, list[n], _T(".\\Character\\template_position.spr"), light::get_file_name_without_ext(list[n]->Thumbnail()) + _T("\\ANI_CH_IDLE_00") + strThumbnail, m_position_holder[AtFormation].GetPosition());
		m_position_holder[AtFormation].Append(&m_position_card[SlotNo]);
		m_position_card[SlotNo].Set();
	}
}

bool DispositionUI::OnDropSquadCard(SLOT_NO n)
{
	return OnDropSquadCardImpl(n);
}

void DispositionUI::CalcGraph()
{
	m_RelationPoint.clear();
	m_RelationPoint.resize(MAX_SQUAD_CARD);
	for(size_t n = 0; n < _countof(m_squad_holder); ++n)
	{
		if(m_squad_holder[n].AppendPtr().get())
		{
			light::weak_raw_ptr<GuiButtonCard> pCurrent = light::view::Gui::Find(m_squad_holder[n].AppendPtr(), m_squad_cards);

			int LeftAt = (n + MAX_SQUAD_CARD - 1) % MAX_SQUAD_CARD;
			int RightAt = (n + MAX_SQUAD_CARD + 1) % MAX_SQUAD_CARD;

			light::weak_raw_ptr<GuiButtonCard> pLeftCard = light::view::Gui::Find(m_squad_holder[LeftAt].AppendPtr(), m_squad_cards);
			int Point = RelationPoint(pCurrent, pLeftCard);

			light::weak_raw_ptr<GuiButtonCard> pRightCard = light::view::Gui::Find(m_squad_holder[RightAt].AppendPtr(), m_squad_cards);
			Point += RelationPoint(pCurrent, pRightCard);

			// 두명에 대해 검사했으므로, 2로 나눔.
			Point /= 2;

			m_RelationPoint[n] = Point;
			pCurrent->GetCard()->SetRelationPoint(Point);
		}
	}
}

void DispositionUI::DrawGraph(const light::POSITION_INT& Adjust)
{
	// BG Graph의 X가 시작점
	// BG Graph의 Y + BG그래프 그림 크기가 Y쪽 시작점.
	// Point 만큼 Y좌표값을 -해서 그리자.
	// 빈칸은 패스~
	INT X = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("DISPOSITION.GRAPH_X");
	INT Y = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("DISPOSITION.GRAPH_Y");
	INT X_INTERVAL = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("DISPOSITION.GRAPH_X_INTERVAL");
	INT HEIGHT = light::INI::Loader::Instance()->find<UIConstant>()->get<int>("DISPOSITION.GRAPH_HEIGHT");;

	for(size_t n = 0; n < m_RelationPoint.size(); ++n)
	{
		INT Point = m_RelationPoint[n];
		float Percentage = (float)Point / MAX_RELATION_POINT;
		
		m_GraphIcon.DrawSprite(0, light::POSITION_INT(X + (X_INTERVAL * n), Y - (INT)(Percentage * HEIGHT)) - Adjust, Point / (MAX_RELATION_POINT / 3));
	}
}

int DispositionUI::RelationPoint(light::weak_raw_ptr<GuiButtonCard> pCard, light::weak_raw_ptr<GuiButtonCard> pTarget)
{
	if( pCard.get() == NULL || pTarget.get() == NULL)
	{
		return 0;
	}

	auto& mapCharacterProfile = light::excel::Loader::Instance()->find<ExcelData::CharacterProfileData>()->Map();
	auto& mapGroupRelation = light::excel::Loader::Instance()->find<ExcelData::GroupRelationData>()->Map();
	auto& mapNationRelation = light::excel::Loader::Instance()->find<ExcelData::NationRelationData>()->Map();
	auto& mapRaceRelation = light::excel::Loader::Instance()->find<ExcelData::RaceRelationData>()->Map();
	auto& mapCharacterRelation = light::excel::Loader::Instance()->find<ExcelData::CharacterRelationData>()->Map();

	auto& Profile = mapCharacterProfile[pCard->GetCard()->CharacterIndex()];

	auto& targetProfile = mapCharacterProfile[pTarget->GetCard()->CharacterIndex()];
	INT Point = 0;

	auto& RaceRelation = mapRaceRelation[Profile.Race()];
	for( size_t n = 0; n < RaceRelation.VectorRace().size(); ++n)
	{
		if(targetProfile.Race() == RaceRelation.VectorRace()[n])
		{
			Point += RaceRelation.VectorRelation()[n];
			break;
		}
	}

	auto& GroupRelation = mapGroupRelation[Profile.Group()];
	for( size_t n = 0; n < RaceRelation.VectorRace().size(); ++n)
	{
		if(targetProfile.Race() == RaceRelation.VectorRace()[n])
		{
			Point += RaceRelation.VectorRelation()[n];
			break;
		}
	}

	auto& NationRelation = mapNationRelation[Profile.Nation()];
	for( size_t n = 0; n < NationRelation.VectorNation().size(); ++n)
	{
		if(targetProfile.Nation() == NationRelation.VectorNation()[n])
		{
			Point += NationRelation.VectorRelation()[n];
			break;
		}
	}

	auto& CharacterRelation = mapCharacterRelation[pCard->GetCard()->CharacterIndex()];
	for( size_t n = 0; n < GroupRelation.VectorGroup().size(); ++n)
	{
		if(targetProfile.Group() == GroupRelation.VectorGroup()[n])
		{
			Point += GroupRelation.VectorRelation()[n];
			break;
		}
	}

	for( size_t n = 0; n < CharacterRelation.VectorCharacter().size(); ++n)
	{
		if(pTarget->GetCard()->CharacterIndex() == CharacterRelation.VectorCharacter()[n])
		{
			Point += CharacterRelation.VectorRelation()[n];
			break;
		}
	}

	return (std::min)(Point, MAX_RELATION_POINT);
}

} // namespace NW