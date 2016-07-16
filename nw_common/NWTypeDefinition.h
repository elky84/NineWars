#pragma once

#include <memory>
#include "weak_raw_ptr.hpp"

#include "Position.h"

#include "NWUtil.h"

class Class;
class Character;

namespace NW
{

static const int CHARACTER_SIZE = 110;
static const int MAP_WIDTH = 64 * 15;
static const int MAP_HEIGHT = 64 * 9;

static const int MAX_RELATION_POINT = 40;

struct ModeID
{
	enum Type
	{
		NONE = -1,
		SETTING,
		CHARACTER_SETTING,
		DISPOSITION,
		TACICS,
		BATTLE,
	};
};

typedef INT CARD_INDEX;

typedef INT ITEM_INDEX;

typedef INT SKILL_INDEX;

typedef INT BUTTON_INDEX;

typedef INT SLOT_NO;

typedef INT LEVEL;

struct DAMAGE
{
	enum Type
	{
		NONE = -1,
		AD = 0,
		AP = 1,
	};
};

struct AttackInformation
{
public:
	AttackInformation(const float damage = 0.0f, const DAMAGE::Type damagetype = DAMAGE::NONE, const bool dead = false)
		: Damage(damage)
		, DamageType(damagetype)
		, Dead(dead)
	{
	}

public:
	float Damage;
	DAMAGE::Type DamageType;
	bool Dead;
};

struct TEAM
{
	enum type
	{
		NONE = -1,
		RED = 0,
		BLUE = 1,
		MAX,
	};
};

struct AttackMethod
{
	enum Type
	{
		NONE = -1,
		SKILL1 = 0,
		SKILL2,
		SKILL3,
		NORMAL,
	};
};

typedef INT TARGETING_VALUE;

typedef INT MOVE_DECIDE_VALUE;

typedef INT POWER_DECIDE_VALUE;


const int MAX_CORPS_CARD = 9;
const int MAX_SQUAD_CARD = 9;

const int MAX_DECK = 40;

static const light::POSITION_FLOAT BluePosition[MAX_SQUAD_CARD] = {
	light::POSITION_FLOAT(13.0f * 64, 1.0f * 64), 
	light::POSITION_FLOAT(13.0f * 64, 4.0f * 64), 
	light::POSITION_FLOAT(13.0f * 64, 7.0f * 64), 
	light::POSITION_FLOAT(11.0f * 64, 1.0f * 64), 
	light::POSITION_FLOAT(11.0f * 64, 4.0f * 64), 
	light::POSITION_FLOAT(11.0f * 64, 7.0f * 64),
	light::POSITION_FLOAT(9.0f * 64, 1.0f * 64),
	light::POSITION_FLOAT(9.0f * 64, 4.0f * 64),
	light::POSITION_FLOAT(9.0f * 64, 7.0f * 64),
};

class Turn;
typedef std::unique_ptr<Turn> UNIQUE_TURN;
typedef light::weak_raw_ptr<Turn> WEAK_TURN;

class Action;
typedef std::shared_ptr<Action> SHARED_ACTION;
typedef std::unique_ptr<Action> UNIQUE_ACTION;
typedef light::weak_raw_ptr<Action> WEAK_ACTION;

class Decide;
typedef std::unique_ptr<Decide> UNIQUE_DECIDE;
typedef light::weak_raw_ptr<Decide> WEAK_DECIDE;

class Card;
typedef std::unique_ptr<Card> UNIQUE_CARD;
typedef light::weak_raw_ptr<Card> WEAK_CARD;

class Player;
typedef std::shared_ptr<Player> SHARED_PLAYER;
typedef std::unique_ptr<Player> UNIQUE_PLAYER;
typedef light::weak_raw_ptr<Player> WEAK_PLAYER;

class Squad;
typedef std::unique_ptr<Squad> UNIQUE_SQUAD;
typedef light::weak_raw_ptr<Squad> WEAK_SQUAD;

typedef std::vector<WEAK_SQUAD> VECTOR_SQUAD;
typedef std::unique_ptr< VECTOR_SQUAD > UNIQUE_VECTOR_SQUAD;
typedef light::weak_raw_ptr< VECTOR_SQUAD > WEAK_VECTOR_SQUAD;

class Battle;
typedef std::unique_ptr<Battle> UNIQUE_BATTLE;
typedef light::weak_raw_ptr<Battle> WEAK_BATTLE;

class ProjectTile;
typedef std::unique_ptr<ProjectTile> UNIQUE_PROJECTTILE;
typedef light::weak_raw_ptr<ProjectTile> WEAK_PROJECTTILE;

class Effect;
typedef std::unique_ptr<Effect> UNIQUE_EFFECT;
typedef light::weak_raw_ptr<Effect> WEAK_EFFECT;

class Particle;
typedef std::unique_ptr<Particle> UNIQUE_PARTICLE;
typedef light::weak_raw_ptr<Particle> WEAK_PARTICLE;

class Item;
typedef std::unique_ptr<Item> UNIQUE_ITEM;
typedef light::weak_raw_ptr<Item> WEAK_ITEM;

class Inventory;
typedef std::unique_ptr<Inventory> UNIQUE_INVENTORY;
typedef light::weak_raw_ptr<Inventory> WEAK_INVENTORY;

class Tile;
typedef std::unique_ptr<Tile> UNIQUE_TILE;
typedef light::weak_raw_ptr<Tile> WEAK_TILE;

class Skill;
typedef std::unique_ptr<Skill> UNIQUE_SKILL;
typedef light::weak_raw_ptr<Skill> WEAK_SKILL;

class SkillContainer;
typedef std::unique_ptr<SkillContainer> UNIQUE_SKILL_CONTAINER;
typedef light::weak_raw_ptr<SkillContainer> WEAK_SKILL_CONTAINER;


class Deck;
typedef std::unique_ptr<Deck> UNIQUE_DECK;
typedef light::weak_raw_ptr<Deck> WEAK_DECK;

} // namespace NW

namespace ExcelData
{

class Character;
typedef std::unique_ptr<Character> UNIQUE_CHARACTER;
typedef light::weak_raw_ptr<Character> WEAK_CHARACTER;

class ItemInfo;
typedef std::unique_ptr<ItemInfo> UNIQUE_ITEMINFO;
typedef light::weak_raw_ptr<ItemInfo> WEAK_ITEMINFO;

class Skill;
typedef std::unique_ptr<Skill> UNIQUE_SKILL;
typedef light::weak_raw_ptr<Skill> WEAK_SKILL;

} // namespace ExcelData