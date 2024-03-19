#pragma once
enum class CHARACTER_TYPE
{
	NONE,
	PLAYER,
	MONSTER,
};

enum class ITEM_TYPE
{
	ARMOR,
	WEAPON
};

enum class MONSTER_TYPE
{
	NONE,
	SKELETON,
	SLIME,
	DEMON,
	ORC
};

class UTIL
{
public:
	static int Change()
	{
		return 1;
	}
};
