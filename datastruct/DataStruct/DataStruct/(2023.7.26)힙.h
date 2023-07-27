#pragma once
#include <iostream>

#define SIZE 8

class MAX_HEAP
{
private:
	int heapArray[SIZE];
	int index;
public:
	MAX_HEAP()
	{
		for (int i = 0; i < SIZE; i++)
		{
			heapArray[i] = NULL;
		}
		index = 0;
	}
	void Insert(int data)
	{
		if (index == SIZE - 1)
			return;
		heapArray[++index] = data;
		//if (index > 1)
		//{
		//	int t = index;
		//	while (heapArray[t / 2] < data)
		//	{
		//		std::swap(heapArray[t / 2], heapArray[t]);
		//		t = t / 2;
		//		if (t == 1)
		//			break;
		//	}
		//}
		int child = index;
		int parent = index / 2;
		while (child > 1)
		{
			if (heapArray[parent] < heapArray[child])
			{
				std::swap(heapArray[parent], heapArray[child]);
			}
			child = parent;
			parent = child / 2;
		}
		PrintHeap();
	}
	int& Delete()
	{
		int max = heapArray[1];
		if (index <= 0)
		{
			std::cout << "heap is empty." << std::endl;
			exit(1);
		}

		heapArray[1] = heapArray[index];
		heapArray[index--] = NULL;
		//int t = 1;
		//while (t < SIZE / 2)
		//{
		//	if (heapArray[t * 2] > heapArray[t * 2 + 1])
		//	{
		//		if (heapArray[t * 2] > heapArray[t])
		//		{
		//			std::swap(heapArray[t * 2], heapArray[t]);
		//		}
		//		else
		//		{
		//			break;
		//		}
		//		t = t * 2;
		//	}
		//	else
		//	{
		//		if (heapArray[t * 2 + 1] > heapArray[t])
		//		{
		//			std::swap(heapArray[t * 2 + 1], heapArray[t]);
		//		}
		//		else
		//		{
		//			break;
		//		}
		//		t = t * 2 + 1;
		//	}
		//}
		int parent = 1;
		int child = 2;
		while (child <= index)
		{
			if (heapArray[child] < heapArray[child + 1])
				child = child + 1;

			if (heapArray[parent] < heapArray[child])
			{
				std::swap(heapArray[parent], heapArray[child]);
				parent = child;
				child = parent * 2;
			}
			else
				break;
		}

		PrintHeap();
		return max;
	}
	void PrintHeap()
	{
		for (int i = 1; i <= index; i++)
		{
			std::cout << heapArray[i] << ' ';
		}
		std::cout << std::endl;
	}
};

int main()
{
#pragma region ��
	// ���� ���� �߿� �ִ�, �ּڰ��� ������ ã�� ���� �ڷ� ����

	//�ִ� ��
	//�θ� ����� Ű ���� �ڽ� ����� Ű ������ ũ�ų� ���� ���� ���� Ʈ��
	MAX_HEAP heap;
	heap.Insert(10);
	heap.Insert(20);
	heap.Insert(30);
	heap.Insert(40);
	heap.Insert(50);
	heap.Insert(60);
	heap.Insert(70);

	heap.Delete();
	heap.Delete();
	heap.Delete();
	heap.Delete();
	heap.Insert(0);
	heap.Delete();
	heap.Delete();
	heap.Delete();

	heap.Insert(10);
	heap.Insert(20);
	heap.Insert(30);
	heap.Insert(40);
	heap.Insert(50);
	heap.Insert(60);
#pragma endregion


	return 0;
}