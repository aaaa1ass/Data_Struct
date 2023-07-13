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
        size++;
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
    }
    void push_back(int data)
    {
        NODE* node = new NODE;
        node->data = data;
        node->next = nullptr;
        size++;
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node ;
            tail = node;
        }
    }
    void insert(NODE* prev_node, int data)
    {

    }
    void pop_back()
    {

    }
    void pop_front()
    {   
        NODE* node = head;
        if (head == tail)
        { 
            head = nullptr;
            tail = nullptr;
            delete(node);
        }
        else
        {
            head = node->next;
            delete(node);
        }
        
        

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