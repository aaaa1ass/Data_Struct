#pragma once
#include <iostream>
#include <vector>

template<typename T>
class VECTOR
{
private:
	int capacity = 0;
	int size = 0;
	T* arr;
public:
	VECTOR()
	{
		capacity = 1;
		size = 0;
	}
	void Push_Back(T data)
	{
		if (size >= capacity)
		{
			capacity *= 2;
			Resize(capacity);
		}
		size++;
		T* temp = new T[size];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = arr[i];
		}
		temp[size - 1] = data;
		delete arr;
		arr = temp;
	}
	void Pop_Back()
	{
		if (size <= 0)
		{
			return;
		}
		size--;
		arr[size] = NULL;
	}
	void Clear()
	{
		T* temp = new T;
		delete arr;
		arr = temp;
		size = 0;
	}
	void Resize(int size)
	{
		capacity = size;
		T* temp = new T[size];

		for (int i = 0; i < this->size - 1; i++)
		{
			temp[i] = arr[i];
		}

		delete arr;

		arr = temp;
	}
	int Size()
	{
		return size;
	}
	//연산자 오버로딩[]
	T& operator [] (const int& value)
	{
		return arr[value];
	}
	~VECTOR()
	{
		delete arr;
	}
};
int main()
{
	VECTOR<int> v;
	v.Push_Back(10);
	v.Push_Back(20);
	v.Push_Back(30);
	v.Push_Back(40);
	v.Pop_Back();
	v.Resize(10);


	return 0;
}