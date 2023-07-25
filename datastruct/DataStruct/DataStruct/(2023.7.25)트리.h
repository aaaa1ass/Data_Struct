#pragma once
#include <iostream>

#pragma region Ʈ��
//�׷����� �������� ������ ������ �̿��Ͽ� �������� ��ġ ���¸� �߻�ȭ�� �ڷᱸ��
struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data, Node* leftChild, Node* rightChild)
{
	// ��� ����
	Node* NewNode = new Node;

	//data ����
	NewNode->data = data;

	// left, right ����
	NewNode->left = leftChild;
	NewNode->right = rightChild;

	//�ּڰ� ��ȯ
	return NewNode;
}
//���� ��ȸ root->left->right
void RootLeftRight(Node* root)
{
	if (root != nullptr)
	{
		std::cout << root->data << ' ';
		RootLeftRight(root->left);
		RootLeftRight(root->right);
	}
}
//���� ��ȸ left->root->right
void LeftRootRight(Node* root)
{
	if (root != nullptr)
	{
		LeftRootRight(root->left);
		std::cout << root->data << ' ';
		LeftRootRight(root->right);
	}
}
//���� ��ȸ left->right->root
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