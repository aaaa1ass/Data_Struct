#pragma once
#include <iostream>
#define SIZE 9
int arr[SIZE] = { 5,3,8,4,9,1,2,6,7 };
void QuickSort(int data[], int start, int end)
{
	//���Ұ� 1��
	if (start >= end)
	{
		return;
	}

	int p = start;
	int l = start + 1;
	int r = end;

	//while (1)
	//{
	//	while (arr[p] > arr[l])
	//	{
	//		l++;
	//	}
	//
	//	while (arr[p] < arr[r])
	//	{
	//		r--;
	//	}
	//
	//	if (r < l)
	//		break;
	//
	//	std::swap(arr[l], arr[r]);
	//}
	//std::swap(arr[p], arr[r]);

	while (l <= r)
	{
		while (l <= end && arr[p] > arr[l])
		{
			l++;
		}

		while (r >= start && arr[r] > arr[p])
		{
			r--;
		}

		if (r < l)
		{
			std::swap(arr[p], arr[r]);
		}
		else
		{
			std::swap(arr[l], arr[r]);
		}
	}

	QuickSort(data, start, r - 1);
	QuickSort(data, r + 1, end);


}
struct Node
{
	int key;
	int value;
	Node* next;
};
struct Bucket
{
	Node* head;
	int count;
};
class HashTable
{
private:
	Bucket bucket[5];
public:
	HashTable()
	{
		for (int i = 0; i < 5; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}
	Node* CreateNode(int key, int value)
	{
		//�� ��� ����
		Node* newNode = new Node;

		//�� ����� key�� ����
		newNode->key = key;

		//�� ����� value�� ����
		newNode->value = value;

		//�� ����� next �ʱ�ȭ
		newNode->next = nullptr;

		//�� ����� �ּڰ� ��ȯ
		return newNode;
	}
	int HashFunction(int key)
	{
		return key % 5;
	}
	void Insert(int key, int value)
	{
		int index = HashFunction(key);

		Node* newNode = CreateNode(key, value);

		if (bucket[index].count == 0)
		{
			bucket[index].head = newNode;
			bucket[index].count = 1;
		}
		else
		{
			//Node* node = bucket[index].head;
			//for (int i = 1; i < bucket[index].count; i++)
			//	node = node->next;
			//node->next = newNode;
			//bucket[index].count++;
			newNode->next = bucket[index].head;
			bucket[index].head = newNode;
			bucket[index].count++;
		}

	}
	void Remove(int key)
	{
		int index = HashFunction(key);

		Node* node = bucket[index].head;

		if (!node)
		{
			std::cout << "��尡 �����ϴ�." << std::endl;
		}

		if (bucket[index].head->key == key)
		{
			bucket[index].head = bucket[index].head->next;
			delete node;
			bucket[index].count--;
			return;
		}

		Node* traceNode = node;
		node = node->next;

		while (node)
		{
			if (key == node->key)
			{
				traceNode->next = node->next;
				delete node;
				bucket[index].count--;
				return;
			}
			node = node->next;
			traceNode = traceNode->next;
		}

		std::cout << "Ű�� �����ϴ�." << std::endl;
	}
	int Search(int key)
	{
		int index = HashFunction(key);
		Node* node = bucket[index].head;
		while (node)
		{
			if (key == node->key)
			{
				return node->value;
			}
			node = node->next;
		}
		std::cout << "Ű�� �����ϴ�." << std::endl;
		return 0;
	}
	void Show()
	{
		for (int i = 0; i < 5; i++)
		{
			Node* node = bucket[i].head;
			while (node)
			{
				std::cout << "( " << node->key << " : " << node->value << " ) ";
				node = node->next;
			}
			std::cout << std::endl;
		}
	}

};
int main()
{
#pragma region �� ����
	//�������� ȹ���� ���� �ش� �������� �������� �迭�� ������ �� �ʿ��� ���������� ���� �׸���� ��ġ�ϰ� �ٸ� �ʿ��� ���������� ū �׸���� ��ġ�Ѵ�
	//�������� ���� �迭�� ���� ��������� �� ������ ȣ���Ͽ�, ��� �迭�� �⺻ �迭�� �� ������ �ݺ��ϴ� �˰����̴�

	//QuickSort(arr,0,SIZE - 1);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	std::cout << arr[i] << ' ';
	//}
#pragma endregion

#pragma region �ؽ� ���̺�
	// (key, value)�� �����͸� ������ �� �ִ� �ڷᱸ�� �� �ϳ��� ������ �����͸� �˻��� �� �ִ� �ڷᱸ��

	//��� �ð� ���⵵ O(1)

	//�ؽ� �浹 �ذ� ���

	//ü�̴� ���
	//�� �ؽ� ��Ŷ�� ���Ḯ��Ʈ�� �����ϴ� ���
	//�ؽ� �浹 �߻� �� ������ �ؽ� ���� �ش��ϴ� �����͵��� ���Ḯ��Ʈ�� �����Ͽ� ����

	HashTable hashTable;


	hashTable.Insert(5, 500);
	hashTable.Insert(10, 100);

	hashTable.Remove(10);

	hashTable.Search(10);

	//���� �ּҹ�
	/*�浹 �߻� �� �� ��Ŷ�� �����͸� �����ϴ� ���
	�� ��Ŷ�� �����ϴ� ��Ŀ� ���� �ٸ� ���� ���
	���� Ž��: �浹 �߻� �� �տ������� ���ʴ�� �� ��Ŷ�� ã�� ���� �����ϴ� ���
	���� Ž��: �浹 �߻� �� 2^2, 2^3 ��ŭ ������ �� ��Ŷ�� ã�� ���� �����ϴ� ���
	���� �ؽ�: �ؽ� ���� �ѹ� �� �ؽ� �Լ��� �־� �ٸ� �ؽ˰��� �����ϴ� ���*/
#pragma endregion

	return 0;
}