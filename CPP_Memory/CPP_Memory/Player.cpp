#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	ClaculatePath();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;
	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;
		//이동
		_pos.y = _path[_pathIndex].first;
		_pos.x = _path[_pathIndex].second;
		_pathIndex++;
	}

}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::ClaculatePath()
{
	Pos pos = _pos;
	_path.clear();

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
	};
	Pos dest = _board->GetExitPos();

	// 바로 앞의 좌표?

	////오른쪽 회전
	//_dir = (_dir + 1) % 4;
	////왼쪽 회전
	//_dir = (_dir - 1) % 4;
	int32 count = 0;
	while (pos != dest)
	{
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 1. 현재 바라보는 방향을 기준으로, 오른쪽으로 갈 수 있는지 확인
			_dir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
			pos += front[_dir];
			_path.push_back({ pos.y, pos.x });
		}
		else if (CanGo(pos + front[_dir]))
		{
			pos += front[_dir];
			// 기록
			_path.push_back({ pos.y, pos.x });
		}
		else
		{
			_dir = (_dir + 1) % 4;
		}
	}
}
