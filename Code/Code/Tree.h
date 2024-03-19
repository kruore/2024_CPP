#pragma once

template<typename T>
class Node;


template<typename T>
class Tree 
{
public:

	Tree(int depth) : _depth(depth) {};
	~Tree() {};

public:
	

private:
	int _depth;
	Node<T>* _first;
	Node<T>* _second;
};

