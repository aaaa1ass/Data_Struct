#pragma once
#include <iostream>
#include <vector>
#pragma region 그래프
//정점과 간선으로 이루어진 자료구조
//정점 vertex : 노드를 의미하며, 각 노드에는 데이터가 저장된다
//간선 edge : 링크라고 하며, 노드간의 관계를 나타낸다
//차수 degree : 무방향 그래프에서 하나의 정점에 인접한 정점의 수
//진출 차수 out-degree : 방향 그래프에서 사용되며, 한 노드에서 외부로 향하는 간선의 수
//진입 차수 in-degree : 방향 그래프에서 사용되며, 외부 노드에서 들어오는 간선의 수
#pragma endregion

int main()
{
#pragma region 인접 행렬
	//그래프의 연결 관계를 이차원 배열로 나타내는 방식
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

#pragma region 인접 리스트
	//그래프의 연결 관계를 vector의 배열로 나타내는 방식
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