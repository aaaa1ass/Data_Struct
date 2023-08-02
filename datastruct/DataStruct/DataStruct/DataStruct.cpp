#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfsGraph[6];
std::vector<int> dfsGraph[6];
bool dfsCheck[6] = { false };
bool bfsCheck[6] = { false };

#pragma region BFS 너비 우선 탐색
//시작 노드를 방문한 후 시작 노드에 있는 인접한 모든 노드들을 탐색하는 방법
//더이상 방문하지 않은 노드가 없을 때까지, 방문하지 않은 모든 노드에 대해서도 BFS를 적용
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

#pragma region DFS 깊이 우선 탐색
//시작점부터 다음 경로로 넘어가기 전에 해당 경로를 완벽하게 탐색하고 넘어가는 방법
void DFS(int start)
{
	std::cout << start << std::endl;
	dfsCheck[start] = true;

	for (int i = 0;i < dfsGraph[start].size(); i++)
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