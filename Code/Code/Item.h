#pragma once
#include "iostream"
using namespace std;

class Item
{
public:
	Item() { cout << "item" << endl; };
	virtual ~Item();
	

	//아이템 시리얼라이제이션
	void Initialized(int id, string description);

protected:
	int			_id = 0;
	string		_description = "";
};

