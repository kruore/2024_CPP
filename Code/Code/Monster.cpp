#include "Monster.h"
#include "Types.h"
#include "Item.h"

Monster::Monster(int id, MONSTER_TYPE monsterType)
{
	Init(id, monsterType);
	cout << "Monster : " << _id << "TYPE: " << MonsterToString(monsterType) << endl;
}

Monster::~Monster()
{
	cout << "~Monster" << _id << endl;
	delete[] _item;
	_item = nullptr;
}

void Monster::Init(int id, MONSTER_TYPE types)
{
	_id = id;
	_type = CHARACTER_TYPE::MONSTER;
	m_type = types;
	GetItem();
}

string Monster::MonsterToString(MONSTER_TYPE type)
{
	switch (type)
	{
	case MONSTER_TYPE::NONE:
		return "NONE";
	case MONSTER_TYPE::SKELETON:
		return "SKELETON";
	case MONSTER_TYPE::SLIME:
		return "SLIME";
	case MONSTER_TYPE::DEMON:
		return "DEMON";
	case MONSTER_TYPE::ORC:
		return "ORC";
	default:
		return "";
	}
}

Item* Monster::GetItem()
{
	if (_item == nullptr)
	{
		Item* item = new Item();
		item->Initialized(UTIL::Change(),"Description");
		_item=item;
	}
	return _item;
}
