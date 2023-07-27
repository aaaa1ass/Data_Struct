#include <iostream>
#define SIZE 10


int main()
{
#pragma region 계수 정렬
	// 데이터의 값을 직접 비교하지 않고 숫자가 몇 개 있는 지 세어 저장한 다음 정렬하는 알고리즘
	// int item[SIZE] = {1,3,3,4,5,5,5,1,2,2};
	// int arrr[SIZE] = { 0 };
	// int arr[5] = { 0 };
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	arr[item[i] - 1]++;
	// }
	// 
	// int index = 0;
	// for (int i = 0; i < 5; i++)
	// {
	// 	for (int j = 0; j < arr[i]; j++)
	// 	{
	// 		item[index++] = i + 1;
	// 	}
	// }
	// 
	// for (int i = 0; i < SIZE; i++)
	// {
	// 	std::cout << item[i] << ' ';
	// }


#pragma endregion

#pragma region 퀵 정렬
	//기준점을 획득한 다음 해당 기준점을 기준으로 배열을 나누고 한 쪽에는 기준점보다 작은 항목들이 위치하고 다른 쪽에는 기준점보다 큰 항목들이 위치한다
	//나뉘어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여, 모든 배열이 기본 배열이 될 때까지 반복하는 알고리즘이다
	int arr[9] = { 5,3,8,4,9,1,2,6,7 };
	int l = 1;
	int r = 8;
	while (1)
	{
		while (arr[0] > arr[l])
		{
			l++;
		}
		while (arr[0] < arr[r])
		{
			r--;
		}
		if (r < l)
			break;
		std::swap(arr[l], arr[r]);
	}
	std::swap(arr[0], arr[r]);

	for (int i = 0; i < 9; i++)
	{
		std::cout << arr[i] << ' ';
	}
#pragma endregion

	 
	return 0;
}