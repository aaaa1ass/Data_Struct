#include <iostream>
#define SIZE 9
int arr[SIZE] = { 5,3,8,4,9,1,2,6,7 };
void QuickSort(int data[], int start, int end)
{	
	//원소가 1개
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
		//새 노드 생성
		Node* newNode = new Node;

		//새 노드의 key값 저장
		newNode->key = key;

		//새 노드의 value값 저장
		newNode->value = value;

		//새 노드의 next 초기화
		newNode->next = nullptr;

		//새 노드의 주솟값 반환
		return newNode;
	}
	int HashFunction(int key)
	{
		return key % 5;
	}
	void Insert(int key, int value)
	{
		int index = HashFunction(key);

		Node* newNode = CreateNode(key,value);

		if (bucket[index].count == 0)
		{
			bucket[index].head = newNode;
			bucket[index].count = 1;
		}
		else
		{
			Node* node = bucket[index].head;
			for (int i = 0; i < bucket[index].count; i++)
				node = node->next;
			node = newNode;
			bucket[index].count++;
		}

	}
	void Remove(int key)
	{

	}
	void Search(int key)
	{

	}

};
int main()
{
#pragma region 퀵 정렬
	//기준점을 획득한 다음 해당 기준점을 기준으로 배열을 나누고 한 쪽에는 기준점보다 작은 항목들이 위치하고 다른 쪽에는 기준점보다 큰 항목들이 위치한다
	//나뉘어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여, 모든 배열이 기본 배열이 될 때까지 반복하는 알고리즘이다

	//QuickSort(arr,0,SIZE - 1);
	//for (int i = 0; i < SIZE; i++)
	//{
	//	std::cout << arr[i] << ' ';
	//}
#pragma endregion

#pragma region 해시 테이블
	// (key, value)로 데이터를 저장할 수 있는 자료구조 중 하나로 빠르게 데이터를 검색할 수 있는 자료구조

	//평균 시간 복잡도 O(1)

	//해시 충돌 해결 방법

	//체이닝 기법
	//각 해시 버킷을 연결리스트로 구성하는 방식
	//해시 충돌 발생 시 동일한 해시 값에 해당하는 데이터들을 연결리스트로 연결하여 저장

	//개방 주소법
	/*충돌 발생 시 빈 버킷에 데이터를 저장하는 방식
	빈 버킷을 결정하는 방식에 따라 다른 구현 방식
	선형 탐사: 충돌 발생 시 앞에서부터 차례대로 빈 버킷을 찾아 값을 저장하는 방식
	이차 탐사: 충돌 발생 시 2^2, 2^3 만큼 떨어진 빈 버킷을 찾아 값을 저장하는 방식
	이중 해싱: 해시 값을 한번 더 해시 함수에 넣어 다른 해싯값을 도출하는 방식*/
#pragma endregion

	return 0;
}