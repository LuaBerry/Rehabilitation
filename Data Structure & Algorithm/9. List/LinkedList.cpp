#include"LinkedList.h"
#include<iostream>

static void SetNode(Node* n, Member* data, Node* next)
{
    n->data = data;
    n->next = next;
}


void Initialize(List *list)
{
    list->cur = NULL;
    list->head = NULL;
}

Node* Search(List *list, const Member *n, int compare(const Member *x, const Member *y))
{
    Node* node = list->head;
    while(node != NULL)
    {
        if(compare(node->data, n))
        {
            list->cur = node;
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void InsertFront(List *list, Member *n)
{
    Node* node = new Node;
    SetNode(node, n, list->head);
    list->head = node;
    list->cur = node;
}

void InsertRear(List *list, Member *n)
{
    Node* tail = list->head;
    if(tail == NULL) return;
    
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    Node* node = new Node;
    SetNode(node, n, NULL);
    tail->next = node;
    list->cur = node;
}

void RemoveFront(List *list)
{
    Node* node = list->head;
    if(node != NULL)
    {
        list->head = list->head->next;
        delete node;
    }
    list->cur = list->head;
}

void RemoveRear(List *list)
{
    Node* tailfront = list->head;
    if(tailfront == NULL) return;
    Node* tail = tailfront->next;
    if(tail == NULL) RemoveFront(list);
    while(tail->next != NULL)
    {
        tailfront = tail;
        tail = tailfront->next;
    }
    tailfront->next = NULL;
    delete tail;
    list->cur = tailfront;
}

void RemoveCurrent(List *list)
{
    Node* node = list->cur;
    Node* curfront = list->head;
    if(curfront = NULL) return;
    while(curfront != NULL)
    {
        if(curfront->next = list->cur)
            break;
        curfront = curfront->next;
    }

    curfront->next = node->next;
    delete node;
}

void Clear(List *list)
{
    while(list->head != NULL)
    {
        RemoveFront(list);
    }
    list->cur = NULL;
}

void PrintCurrent(const List *list)
{
    if(list->cur != NULL)
        PrintMember((list->cur)->data);
}

void PrintlnCurrent(const List *list)
{
    PrintCurrent(list);
    std::cout << "\n";
}

void PrintAll(const List *list)
{
    Node* node = list->head;
    while(node != NULL)
    {
        PrintMember(node->data);
        std::cout << "\n";
        node = node->next;
    }

}

void Terminate(List *list)
{
    Clear(list);
}