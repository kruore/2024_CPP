#pragma once
#include "vector"
#include "iostream"
using namespace std;

template <typename T>
class Node
{
public:
	Node(T data) : _data(data){};
	~Node() {};
public:
	
#pragma region SetData
	T GetData()
	{
		return _data;
	}
	void SetData(T data)
	{
		_data = data;
	}
	int GetChildSize()
	{
		return static_cast<int>(children.size());
	}
	void AddChild(Node* data)
	{
		children.push_back(data);
	}

#pragma endregion

	Node<T> operator=(T data)
	{
		_data = data;
		return *this;
	}
	vector<Node<T>*> children;
private:
	T		_data; 
};