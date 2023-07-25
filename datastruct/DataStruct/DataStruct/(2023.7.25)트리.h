#pragma once
#include <iostream>

#pragma region 트리
//그래프의 일종으로 정점과 간선을 이용하여 데이터의 배치 형태를 추상화한 자료구조
struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data, Node* leftChild, Node* rightChild)
{
	// 노드 생성
	Node* NewNode = new Node;

	//data 저장
	NewNode->data = data;

	// left, right 설정
	NewNode->left = leftChild;
	NewNode->right = rightChild;

	//주솟값 반환
	return NewNode;
}
//전위 순회 root->left->right
void RootLeftRight(Node* root)
{
	if (root != nullptr)
	{
		std::cout << root->data << ' ';
		RootLeftRight(root->left);
		RootLeftRight(root->right);
	}
}
//중위 순회 left->root->right
void LeftRootRight(Node* root)
{
	if (root != nullptr)
	{
		LeftRootRight(root->left);
		std::cout << root->data << ' ';
		LeftRootRight(root->right);
	}
}
//후위 순회 left->right->root
void LeftRightRoot(Node* root)
{
	if (root != nullptr)
	{
		LeftRightRoot(root->left);
		LeftRightRoot(root->right);
		std::cout << root->data << ' ';
	}
}
#pragma endregion


int main()
{
	Node* Node7 = CreateNode(7, nullptr, nullptr);
	Node* Node6 = CreateNode(6, nullptr, nullptr);
	Node* Node5 = CreateNode(5, nullptr, nullptr);
	Node* Node4 = CreateNode(4, nullptr, nullptr);
	Node* Node3 = CreateNode(3, Node6, Node7);
	Node* Node2 = CreateNode(2, Node4, Node5);
	Node* Node1 = CreateNode(1, Node2, Node3);

	RootLeftRight(Node1);
	std::cout << std::endl;
	LeftRootRight(Node1);
	std::cout << std::endl;
	LeftRightRoot(Node1);
	std::cout << std::endl;

	return 0;
}