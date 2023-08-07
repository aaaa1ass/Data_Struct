#include <iostream>

#pragma region 원형 연결 리스트
//단순 연결 리스트에서 마지막 노드가 리스트의 첫 번째 노드를 가리키는 리스트 구조로 원형
struct Node
{
	int data;
	Node* next;
};
class CircleLinkedList
{
private:
	int count;

public:
	CircleLinkedList(int m_count = 1)
	{
		count = m_count;
	}
	Node* Push_Front(Node* head,int data)
	{
		Node* node = new Node;
		node->data = data;
		if (head == nullptr)
		{
			node->next = node;
			head = node;
		}
		else
		{
			node->next = head->next;
			head->next = node;
		}
		return head;
	}
	Node* Push_Back(Node* head, int data)
	{
		Node* node = new Node;
		node->data = data;
		if (head == nullptr)
		{
			node->next = node;
			head = node;
		}
		else
		{
			node->next = head->next;
			head->next = node;
			head = node;
		}
		return head;
	}
	void Information(Node * head)
	{
		if (head == nullptr)
			return;
		Node* CurrentNode = head->next;
		while (CurrentNode != head)
		{
			std::cout << CurrentNode->data << std::endl;
			CurrentNode = CurrentNode->next;
		}
		std::cout << head->data << std::endl;

	}
};
#pragma endregion


int main()
{
	Node* head = nullptr;

	CircleLinkedList c;

	head = c.Push_Front(head, 20);
	head = c.Push_Front(head, 10);
	head = c.Push_Back(head, 30);

	c.Information(head);



	return 0;
}

