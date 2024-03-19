#include "Item.h"


Item::~Item()
{
	cout << "~item" << endl;
}

void Item::Initialized(int id, string description)
{
	_id = id;
	_description=description;
	cout <<"ITEM: " << _id <<"DES: "<< _description << endl;
}
