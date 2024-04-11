#pragma once
template <class T>
class Vector
{
public:
	Vector() {_buffer = new T[10];};
	Vector(int count) : _size(count) { _buffer = new T[10]; };
	~Vector() {
		if (_buffer != nullptr)
		{
			delete[] _buffer;
			_buffer = nullptr;
		}
		else
		{
			cout << "already Deleted" << endl;
		}
	};
public:



	void reSize(const int size = 0)
	{
		if (_capacity <= _size)
		{
			cout << "Vector Capacity Up" << endl;
			int newCapacity = (_capacity << 1) + 1;
			auto newSlot = new T[newCapacity];
			//::copy(_buffer,_size,newSlot);
			delete[] _buffer;
			_capacity = newCapacity;
			_buffer = newSlot;
		}
		else 
		{
			cout << "Vector Size Changed" << endl;
			_size = size;
		}
	}

	void push_back(const T data)
	{
		if (_capacity <= _size)
		{
			reSize(_capacity);
		}
		_buffer[_size] = data;
		_size++;
	}
	void pop_back()
	{
		_buffer[_size] = 0;
		_size--;
	}
	T& Top()
	{
		if (!_buffer)
			return this->_buffer[0];
		return _buffer[0];
	}
	bool isEmpty()
	{
		return _size == 0;
	}
	
	T operator[](int pos)
	{
		return _buffer[pos];
	}

	int capacity() { cout << "capacity : " << _capacity << endl; return _capacity; };
	int size() { cout << "size : " << _size << endl; return _size; };

private:
	T* _buffer = nullptr;
	int _size = 0;
	int _capacity = 0;
};

