#pragma once
#include <iostream>

typedef struct NODE {
    int data;
    NODE* next;
} NODE;

void AddNode(NODE* target, int data)
{
    NODE* node = new NODE;
    node->data = data;
    node->next = target->next;
    target->next = node;
}

void ShowNode(NODE* target)
{
    std::cout << target->data << std::endl;
    if (target->next)
        ShowNode(target->next);
    else
        return;
}

void RemoveNode(NODE* target)
{
    NODE* node = target->next;
    if (node->next == nullptr)
        target->next = nullptr;
    else
        target->next = node->next;
    delete(node);
}

void ReleaseNode(NODE* target)
{
    if (target == nullptr)
        return;
    else
        ReleaseNode(target->next);

    delete(target);

}

void ReleaseNode_(NODE* target)
{
    NODE* curPtr = target;
    while (curPtr != nullptr)
    {
        NODE* nextPtr = curPtr->next;
        delete(curPtr);
        curPtr = nextPtr;
    }
}

int main()
{
    // 단일 연결 리스트
    /*
    NODE* dummy = new NODE;
    NODE* node1 = new NODE;
    NODE* node2 = new NODE;

    dummy->next = node1;

    dummy->next->data = 10;
    dummy->next->next = node2;

    dummy->next->next->data = 20;
    dummy->next->next->next = nullptr;

    NODE* currentPtr = dummy;

    while (currentPtr != nullptr)
    {
        currentPtr = currentPtr->next;
        if(currentPtr != nullptr)
            std::cout << currentPtr->data << std::endl;
    }

    delete dummy;
    delete node1;
    delete node2;

    */

    // 단일 연결 리스트 함수
    NODE* dummy = new NODE;
    dummy->next = nullptr;

    AddNode(dummy, 100);
    AddNode(dummy, 200);
    AddNode(dummy, 300);

    RemoveNode(dummy->next);

    ShowNode(dummy->next);

    ReleaseNode(dummy);

}