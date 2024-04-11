#pragma once
template <class T>
class Node
{
public:
	Node(T data) : _data(data) {};
	~Node() {};

public:
	void HeadNode(Node* node)
	{
		if (_prev == nullptr)
			this->_prev = node;
		else
			return;
	}
	void NextNode(Node* node)
	{
		if (_next == nullptr)
			this->_next = node;
		else
			return;
	}
	Node* getPrev()
	{
		return _prev;
	}
	Node* getNext()
	{
		return _next;
	}

private:
	T _data;
	Node* _prev = nullptr;
	Node* _next = nullptr;
};

