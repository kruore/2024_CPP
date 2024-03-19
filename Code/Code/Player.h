#pragma once
#include "iostream"
#include "Types.h"
#include "BaseCharacter.h"

using namespace std;

class Player : public BaseCharacter
{
public:
	Player(int id);
    ~Player();

	void Init(int id);
};

