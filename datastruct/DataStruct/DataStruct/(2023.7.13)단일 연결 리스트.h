#pragma once
#include <iostream>

typedef struct NODE {
    int data;
    NODE* next;
} NODE;
class LinkedList
{
private:
    NODE* head;
    NODE* tail;

    int size;
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;

        size = 0;
    }
    void push_front(int data)
    {
        NODE* node = new NODE;
        node->data = data;
        node->next = nullptr;

        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        size++;
    }
    void push_back(int data)
    {
        NODE* node = new NODE;
        node->data = data;
        node->next = nullptr;

        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    int Size()
    {
        return size;
    }
    ~LinkedList()
    {

    }
};

int main()
{
    LinkedList list;

    list.push_front(10);
    list.push_back(20);

    std::cout << list.Size();
}