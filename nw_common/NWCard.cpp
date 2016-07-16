#include "stdafx.h"
#include "NWCard.h"

#include "MetaData.h"

#include "NWDecide.h"
#include "NWFormula.h"
#include "NWSquad.h"
#include "NWAction.h"
#include "NWItem.h"

#include "DirectX.h"

#include "UIConstant.h"

namespace NW
{

Card::Card(light::weak_raw_ptr<light::view::DirectX> directX, const CARD_INDEX index)
	: m_Index(index)
	, m_Level(DEFAULT_LEVEL)
	, m_HP(0)
	, m_MaxHP(0)
	, m_direct_x(directX)
	, m_Team(TEAM::NONE)
	, m_Delay(0)
	, m_ButtonIndex(0)
	, m_LoadAnimation(false)
	, m_SlotNo(0)
	, m_Locate(Enum::Locate::NONE)
	, m_RelationPoint(0)
	, m_Height(0)
	, m_Width(0)
    , m_Character(new ExcelData::Character)
{
	memset(&m_Direction, 0, sizeof(m_Direction));
	memset(&m_CharacterStat, 0, sizeof(m_CharacterStat));
}

Card::Card()
	: m_Index(0)
	, m_Level(DEFAULT_LEVEL)
	, m_HP(0)
	, m_MaxHP(0)
	, m_Team(TEAM::NONE)
	, m_Delay(0)
	, m_ButtonIndex(0)
	, m_LoadAnimation(false)
	, m_SlotNo(0)
	, m_Locate(Enum::Locate::NONE)
	, m_RelationPoint(0)
	, m_Height(0)
	, m_Width(0)
    , m_Character(new ExcelData::Character)
{
	memset(&m_Direction, 0, sizeof(m_Direction));
	memset(&m_CharacterStat, 0, sizeof(m_CharacterStat));
}

Card::~Card()
{
	if(m_Action.get() )
	{
		m_Action->SetCard(NULL);
	}
}

void Card::GuiSet()
{
	m_ProgressBar.Set();
}

void Card::SetTeam(TEAM::type team, INT index)
{
	m_Team = team;
	m_ButtonIndex = index;
	if(team == TEAM::RED)
	{
		m_ProgressBar.Create(m_direct_x, _T(".\\Gui\\ProgressBar\\ProgressBar_Red.spr"), light::POSITION_INT(), 100, 2);
		m_Direction.x = 1.0f;
	}
	else
	{
		m_ProgressBar.Create(m_direct_x, _T(".\\Gui\\ProgressBar\\ProgressBar_Blue.spr"), light::POSITION_INT(), 100, 2);
		m_Direction.x = -1.0f;
	}

	m_ProgressBar.SetProgress(1, 100.0f);
}

std::wstring Card::EquipEffect()
{
	std::wstringstream stream;
	stream << _T("공격력:") << Damage() << _T("\n")
		<< _T("물방:") << m_CharacterStat.AdDefense() << _T("\n")
		<< _T("명중률:") << m_CharacterStat.AttackRate() << _T("\n")
		<< _T("마방:") << m_CharacterStat.ApDefense() << _T("\n")
		<< _T("공속:") << m_CharacterStat.AttackSpeed() << _T("\n")
		<< _T("사거리:") << m_CharacterStat.Range();
	return stream.str();
}

void Card::CalcuateEquipEffect(Inventory::item_list& list)
{
	for each( auto item in list)
	{
		m_CharacterStat.AdDefense( m_CharacterStat.AdDefense() + item->Info()->AC());
		m_CharacterStat.ApDefense( m_CharacterStat.ApDefense() + item->Info()->MR());

		if(Formula::DAMAGE_TYPE(Class()) == DAMAGE::AD )
			m_CharacterStat.AdDamage(m_CharacterStat.AdDamage() + item->Info()->Damage());
		else
			m_CharacterStat.ApDamage(m_CharacterStat.ApDamage() + item->Info()->Damage());

		m_CharacterStat.AttackRate(m_CharacterStat.AttackRate() + item->Info()->AttackRate());
		m_CharacterStat.AttackSpeed(m_CharacterStat.AttackSpeed() + item->Info()->AttackSpeed());
		m_CharacterStat.Range(m_CharacterStat.Range() + item->Info()->Range());
	}
}

void Card::SetCharacter(ExcelData::Character& _character)
{
	*m_Character = _character;
	m_MaxHP = Formula::HP( Class());
	m_HP = m_MaxHP;

	m_vectorSkill.resize( m_Character->VectorSkill().size() );
	m_vectorSkill[0].Set(&light::excel::Loader::Instance()->find<ExcelData::SkillData>()->Map()[m_Character->VectorSkill().at(0)]);
	m_vectorSkill[1].Set(&light::excel::Loader::Instance()->find<ExcelData::SkillData>()->Map()[m_Character->VectorSkill().at(1)]);
	m_vectorSkill[2].Set(&light::excel::Loader::Instance()->find<ExcelData::SkillData>()->Map()[m_Character->VectorSkill().at(2)]);
}

bool Card::LoadAnimation()
{
	if(m_LoadAnimation)
	{
		return true;
	}

	auto& mapAnimation = light::excel::Loader::Instance()->find<ExcelData::ClassAnimationData>()->Map();
	int at = m_Character->Index();
	if( false == m_Move.Load(m_direct_x, mapAnimation[at].Move()) )
	{
		return false;
	}

	if( false == m_Attack.Load(m_direct_x, mapAnimation[at].Attack()) )
	{
		return false;
	}

	if( false == m_Idle.Load(m_direct_x, mapAnimation[at].Idle()) )
	{
		return false;
	}

	m_Move.Stop();
	m_Attack.Stop();
	m_LoadAnimation = true;

	m_Width = mapAnimation[at].Width();
	m_Height = mapAnimation[at].Height();

	auto& mapClassEffect = light::excel::Loader::Instance()->find<ExcelData::ClassEffectData>()->Map();
	m_AttackEffect.Load(mapClassEffect[Class()].Attack());
	m_DamageEffect.Load(mapClassEffect[Class()].Damage());
	return true;
}

void Card::MoveAnimation()
{
	m_Move.Play();
}

void Card::MoveEndAnimation()
{
	m_Move.Stop();
}

void Card::AttackAnimation()
{
	m_Move.reset();
	m_Move.Stop();
	m_Attack.reset();
	m_Attack.Play();
}

INT Card::Damage() const
{
	if(Formula::DAMAGE_TYPE(Class()) == DAMAGE::AD )
		return m_CharacterStat.AdDamage();
	else
		return m_CharacterStat.ApDamage();
}

AttackInformation Card::Damage(DAMAGE::Type type, float damage)
{
	float real = 0.0f;
	if(type == DAMAGE::AD)
	{
		float fReduce = Formula::AD_REDUCE(Formula::AD_DEFENSE( Class() ), Class()) / 100.0f;
		real = damage * fReduce;
	}
	else if(type == DAMAGE::AP)
	{
		float fReduce = Formula::AD_REDUCE(Formula::AP_DEFENSE( Class() ), Class()) / 100.0f;
		real = damage * fReduce;
	}

	if( real <= 1.0f)
	{
		real = 1.0f;
	}

	m_HP -= real;
	m_ProgressBar.SetProgress(1, 100.0f * (m_HP / m_MaxHP));

	bool bDead = false;
	if(m_HP <= 0.0f)
	{
		m_HP = 0.0f;
		m_Squad->Die(this);
		bDead = true;
		m_ProgressBar.Release();
	}

	return AttackInformation(damage, type, bDead);
}

static const int FONT_SIZE = 10;

void Card::DrawLoop(light::view::Animation2D& animation, const light::POSITION_INT& Position, bool Mirror, bool FrameUpdate)
{
	animation.Position(Position);
	animation.Draw(Mirror);
	if(FrameUpdate)
		animation.DrawLoop(Mirror);
	else
		animation.Draw(Mirror);
}

void Card::Draw(const light::POSITION_INT& Position, bool FrameUpdate)
{
	if( m_HP <= 0.0f )
	{
		return;
	}

	m_ProgressBar.SetPosition(Position + light::POSITION_INT( light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CHARACTER.PROGRESSBAR_X"), light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CHARACTER.PROGRESSBAR_Y") ));

	bool Mirror = false;
	if( light::LookAtToDegree(Direction().x, Direction().y) <= 180.0f)
	{
		Mirror = true;
	}

	if( m_Attack.NowPlaying() )
	{
		m_Attack.Update();
		DrawLoop(m_Attack, Position, Mirror, false);
	}
	else if(m_Move.NowPlaying())
	{
		DrawLoop(m_Move, Position, Mirror, FrameUpdate);		
	}
	else
	{
		DrawLoop(m_Idle, Position, Mirror, FrameUpdate);
	}

	m_direct_x->DrawString(Name(), Position + light::POSITION_INT(light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CHARACTER.CARDNAME_X"), light::INI::Loader::Instance()->find<UIConstant>()->get<int>("CHARACTER.CARDNAME_Y") ), FONT_SIZE);
}

void Card::PostDelay()
{
	m_Delay = m_Character->PostDelay();
}

void Card::PostDelay(INT Delay)
{
	m_Delay = Delay;
}

void Card::PreDelay()
{
	m_Delay = m_Character->PreDelay();
	MoveEndAnimation();
}

void Card::PreDelay(INT Delay)
{
	m_Delay = Delay;
	MoveEndAnimation();
}

bool Card::isDelay()
{
	return 0 < m_Delay;
}

float Card::Range()
{
	return m_CharacterStat.Range() * (CHARACTER_SIZE / 1.5f);
}

void Card::SetDisposition(const light::POSITION_INT& position)
{
	SetPosition(light::POSITION_FLOAT(position.X() * 64.0f + 64.0f, position.Y() * (64.0f * 2) + 64.0f));
	m_Disposition = position;
}

void Card::SetRelationPoint(const INT Point)
{
	m_RelationPoint = Point;
}

void Card::CalcAddStat()
{
	TCHAR alphabet = _T('A');
	for(int i = 0; i < m_Disposition.X(); ++i)
		++alphabet;

	std::wstringstream stream;
	stream << alphabet << m_Disposition.Y();

	auto& mapDisposition = light::excel::Loader::Instance()->find<ExcelData::DispositionData>()->Map();
	ExcelData::Disposition& disposition = mapDisposition[stream.str()];

	m_CharacterStat.AdDamage(m_CharacterStat.AdDamage() + disposition.AdDamage());
	m_CharacterStat.ApDamage(m_CharacterStat.ApDamage() + disposition.ApDamage());
	m_CharacterStat.AdDefense(m_CharacterStat.AdDefense() + disposition.AdDefense());
	m_CharacterStat.ApDefense(m_CharacterStat.ApDefense() + disposition.ApDefense());
	m_CharacterStat.Speed( m_Character->Speed() + m_CharacterStat.Speed() + disposition.Speed());
	m_CharacterStat.AttackTendency( m_Character->AttackTendency() + m_CharacterStat.AttackTendency() + disposition.AttackTendency());
	m_CharacterStat.Boldness( m_Character->Boldness() + m_CharacterStat.Boldness() + disposition.Boldness());
	m_CharacterStat.Prediction( m_Character->Prediction() + m_CharacterStat.Prediction() + disposition.Prediction());
	m_CharacterStat.DefenseTendency( m_Character->DefenseTendency() + m_CharacterStat.DefenseTendency() + disposition.DefenseTendency());
	m_CharacterStat.Aggressive( m_Character->Aggressive() + m_CharacterStat.Aggressive() + disposition.Competitive());
	m_CharacterStat.Concentration( m_Character->Concentration() + m_CharacterStat.Concentration() + disposition.Concentration());
	m_CharacterStat.Calm( m_Character->Calm() + m_CharacterStat.Calm() + disposition.Calm());
	m_CharacterStat.Judgement( m_Character->Judgement() + m_CharacterStat.Judgement() + disposition.Judgement());
	m_CharacterStat.Leadership( m_Character->Leadership() + m_CharacterStat.Leadership() + disposition.Leadership());
	m_CharacterStat.TeamWork( m_Character->TeamWork() + m_CharacterStat.TeamWork() + disposition.TeamWork());
	m_CharacterStat.Tactical( m_Character->Tactical() + m_CharacterStat.Tactical() + disposition.Tactical());

	auto& mapRelation = light::excel::Loader::Instance()->find<ExcelData::RelationEffectData>()->Map();
	for each(auto& val in mapRelation)
	{
		const ExcelData::RelationEffect& effect = val.second;
		if( effect.Min() <= m_RelationPoint &&
			m_RelationPoint <= effect.Max())
		{
			m_CharacterStat.AdDamage( (INT)(m_CharacterStat.AdDamage() * (effect.Effect() / 100.0f)) );
			m_CharacterStat.ApDamage( (INT)(m_CharacterStat.ApDamage() * (effect.Effect() / 100.0f)) );
			m_CharacterStat.AdDefense( (INT)(m_CharacterStat.AdDefense() * (effect.Effect() / 100.0f)) );
			m_CharacterStat.ApDefense( (INT)(m_CharacterStat.ApDefense() * (effect.Effect() / 100.0f)) );
		}
	}

	m_CharacterStat.AdDamage( std::max(1, m_CharacterStat.AdDamage()) );
	m_CharacterStat.ApDamage( std::max(1, m_CharacterStat.ApDamage()) );
}

void Card::PlayAttack()
{
	m_AttackEffect.Play();
}

void Card::PlayDamage()
{
	m_DamageEffect.Play();
}

} // namespace NW