#include <iostream>

#pragma region 이진 탐색 트리 (BST)
//임의의 키를 가진 원소를 삽입, 삭제, 검색할 때 효율적인 트리
struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* Insert(Node * root,int data)
{
	if (root == nullptr)
	{
		root = new Node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if(root->data > data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}
//Node* Delete(Node* root,int key)
//{
//	if (root->data == key)
	//{
	//	if (root->left == nullptr && root->right == nullptr)
	//	{
	//		delete root;
	//	}
	//	else if (root->left && root->right == nullptr)
	//	{
	//		root->data = root->left->data;
	//		delete root->left;
	//		root->left = nullptr;
	//	}
	//	else if (root->left == nullptr && root->right)
	//	{
	//		root->data = root.
	//	}
	//}
//	else if (root->data > key)
//	{
//		root->left = Delete(root->left, key);
//	}
//	else
//	{
//		root->right = Delete(root->right, key);
//	}
//}
void* Delete(Node* root, int key)
{
	if (root == nullptr)
		return;
	
	Node* node = root;
	Node* prev = nullptr;
	while (node->data != key)
	{
		prev = node;
		if (root->data > key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	if (prev == nullptr)
	{
		delete root;
		root = nullptr;
	}
	else if (node->left == nullptr && node->right == nullptr)
	{
		if (prev->left == node)
		{
			prev->left = nullptr;
			delete node;
		}
		else
		{
			prev->right = nullptr;
			delete node;
		}
	}
	else if (node->left && node->right == nullptr)
	{
		if (prev->left == node)
		{
			prev->left = node->left;
			delete node;
		}
		else
		{
			prev->right = node->left;
			delete node;
		}
	}
	else if (node->left == nullptr && node->right)
	{
		if (prev->left == node)
		{
			prev->left = node->right;
			delete node;
		}
		else
		{
			prev->right = node->right;
			delete node;
		}
	}
	else
	{
		prev = node->right;
		while (prev->left != nullptr)
		{
			prev = prev->left;
		}
		node->data = prev->data;

	}
}
int FindMax(Node* root)
{
	if (root == nullptr)
		return 0xcccccccc;
	//Node* node = root;
	//while (node->right != nullptr)
	//{
	//	node = node->right;
	//}
	//return node->data;
	if (root->right == nullptr)
		return root->data;
	else
		return FindMax(root->left);
}
int FindMin(Node* root)
{
	if (root == nullptr)
		return 0xcccccccc;	
	//Node* node = root;
	//while (node->left != nullptr)
	//{
	//	node = node->left;
	//}
	//return node->data;
	if (root->left == nullptr)
		return root->data;
	else
		return FindMin(root->left);
}
#pragma endregion


int main()
{
	Node* root = nullptr;
	root = Insert(root,10);
	root = Insert(root, 5);

	std::cout << FindMax(root);
	//std::cout << FindMin(root);
	
	return 0;
}

