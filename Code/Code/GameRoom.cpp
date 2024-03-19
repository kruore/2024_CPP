#include "GameRoom.h"
#include <random>

void GameRoom::PlayerCreate()
{
	if (_player == nullptr)
	{
		cout << "Player is Null Created" << endl;
		_player = new Player(playerCount);
		playerCount++;
	}
}

void GameRoom::CreateMonster()
{
	for (int i = 0; i < 1000; i++)
	{
		int seed = GetRandomSeed();
		MONSTER_TYPE type;
		seed = (seed % 4) + 1;
		switch (seed)
		{
		case 1:
			type = MONSTER_TYPE::SKELETON;
			break;
		case 2:
			type = MONSTER_TYPE::SLIME;
			break;
		case 3:
			type = MONSTER_TYPE::DEMON;
			break;
		case 4:
			type = MONSTER_TYPE::ORC;
			break;
		}
		auto monster_dummy = new Monster(monsterCount, type);
		monsters.push_back(monster_dummy);
		monsterCount++;
	}

}

void GameRoom::RemoveMonster(int id)
{
	for (int i = 0; i < monsters.size(); i++)
	{
		if (monsters[i]->GetID()==id)
		{
			auto mon = monsters[i];
			monsters.erase(monsters.begin() + i);
			delete mon;
		}
	}
}

void GameRoom::ClearMonster()
{
	for (auto element : monsters) {
		delete element;
	}
	monsters.clear();
	monsters.shrink_to_fit();
}

void GameRoom::CreateItemDummy()
{
	for (int i = 0; i < 100; i++)
	{
		Weapon* weaponptr = new Weapon();
		items.push_back(weaponptr);
	}
}

void GameRoom::RemoveItem()
{

	for (int i = 0; i < 10; i++)
	{
		if (items.size() == 0)
			return;
		auto c = items[0];
		items.erase(items.begin());
		delete c;
	}
}


int GameRoom::GetRandomSeed()
{
	//Create Random Seed;
	int seed = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);
	seed = dis(gen);
	return seed;
}
