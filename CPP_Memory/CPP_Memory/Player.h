#pragma once
#include "vector"
class Board;

enum
{
	MOVE_TICK = 1000
};
class Player
{
public:

	void	Init(Board* board);
	void	Update(uint64 deltaTick);
	
	void	SetPos(Pos pos) { _pos = pos; }
	Pos		GetPos() { return _pos; }

	bool	CanGo(Pos pos);
private:

	void ClaculatePath();
	

private:

	Pos		_pos;
	int32	_dir = DIR_UP;
	Board*	_board = nullptr;

	vector<pair<int32, int32>>	_path;
	int32						_pathIndex = 0;
	uint64						_sumTick = 0;
};

