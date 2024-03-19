#pragma once
#include "vector"

template<typename T>
class PriorityQueue
{
public:
	void Push(const T& data)
	{
		_heap.push_back(data);
	}
	void pop()
	{

	}

	T& top()
	{
		_heap.end();
	}
	bool empty()
	{
		return _heap.empty();
	}


private:

	vector<T> _heap;
};