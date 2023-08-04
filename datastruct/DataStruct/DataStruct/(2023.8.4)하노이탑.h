#pragma once
#include <iostream>
#pragma region 하노이 탑
// 규칙
// 1. 큰 원반이 아래, 작은 원반이 위로 가게해서 3개의 기둥 사이에 원반을 옮기는 것
// 2. 원반은 1번에 1개씩 이동한다
// 3. 최소한의 이동으로 목표 기둥으로 옮긴다
//
void Hanoi(int n, char A, char B, char C)
{
	if (n <= 1)
	{
		std::cout << A << "->" << C << std::endl;
	}
	else
	{
		Hanoi(n - 1, A, C, B);
		std::cout << A << "->" << C << std::endl;
		Hanoi(n - 1, B, A, C);
	}
}
#pragma endregion

class A
{
public:
	void Print()
	{
		std::cout << "A class" << std::endl;
	}
	virtual A* GetThis()
	{
		return this;
	}
};
class B : public A
{
public:
	void Print()
	{
		std::cout << "B class" << std::endl;
	}
	virtual B* GetThis()
	{
		return this;
	}
};

int main()
{
#pragma region 하노이 탑
	//int n;
	//std::cin >> n;
	//Hanoi(n,'A','B','C');
#pragma endregion

#pragma region 공변 반환값
	A aClass;
	B bClass;

	A& ref = bClass;
	bClass.GetThis()->Print();
	ref.GetThis()->Print();

	std::cout << typeid(bClass.GetThis()).name() << std::endl;
	std::cout << typeid(ref.GetThis()).name() << std::endl;
#pragma endregion


	return 0;
}

