#include "pch.h"
#include "vector"
#include "time.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;


int main()
{
	::srand(static_cast<uint32>(time(nullptr)));

	uint64 lastTick = 0;
	board.Init(11, &player);
	player.Init(&board);
	while (true)
	{
#pragma region  프레임 관리
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion

		player.Update(deltaTick);

		board.Render();
	}
}