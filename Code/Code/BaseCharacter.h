#pragma once

#include "iostream"
#include "Types.h"

using namespace std;

class BaseCharacter
{
public:

	BaseCharacter();	
	virtual ~BaseCharacter();

public:
	bool GetDead() { return _isDead; }
	void SetDead(bool IsDead) { _isDead = IsDead; }


protected:
	int				_id				= 0;
	string			_description	= "";
	CHARACTER_TYPE	_type			= CHARACTER_TYPE::PLAYER;
	bool			_isDead			= false;

protected:
	int				_hp			= 0;
	int				_mp			= 0;
	float			_critical	= 0.f;
};

