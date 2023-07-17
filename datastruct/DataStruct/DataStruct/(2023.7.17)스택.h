#pragma once
#include <iostream>
#include <stack>

#define SIZE 5

template <typename T>
class STACK
{
private:
	int top;
	T buffer[SIZE];
public:
	STACK()
	{
		top = -1;
	}
	void Push(T data)
	{
		if (!IsFull())
		{
			top++;
			buffer[top] = data;
		}
		else
		{
			std::cout << "STACK is full." << std::endl;
		}
	}
	T Pop()
	{
		if (!Empty())
		{
			return buffer[top--];
		}
		else
		{
			std::cout << "STACK is empty." << std::endl;
			return 0;
		}
	}
	bool Empty()
	{
		if (top <= -1)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		if (top >= SIZE - 1)
			return true;
		else
			return false;
	}
	T Top()
	{
		if (!Empty())
		{
			return buffer[top];
		}
		else
		{
			exit(1);
		}
	}
	~STACK()
	{
	}
};

int main()
{
	STACK<int> intStack;
	intStack.Push(10);
	intStack.Push(20);
	intStack.Push(30);
	intStack.Push(40);
	while (intStack.Empty() == false)
	{
		std::cout << intStack.Top() << std::endl;
		intStack.Pop();
	}

	return 0;
}