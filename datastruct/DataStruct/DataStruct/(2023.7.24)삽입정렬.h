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
	//기본 생성자
	Component()
	{
		x = 10;
		y = 20;
		count = new int;
	}

	//복사 생성자
	Component(const Component& clone)
	{
		this->x = clone.x;
		this->y = clone.y;

		this->count = new int;

		std::cout << "복사 생성자 호출" << std::endl;
	}

	//이동 생성자
	Component(Component&& other)
	{
		this->x = other.x;
		this->y = other.y;

		this->count = other.count;
		other.count = nullptr;

		std::cout << "이동 생성자 호출" << std::endl;
	}
};

int main()
{
#pragma region 삽입정렬
	//두 번째 자료부터 시작하여 그 앞의 자료들과 비교하여 삽입할 위치를 지정한 후 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘
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

#pragma region 이동 생성자
	Component component1;
	Component component2 = component1;
	Component component3 = std::move(component1);
#pragma endregion

	return 0;
}