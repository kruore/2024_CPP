#include "Vector.h"
#include "Queue.h"
#include "Stack.h"
#include "iostream"

using namespace std;


int main()
{
	Vector<int> c;
	Queue<int> q;
	Stack<int> s;

	c.Push(1);
	c.Push(2);
	c.Push(3);
	c.Push(4);
	c.Push(5);

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);


	s.Push(1);
	cout << s.top();
	s.Push(2);
	cout << s.top();
	s.Push(3);
	cout << s.top();
	s.Push(4);
	cout << s.top();
	s.Push(5);
	cout << s.top();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();
	cout << s.top();

	cout << s.empty();

	s.Push(1);
	cout << s.top();
	s.Push(1);
	cout << s.top();
	s.Push(1);
	cout << s.top();

	cout << q.front();
}