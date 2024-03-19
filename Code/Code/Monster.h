#pragma once
#include "iostream"
#include "BaseCharacter.h"
#include "Types.h"

class Item;

class Monster : public BaseCharacter
{
public:
	Monster(int id, MONSTER_TYPE monsterType);
	~Monster();

	void Init(int id, MONSTER_TYPE types);

	string MonsterToString(MONSTER_TYPE type);

	Item* GetItem();
	int GetID() { return _id; };

private:
	MONSTER_TYPE m_type = MONSTER_TYPE::NONE;
	Item* _item = nullptr;

};

