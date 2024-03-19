#pragma once

template <typename T>
class Vector
{
public:
	Vector() { Init(); };
	~Vector() {
		if (_buffer)
		{
			delete[] _buffer, _buffer = nullptr;
		}
	};

public:

	void Init()
	{
		if (_size >= _capacity)
		{
			int newCapa = _capacity < 1;
			if (newCapa == _capacity)
			{
				newCapa++;
			}
			ReSize(newCapa);
		}
	}
	void ReSize(int size)
	{
		if (_capacity <= size)
		{
			T* newBuffer = new T[size];
			if (!_buffer)
			{
				_buffer = newBuffer;
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					newBuffer[i] = _buffer[i];
				}
				delete[] _buffer;
				_buffer = newBuffer;
			}
			_capacity = size;
		}

	}

	void Push(const T data)
	{
		if (_size >= _capacity)
		{
			int newCapa = _capacity < 1;
			if (newCapa == _capacity)
			{
				newCapa++;
			}
			ReSize(newCapa);
		}
		_buffer[_size] = data;
		_size++;
	}
	void Pop()
	{
		if (_size > 0)
		{
			_buffer[_size] = 0;
			_size--;
		}
	}

	T Top()
	{
		return _size > 0 ? _buffer[_size - 1] : -1;
	}
	int Size() { return _size; }


	T operator[](int pos)
	{
		if (pos < _size)
		{
			return _buffer[pos];
		}
		else
		{
			return  -1;
		}
	}
private:
	T*		_buffer		= nullptr;
	int		_size		= 0;
	int		_capacity	= 0;
};