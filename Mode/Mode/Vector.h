#pragma once

template <typename T>
class Vector
{
public:
	explicit Vector(int size = 0) {
	};
	~Vector()
	{
		if (_buffer)
			delete[] _buffer, _buffer = nullptr;
	}
#pragma region  Function

	void Push(const T& data)
	{
		if (_size >= _capacity)
		{
			auto newCapa = static_cast<int>(_capacity) << 1;
			if (_size == newCapa)
				newCapa++;
			T* newBuffer = new T[newCapa];
			for (int i = 0; i < _capacity; i++)
			{
				newBuffer[i] = _buffer[i];
			}
			delete[] _buffer;
			_buffer = newBuffer;
			_capacity = newCapa;
		}
		_buffer[_size] = data;
		_size++;
	}

	void Pop()
	{
		_size--;
	}
	T		Top() { return _buffer[_size - 1]; }
	int		size() { return _size; }
	int		capacity() { return capacity; }

#pragma endregion

#pragma region Operator
	T& operator[](const int pos)
	{
		return _buffer[pos];
	}

#pragma endregion

private:
	T*		_buffer		= nullptr;
	int		_size		= 0;
	int		_capacity	= 0;


};