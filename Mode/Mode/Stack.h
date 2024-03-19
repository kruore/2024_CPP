#pragma once
#include "Vector.h"
#include "iostream"
using namespace std;

template <typename T>
class Stack
{
public:

	Stack() {};
	~Stack() {cout<<"RemoveStack"<<endl; };


public:

	void Push(T data)
	{
		_slot.Push(data);
		_end++;
	}
	void Pop()
	{
		if (_end <= 0)
		{
			return;
		}
		_slot.Pop();
		_end--;
	}
	T top()
	{
		if (_end == 0)
			return -1;
		return _slot[_end-1];
	}
	bool empty() { return _end == 0; }
	T size() { return _end; }


private:
	Vector<T>	_slot;
	int			_end;

};
