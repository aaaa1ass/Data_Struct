#pragma once
#include <iostream>
#include <limits>
#define SIZE 5
int main()
{
#pragma region �ð� ���⵵
	// ��ǻ�� ���α׷��� �Է� ���� ���� ���� �ð��� ������踦 ��Ÿ���� ô��

	// big-o ǥ���
	// �Է°��� ��ȭ�� ���� ������ ������ �� ���� Ƚ���� ���� �ð��� �󸶸�ŭ �ɸ��� �� ��Ÿ���� ô��
	//�־��� ��츦 ����ϹǷ�, ���α׷��� ����Ǵ� �������� �ҿ�Ǵ� �־��� �ð����� ����� �� �ֱ� ����

	//O(1) ��� �ð����⵵
	/*
	�Է°��� �����ϴ��� �ð��� �þ�� �ʴ� �ð� ���⵵
	ex) �迭�� �ε��� ����
	*/

	// O(n) ���� �ð� ���⵵
	/*
	�Է°��� �����Կ� ���� �ð� ���� ���� ������ �����ϴ� �ð� ���⵵
	*/

	// O(log n) �α� �ð� ���⵵
	/*
	�Է� �������� ũ�Ⱑ Ŀ������ ó�� �ð��� �α� ��ŭ ª������ �ð� ���⵵
	*/

	//O(n^2) 2�� �ð� ���⵵
	/*
	�Է°��� �����Կ� ���� �ð��� n�� �������� ������ �����ϴ� �ð� ���⵵
	ex)���߹ݺ���
	*/

	//O(2^n) ���� �޼��� �ð� ���⵵
	/*
	ex)�Ǻ���ġ ����
	*/


#pragma endregion

#pragma region ��ǰ ����
	//���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���
	//�ð� ���⵵ : O(n^2)

	//  int array[SIZE] = { 4, 3, 2, 1, 0 };
	//  
	//  for (int i = 0; i < SIZE - 1; i++)
	//  {
	//  	for (int j = 0; j < SIZE - i - 1; j++)
	//  	{
	//  		if (array[j] > array[j + 1])
	//  		{
	//  			std::swap(array[j], array[j + 1]);
	//  		}
	//  	}
	//  }

	//  for (int i = 0; i < SIZE; i++)
	//  {
	//  	std::cout << array[i] << std::endl;
	//  }


#pragma endregion

#pragma region ���� ����
	//���ĵ��� ���� �����͵鿡 ���� 
	// ���� ���� �����͸� ã�Ƽ� ���� �տ� �ִ� �����Ϳ� ��ȯ�ϴ� �˰���

	//�ð� ���⵵ O(n^2)

	int selectBuffer[SIZE] = { 5,4,3,2,1 };

	int min;
	int select;

	for (int i = 0; i < SIZE - 1; i++)
	{
		min = selectBuffer[i];
		select = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (min > selectBuffer[j])
			{
				min = selectBuffer[j];
				select = j;
			}
		}
		std::swap(selectBuffer[i], selectBuffer[select]);

	}

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << selectBuffer[i] << std::endl;
	}

#pragma endregion

	return 0;
}