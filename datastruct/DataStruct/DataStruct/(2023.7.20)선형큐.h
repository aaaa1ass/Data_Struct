#pragma once
#include <iostream>
#include <queue>
#define SIZE 5

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
	int& Size()
	{
		return size;
	}
	T& Front()
	{
		if (!Empty())
			return array[front];
	}
	T& Back()
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

int main()
{
#pragma region 선형 큐
	//배열의 공간에 들어간 데이터가 고정되어 데이터를 빼내더라도 초기화하지 않으면 원래 데이터가 있던 배열의 자리에 더이상 다른 것이 들어갈 수 없는 형태의 Queue
	LinearQueue<int> queue;
	queue.Push(-99);
	queue.Push(2);
	queue.Push(3);
	queue.Push(99);
	queue.Push(100);

	queue.Pop();

	std::cout << queue.Front() << std::endl;
	std::cout << queue.Back() << std::endl;
	std::cout << queue.Size() << std::endl;

#pragma endregion

	return 0;
}