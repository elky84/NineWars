#pragma once

#include "NWTypeDefinition.h"
#include <vector>
#include "MetaData.h"

#include "NWDecide.h"
#include "Animation2D.h"

#include "GuiProgressBar.h"
#include "NWInventory.h"
#include "NWSkill.h"

#include "FmodEx.h"

namespace light
{

namespace view
{

class DirectX;

} // namespace view

} // namespace light

namespace NW
{

class Card
{
public:
	static const int DEFAULT_LEVEL = 30;

public:
	typedef std::vector<WEAK_ITEM> VECTOR_ITEM;

public:
	Card(light::weak_raw_ptr<light::view::DirectX> directX, const CARD_INDEX index);

	Card();

	~Card();

	void GuiSet();

	void SetDisposition(const light::POSITION_INT& position);

	void SetRelationPoint(const INT Point);

	light::POSITION_INT& GetDisposition()
	{
		return m_Disposition;
	}

	void SetPosition(const light::POSITION_FLOAT& position)
	{
		m_Position = position;
	}

	light::POSITION_FLOAT& GetPosition()
	{
		return m_Position;
	}

	void SetTeam(TEAM::type team, BUTTON_INDEX index);

	TEAM::type GetTeam()
	{
		return m_Team;
	}

	float X() const
	{
		return m_Position.X();
	}

	float Y() const
	{
		return m_Position.Y();
	}

	bool isDelay();

	void CalcuateEquipEffect(Inventory::item_list& list);

	std::wstring EquipEffect();

	void SetSquad(WEAK_SQUAD squad)
	{
		m_Squad = squad;
	}

	void SetCharacter(ExcelData::Character& _character);

	bool LoadAnimation();

	void Render();

	LEVEL GetLevel() const
	{
		return m_Level;
	}

	void MoveAnimation();

	void MoveEndAnimation();

	void AttackAnimation();

	INT Damage() const;

	AttackInformation Damage(DAMAGE::Type type, float damage);

	bool isDead() const
	{
		return GetHP() <= 0.0f;
	}

	float GetHP() const
	{
		return m_HP;
	}

	float GetMaxHP() const
	{
		return m_MaxHP;
	}

	CARD_INDEX GetIndex() const
	{
		return m_Index;
	}

	light::weak_raw_ptr<light::view::DirectX> DirectXPtr()
	{
		return m_direct_x;
	}

	void Draw(const light::POSITION_INT& Position, bool FrameUpdate);

	void DrawLoop(light::view::Animation2D& animation, const light::POSITION_INT& Position, bool Mirror, bool FrameUpdate);

	void Direction(const D3DXVECTOR3& vec)
	{
		m_Direction = vec;
	}
	
	D3DXVECTOR3 Direction() const
	{
		return m_Direction;
	}

	void SetAction(WEAK_ACTION action)
	{
		m_Action = action;
	}

	WEAK_ACTION GetAction()
	{
		return m_Action;
	}

	void PostDelay();

	void PostDelay(INT Delay);

	void PreDelay();

	void PreDelay(INT Delay);

	void DecreaseDelay()
	{
		if( m_Delay != 0)
		{
			--m_Delay;
		}
	}

	std::vector<Skill>& VectorSkill()
	{
		return m_vectorSkill;
	}

	BUTTON_INDEX GetButtonIndex()
	{
		return m_ButtonIndex;
	}

	bool operator<(const Card& rhs) const
	{
		return m_Index < rhs.GetIndex();
	}

	float Range();

	void Locate(Enum::Locate::Type locate, SLOT_NO no)
	{
		m_Locate = locate;
		m_SlotNo = no;
	}

	SLOT_NO SlotNo() const
	{
		return m_SlotNo;
	}

	Enum::Locate::Type Locate() const
	{
		return m_Locate;
	}

	void CalcAddStat();

	Instance::CharacterStat& CharacterStat()
	{
		return m_CharacterStat;
	}

	void PlayAttack();

	void PlayDamage();

public:
	INT CharacterIndex() const
	{
		return m_Character->Index();
	}

	INT Class() const
	{
		return m_Character->Class();
	}

	std::wstring Name()
	{
		return m_Character->Name();
	}

	std::wstring Thumbnail()
	{
		return m_Character->Image();
	}

	INT Cost()
	{
		return m_Character->Cost();
	}

	INT Str()
	{
		return m_Character->Str();
	}

	INT Int()
	{
		return m_Character->Int();
	}

	INT Con()
	{
		return m_Character->Con();
	}

	INT Dex()
	{
		return m_Character->Dex();
	}

	INT Wis()
	{
		return m_Character->Wis();
	}

public:
	INT Width()
	{
		return m_Width;
	}

	INT Height()
	{
		return m_Height;
	}

private:
	light::view::FmodEx m_AttackEffect;

	light::view::FmodEx m_DamageEffect;

	CARD_INDEX m_Index;

	BUTTON_INDEX m_ButtonIndex;

	INT m_RelationPoint;

	LEVEL m_Level;

	light::POSITION_FLOAT m_Position;

	D3DXVECTOR3 m_Direction;

	float m_HP, m_MaxHP;

	UNIQUE_DECIDE m_Decide;

	ExcelData::UNIQUE_CHARACTER m_Character;

	WEAK_SQUAD m_Squad;

	light::view::Animation2D m_Idle;

	light::view::Animation2D m_Move;

	light::view::Animation2D m_Attack;

	WEAK_ACTION m_Action;

	light::weak_raw_ptr<light::view::DirectX> m_direct_x;

	light::view::GuiProgressBar m_ProgressBar;

	WEAK_TILE m_Tile;

	TEAM::type m_Team;

	USHORT m_Delay;

	bool m_LoadAnimation;

	SLOT_NO m_SlotNo;

	Enum::Locate::Type m_Locate;

	light::POSITION_INT m_Disposition;

	std::vector<Skill> m_vectorSkill;

	Instance::CharacterStat m_CharacterStat;

	INT m_Width;

	INT m_Height;
};

} // namespace NW