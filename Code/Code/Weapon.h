#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon() { cout << "Weapon" << endl; }
	~Weapon();

private:
};

