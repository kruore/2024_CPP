#include "iostream"
#include "BaseCharacter.h"
#include "Player.h"
#include "vector"
#include "Monster.h"
#include "Weapon.h"
#include "GameRoom.h"
#pragma once
#include <vector>


using namespace std;
GameRoom gameroom;
struct Vertex {

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph_1()
{
	vertices.resize(6);

	adjacent = vector < vector<int>>(6);
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

}
//
vector<bool> visited;
void DFS(int here)
{
	visited[here] = true;
	cout << "Visited" << here << endl;

	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
		{
			DFS(there);
		}
	}

}

void DFS(int here)
{
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;
		if (visited[there] == false)
			DFS(there);
	}
}




int main()
{
	CreateGraph_1();
	visited = vector<bool>(6, false);
	DFS(0);


	//int controll;
	//while(true)	{
	//	if(gameroom.isPlayer())
	//	{
	//		gameroom.PlayerCreate();
	//	}
	//	cin >> controll;
	//	switch (controll)
	//	{
	//	case 1:
	//		gameroom.CreateMonster();
	//		break;
	//	case 2:
	//		int cc;
	//		cin >> cc;
	//		gameroom.RemoveMonster(cc);
	//		break;
	//	case 3:
	//		gameroom.ClearMonster();
	//	default:
	//		break;
	//	}
	//}

}
