#pragma once


template<typename T>
class Vector
{
public:
	Vector() { _buffer = new T[0]; };
	~Vector() {};

public:

	void Push(const T& data) 
	{
		if (_size >= _capacity)
		{
			auto newCapa = static_cast<int>(_capacity << 1);
			if (newCapa == _capacity)
			{
				newCapa++;
			}
			reserve(newCapa);
		}
		_buffer[_size] = data;
		_size++;
	}
	void Pop()
	{
		if (_size > 0)
			_size--;
		else
			return;
	}

	void resize(int size) {
		_size = size;
	}

	void reserve(int count)
	{
		_capacity = count;
		T* newData = new T[_capacity];
		for (int i = 0; i < count; i++)
		{
			newData[i] = _buffer[i];
		}
		if (_buffer)
			delete[] _buffer;
		_buffer = newData;
	}

	T& operator[](int data)
	{
		return _buffer[data];
	}
private:

	T*	_buffer			= nullptr;
	int _size			= 0;
	int _capacity		= 0;



};
