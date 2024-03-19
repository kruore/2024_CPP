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
		//���� ������ Node�� ���ؼ� �ش� h�� �𸣱⶧���� *�� ����
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