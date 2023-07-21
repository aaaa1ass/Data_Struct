#include <iostream>
#define SIZE 4

template <typename T>
class LinearQueue
{
private:
	int front;
	int rear;
	int size;
	T array[SIZE];
public:
	LinearQueue()
	{
		front = 0;
		rear = -1;
		size = 0;
	}
	void Push(T data)
	{
		if (!IsFull())
		{
			array[++rear] = data;
			size++;
		}
		else
			return;

	}
	void Pop()
	{
		if (!Empty())
		{
			array[front++] = NULL;
			size--;
		}
		else
			return;
	}
	int & Size()
	{
		return size;
	}
	T & Front()
	{
		if(!Empty())
			return array[front];
	}
	T & Back()
	{
		if (!Empty())
			return array[rear];
	}
	bool Empty()
	{
		if (front > rear)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		if (rear >= SIZE - 1)
			return true;
		else
			return false;
	}

};

template <typename T>
class CircleQueue
{
private:
	int front;
	int rear;
	T Buffer[SIZE];
public:
	CircleQueue()
	{
		front = SIZE - 1;
		rear = SIZE - 1;
		Buffer[SIZE] = { 0 ,};
	}
	void Push(T data)
	{
		if (!IsFull())
		{
			rear = (rear + 1) % SIZE;
			Buffer[rear] = data;
		}
		else
			std::cout << "Queue is full." << std::endl;
	}
	void Pop()
	{
		if (!Empty())
		{
			front = (front + 1) % SIZE;
			Buffer[front] = NULL;
		}
		else
			std::cout << "Queue is empty" << std::endl;
	}
	T & Front()
	{
		if (!Empty())
		{
			return Buffer[(front + 1) % SIZE];
		}
		else
		{
			return 0;
		}
	}
	T & Back()
	{
		if (!Empty())
		{
			return Buffer[rear];
		}
		else
			return 0;
	}
	bool IsFull()
	{
		if (front == (rear + 1) % SIZE)
			return true;
		else
			return false;
	}
	bool Empty()
	{
		if (front == rear)
			return true;
		else
			return false;
	}

};

int main()
{
#pragma region 원형 큐
	//물리적으로 선형 구조며, 큐의 시작점과 끝점을 연결한 큐
	CircleQueue<int> queue;
	queue.Push(10);
	queue.Push(20);
	queue.Push(30);
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Push(40);
	queue.Push(50);
	queue.Push(60);
	queue.Pop();
	queue.Pop();
	queue.Pop();
	queue.Push(70);
	queue.Push(80);
	queue.Push(90);

	std::cout << queue.Front() << std::endl;
	std::cout << queue.Back() << std::endl;

#pragma endregion


	return 0;
}