#pragma once

#include "Vector.h"

template <typename T>
class Queue
{
public:
	Queue() { Init(); }
	~Queue() {}

public:
	void Init() {
		_container.ReSize(100);
	}

	void Enqueue(const T data)
	{
		//TODO: 원형 큐로 변경하기.
		_container[_rear] = data;
		_rear = ((_rear + 1) % _container.Size());
	}
	void Dequeue()
	{
		_container[_front];
		_front = ((_front + 1) % _container.Size());
	}

	T Front()
	{
		return _container[_front];
	}

	bool IsFull()
	{
		return (_rear+1)%_container.Size() == _front;
	}
	bool IsEmtry()
	{
		return _rear == _front;
	}

private:

	Vector<T> _container;
	int _front = 0;
	int _rear = 0;
};