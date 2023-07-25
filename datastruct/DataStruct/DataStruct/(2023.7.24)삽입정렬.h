#pragma once
#include <iostream>
#include <random>
#include <time.h>
#define SIZE 5

class Component
{
private:
	float x;
	float y;
	int* count;
public:
	//�⺻ ������
	Component()
	{
		x = 10;
		y = 20;
		count = new int;
	}

	//���� ������
	Component(const Component& clone)
	{
		this->x = clone.x;
		this->y = clone.y;

		this->count = new int;

		std::cout << "���� ������ ȣ��" << std::endl;
	}

	//�̵� ������
	Component(Component&& other)
	{
		this->x = other.x;
		this->y = other.y;

		this->count = other.count;
		other.count = nullptr;

		std::cout << "�̵� ������ ȣ��" << std::endl;
	}
};

int main()
{
#pragma region ��������
	//�� ��° �ڷ���� �����Ͽ� �� ���� �ڷ��� ���Ͽ� ������ ��ġ�� ������ �� �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ� �����ϴ� �˰���
	srand(time(NULL));
	int arr[5];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << ' ';
	}


	int temp = 0;
	int j = 0;
	for (int i = 1; i < SIZE; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > temp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = temp;
	}


	std::cout << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << ' ';
	}

#pragma endregion

#pragma region �̵� ������
	Component component1;
	Component component2 = component1;
	Component component3 = std::move(component1);
#pragma endregion

	return 0;
}