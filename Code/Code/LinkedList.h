#pragma once

#include "Node.h"

template<typename T>
class LinkedList
{
public:

	LinkedList() {};
	~LinkedList() {};

public:

	void	Add(T* data)
	{
		_data = data;
	}


private:
	T				_data;
	
};

