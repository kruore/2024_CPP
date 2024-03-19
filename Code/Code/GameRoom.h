#pragma once
#include "vector";
#include "Weapon.h"
#include "Player.h"
#include "Item.h"
#include "Monster.h"

class GameRoom
{
public:
	GameRoom() {};
	~GameRoom() {};

	bool isPlayer() { return _player == nullptr; }

	void PlayerCreate();
	void CreateMonster();
	void RemoveMonster(int id);
	void ClearMonster();

	void CreateItemDummy();
	void RemoveItem();

	int GetRandomSeed();

	

private:
	Player* _player = nullptr;
	vector<Monster*> monsters;
	vector<Item*> items;
	
	int playerCount = 0;
	int monsterCount = 0;

};

