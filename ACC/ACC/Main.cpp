#define SIZE 2
#include "iostream"

using namespace std;
class Queue
{
public:
	Queue() {};
	~Queue() {};

	void Enqueue(int data)
	{
		if (isFull())
		{
			cout << "FULL" << endl;
			return;
		}
		_rear = (_rear+1)%SIZE;
		_data[_rear] = data;
	}
	void Dequeue()
	{
		_front = (_front+1)%SIZE;
		_data[_front] = 0;
	}
	bool isFull()
	{
		return (_rear+1)% SIZE == _front;
	}
	bool isEmpty()
	{
		return _rear == _front;
	}
	int front()
	{
		return _data[_front];
	}

private:
	int _data[SIZE];
	int _front = 0;
	int _rear = 0;
};

int main()
{
	Queue data_q;
	data_q.Enqueue(3);
	data_q.Enqueue(3);
	data_q.Enqueue(3);
	cout << data_q.front() << endl;

}