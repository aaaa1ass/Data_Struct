#pragma once
#include <iostream>

template <typename T>
struct NODE {
    T data;
    NODE<T>* next;
    NODE<T>* prev;
};

template <typename T>
class DoubleLinkedList
{
private:
    NODE<T>* head;
    NODE<T>* tail;
    int size;
public:
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void Push_Front(T data)
    {
        NODE<T>* newNode = new NODE;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void Push_Back(T data)
    {
        NODE<T>* newNode = new NODE;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    void Pop_Front()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            delete(head);
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            NODE<T>* newNode = head;
            head = head->next;
            head->prev = nullptr;
            delete(newNode);
        }
        size--;
    }
    void Pop_Back()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            delete(head);
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            NODE<T>* newNode = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete(newNode);
        }
        size--;
    }
    void Clear()
    {
        if (head != nullptr)
        {
            while (head->next)
            {
                NODE<T>* newNode = head;
                head = head->next;
                delete(newNode);
            }
            delete(head);
            head = nullptr;
            tail = nullptr;
        }
    }
    ~DoubleLinkedList()
    {
        Clear();
    }
};

int main()
{
    DoubleLinkedList<int> list;

    list.Push_Back(10);
    list.Pop_Front();

}