#pragma once
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfsGraph[6];
std::vector<int> dfsGraph[6];
bool dfsCheck[6] = { false };
bool bfsCheck[6] = { false };

#pragma region BFS �ʺ� �켱 Ž��
//���� ��带 �湮�� �� ���� ��忡 �ִ� ������ ��� ������ Ž���ϴ� ���
//���̻� �湮���� ���� ��尡 ���� ������, �湮���� ���� ��� ��忡 ���ؼ��� BFS�� ����
std::queue<int> queue;
void BFS(int start)
{
	queue.push(start);
	bfsCheck[start] = true;
	while (!queue.empty())
	{
		int temp = queue.front();
		queue.pop();

		std::cout << temp << std::endl;

		for (int i = 0; i < bfsGraph[temp].size(); i++)
		{
			if (bfsCheck[bfsGraph[temp][i]] == false)
			{
				queue.push(bfsGraph[temp][i]);
				bfsCheck[bfsGraph[temp][i]] = true;
			}
		}
	}
}
#pragma endregion

#pragma region DFS ���� �켱 Ž��
//���������� ���� ��η� �Ѿ�� ���� �ش� ��θ� �Ϻ��ϰ� Ž���ϰ� �Ѿ�� ���
void DFS(int start)
{
	dfsCheck[start] = true;
	std::cout << start << std::endl;

	for (int i = 0; i < dfsGraph[start].size(); i++)
	{
		if (dfsCheck[dfsGraph[start][i]] == false)
		{
			DFS(dfsGraph[start][i]);
		}
	}
}
#pragma endregion



int main()
{
#pragma region BFS
	bfsGraph[0].push_back(1);
	bfsGraph[0].push_back(2);
	bfsGraph[1].push_back(0);
	bfsGraph[1].push_back(3);
	bfsGraph[2].push_back(0);
	bfsGraph[2].push_back(4);
	bfsGraph[2].push_back(5);
	bfsGraph[3].push_back(1);
	bfsGraph[4].push_back(2);
	bfsGraph[5].push_back(2);
	//BFS(0);
#pragma endregion

#pragma region DFS
	dfsGraph[0].push_back(1);
	dfsGraph[0].push_back(2);
	dfsGraph[0].push_back(3);
	dfsGraph[1].push_back(0);
	dfsGraph[1].push_back(4);
	dfsGraph[2].push_back(0);
	dfsGraph[3].push_back(0);
	dfsGraph[3].push_back(5);
	dfsGraph[4].push_back(1);
	dfsGraph[5].push_back(3);
	DFS(0);
#pragma endregion



	return 0;
}