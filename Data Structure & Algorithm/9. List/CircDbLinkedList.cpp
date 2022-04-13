#include"CircDbLinkedList.h"
#include<iostream>

static void SetNode(Node* n, Member* data, Node* prev, Node* next)
{
    n->data = data;
    n->next = next;
    n->prev = prev;
}


void Initialize(List *list)
{
    Node* dummy = new Node;
    list->cur = dummy;
    list->head = dummy;
    dummy->next = dummy->prev = dummy;
}

int IsEmpty(List *list)
{
    return (list->head)->next == list->head;
}

Node* Search(List *list, const Member *n, int compare(const Member *x, const Member *y))
{
    Node* node = (list->head)->next;
    while(node != list->head)
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

void InsertAfter(List *list, Node *n, Member *m)
{
    Node* node = new Node;
    Node* next = n->next;
    SetNode(node, m, n, next);
    n->next = next->prev = node;
    list->cur = node;
}

void InsertFront(List *list, Member *m)
{
    InsertAfter(list, list->head, m);
}

void InsertRear(List *list, Member *m)
{
    InsertAfter(list, (list->head)->prev, m);
}

void Remove(List *list, Node *n)
{
    (n->prev)->next = n->next;
    (n->next)->prev = n->prev;
    list->cur = n->prev;

    delete n;
    if(list->cur == list->head)
        list->cur = list->head->next;

}
void RemoveFront(List *list)
{
    if(!IsEmpty(list))
        Remove(list, (list->head)->next);
}

void RemoveRear(List *list)
{
    if(!IsEmpty(list))
        Remove(list, (list->head)->prev);
}

void RemoveCurrent(List *list)
{
    if(list->cur != list->head)
        Remove(list, list->cur);
}

void Clear(List *list)
{
    while(!IsEmpty(list))
    {
        RemoveFront(list);
    }
}

void PrintCurrent(List *list)
{
    if(!IsEmpty(list))
        PrintMember((list->cur)->data);
}

void PrintlnCurrent(List *list)
{
    PrintCurrent(list);
    std::cout << "\n";
}

void PrintAll(List *list)
{
    if(IsEmpty(list)) return;
    Node* node = list->head->next;
    while(node != list->head)
    {
        PrintMember(node->data);
        std::cout << "\n";
        node = node->next;
    }
}

void PrintAllReverse(List *list)
{
    if(IsEmpty(list)) return;
    Node* node = list->head->prev;
    while(node != list->head)
    {
        PrintMember(node->data);
        std::cout << "\n";
        node = node->prev;
    }
}
int Next (List *list)
{
    if(!IsEmpty(list) && (list->cur)->next != list->head)
    {
        list->cur = list->cur->next;
        return 1;
    }
    else return 0;
}

int Prev (List *list)
{
    if(!IsEmpty(list) && (list->cur)->prev != list->head)
    {
        list->cur = list->cur->prev;
        return 1;
    }
    else return 0;
}

void Terminate(List *list)
{
    Clear(list);
}