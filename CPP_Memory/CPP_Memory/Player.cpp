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
		//�̵�
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

	// �ٷ� ���� ��ǥ?

	////������ ȸ��
	//_dir = (_dir + 1) % 4;
	////���� ȸ��
	//_dir = (_dir - 1) % 4;
	int32 count = 0;
	while (pos != dest)
	{
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 1. ���� �ٶ󺸴� ������ ��������, ���������� �� �� �ִ��� Ȯ��
			_dir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
			pos += front[_dir];
			_path.push_back({ pos.y, pos.x });
		}
		else if (CanGo(pos + front[_dir]))
		{
			pos += front[_dir];
			// ���
			_path.push_back({ pos.y, pos.x });
		}
		else
		{
			_dir = (_dir + 1) % 4;
		}
	}
}
