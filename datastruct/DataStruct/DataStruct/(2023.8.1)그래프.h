#pragma once
#include <iostream>
#include <vector>
#pragma region �׷���
//������ �������� �̷���� �ڷᱸ��
//���� vertex : ��带 �ǹ��ϸ�, �� ��忡�� �����Ͱ� ����ȴ�
//���� edge : ��ũ��� �ϸ�, ��尣�� ���踦 ��Ÿ����
//���� degree : ������ �׷������� �ϳ��� ������ ������ ������ ��
//���� ���� out-degree : ���� �׷������� ���Ǹ�, �� ��忡�� �ܺη� ���ϴ� ������ ��
//���� ���� in-degree : ���� �׷������� ���Ǹ�, �ܺ� ��忡�� ������ ������ ��
#pragma endregion

int main()
{
#pragma region ���� ���
	//�׷����� ���� ���踦 ������ �迭�� ��Ÿ���� ���
	//int buffer[4][4] = {0,};
	//int vertex = 0;
	//int edge = 0;
	//int x, y = 0;
	//std::cin >> vertex >> edge;
	//for (int i = 0; i < edge; i++)
	//{
	//	std::cin >> x >> y;
	//	buffer[x][y] = 1;
	//	buffer[y][x] = 1;
	//}
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		std::cout << buffer[i][j];
	//	}
	//	std::cout << std::endl;
	//}
#pragma endregion

#pragma region ���� ����Ʈ
	//�׷����� ���� ���踦 vector�� �迭�� ��Ÿ���� ���
	int node = 0;
	int edge = 0;

	std::vector<int> data[4];

	std::cin >> node >> edge;

	int x, y;
	for (int i = 0; i < edge; i++)
	{
		std::cin >> x >> y;
		data[x].push_back(y);
		data[y].push_back(x);
	}
	for (int i = 0; i < node; i++)
	{
		std::cout << i;
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << data[i][j];
		}
		std::cout << std::endl;
	}
#pragma endregion

	return 0;
}