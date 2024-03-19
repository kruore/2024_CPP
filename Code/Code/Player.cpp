#include "Player.h"

Player::Player(int id)
{
	Init(id);
	cout << "Player is Created: "<<_id << endl;
};


Player::~Player()
{
	cout << "~Player" << endl;
}

void Player::Init(int id)
{
	_id = id;
	_hp = 100;
	_mp = 100;
}
