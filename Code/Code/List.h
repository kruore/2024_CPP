#pragma once

template<typename T>
class Node;

template<typename T>
class List
{
public:
	List() {};
	~List() {};

public:

	void AddAtHead(T data)
	{
		//전방 선언한 Node에 대해서 해당 h는 모르기때문에 *로 선언
		Node<T>* node = new Node<T>(data);
		if (_head == nullptr)
		{
			_head = node;
			_tail = node;
		}
		else
		{
			
		}
	}


private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
};