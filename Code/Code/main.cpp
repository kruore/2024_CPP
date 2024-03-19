#include "iostream"
#include "BaseCharacter.h"
#include "Player.h"
#include "vector"
#include "Monster.h"
#include "Weapon.h"
#include "GameRoom.h"

using namespace std;
GameRoom gameroom;

int main()
{	

	int controll;
	while(true)	{
		if(gameroom.isPlayer())
		{
			gameroom.PlayerCreate();
		}
		cin >> controll;
		switch (controll)
		{
		case 1:
			gameroom.CreateMonster();
			break;
		case 2:
			int cc;
			cin >> cc;
			gameroom.RemoveMonster(cc);
			break;
		case 3:
			gameroom.ClearMonster();
		default:
			break;
		}
	}

}
