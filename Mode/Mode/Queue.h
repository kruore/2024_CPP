#pragma once
#include "Vector.h"

template <typename T>
class Queue {

public:
	Queue() {}
	~Queue() {}


public:

	void Enqueue(const T data)
	{
		_slot.Push(data);
		_rear = (_rear + 1) % _slot.size();
	}

	void Dequeue()
	{
		if (_front == _rear)
			return;
		_slot[_front] = 0;
		_front = (_front + 1) % _slot.size();
	}
	T front()
	{
		if (_front == _rear)
			return -1;
		return _slot[_front];
	}


private:
	Vector<T>  _slot;
	int		   _front = 0;
	int		   _rear = 0;
};