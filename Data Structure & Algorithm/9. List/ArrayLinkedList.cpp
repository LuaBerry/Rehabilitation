#include"ArrayLinkedList.h"
#include<iostream>
#include<string>

static id GetIndex(List *list)
{
    if(list->deleted == NULL)
        return ++(list->max);
    else
    {
        id temp = list->deleted;
        list->deleted = list->N[temp].fnext;
        return temp;
    }
}

static void DeleteIndex(List *list, id idx)
{
    if(list->deleted == NULL)
    {
        list->deleted = idx;
    }
    else
    {
        list->N[idx].fnext = list->deleted;
        list->deleted = idx;
    }
}

static void SetNode(Node *n, Member *x, id next)
{
    n->data = x;
    n->next = next;
    n->fnext = NULL;
}
void Initialize(List *list, int max)
{
    list->N = new Node[max];
    list->head = NULL;
    list->max = NULL;
    list->cur = NULL;
    list->deleted = NULL;
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