#include"ArrayLinkedList.h"
#include<iostream>
#include<string>

static id GetIndex(List *list)
{
    if(list->deleted == idxNULL)
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
    if(list->deleted == idxNULL)
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
    n->fnext = idxNULL;
}

static Node* GetNode(List *list, id idx)
{
    return &(list->N[idx]);
}

void Initialize(List *list, int max)
{
    list->N = new Node[max];
    list->head = idxNULL;
    list->max = idxNULL;
    list->cur = idxNULL;
    list->deleted = idxNULL;
}

id Search(List *list, const Member *n, int compare(const Member *x, const Member *y))
{
    id index = list->head;
    while(index != idxNULL)
    {
        std::cout << index << " = index\n";
        PrintMember(GetNode(list, index)->data);
        if(compare(GetNode(list, index)->data , n))
        {
            std::cout << "in";
            list->cur = index;
            return index;
        }
        index = GetNode(list, index)->next;
    }
    return idxNULL;
}

void InsertFront(List *list, Member *n)
{
    id index = list->head;
    list->head = list->cur = GetIndex(list);

    std::cout << list->cur << " = list->cur\n";
    SetNode(&list->N[list->head], n, index);
}

void InsertRear(List *list, Member *n)
{
    id lastIndex = list->head;

    if(lastIndex == idxNULL)
    {
        InsertFront(list, n);
        return;
    }

    while((list->N[lastIndex]).next != idxNULL)
    {
        lastIndex = (list->N[lastIndex]).next;
    }

    (list->N[lastIndex]).next = list->cur = GetIndex(list);
    SetNode(&list->N[list->cur], n, idxNULL);
}

void RemoveFront(List *list)
{
    id index = list->head;
    if(index != idxNULL)
    {
        list->head = GetNode(list, index)->next;
        DeleteIndex(list, index);
    }
    list->cur = list->head;
}

void RemoveRear(List *list)
{
    id tailfront = list->head;
    if(tailfront == idxNULL) return;
    id tail = GetNode(list, tailfront)->next;
    if(tail == idxNULL) RemoveFront(list);
    while(GetNode(list, tail)->next != idxNULL)
    {
        tailfront = tail;
        tail = GetNode(list, tail)->next;
    }
    GetNode(list, tailfront)->next = idxNULL;
    DeleteIndex(list, tail);
    list->cur = tailfront;
}

void RemoveCurrent(List *list)
{
    id curnode = list->cur;
    id curfront = list->head;

    if(curfront == idxNULL) return;
    if (curnode == curfront) RemoveFront(list);
    while(curfront != idxNULL)
    {
        if(GetNode(list, curfront)->next == curnode)
            break;
        curfront = GetNode(list, curfront)->next;
    }

    GetNode(list, curfront)->next = GetNode(list, list->cur)->next;
    DeleteIndex(list, list->cur);
    list->cur = curfront;
}

void Clear(List *list)
{
    while(list->head != idxNULL)
    {
        RemoveFront(list);
    }
    list->cur = idxNULL;
}

void PrintCurrent(List *list)
{
    if(list->cur != idxNULL)
        PrintMember(GetNode(list, list->cur)->data);
}

void PrintlnCurrent(List *list)
{
    PrintCurrent(list);
    std::cout << "\n";
}

void PrintAll(List *list)
{
    id index = list->head;
    while(index != idxNULL)
    {
        PrintMember(GetNode(list, index)->data);
        std::cout << "\n";
        index = GetNode(list, index)->next;
    }

}

void Terminate(List *list)
{
    Clear(list);
}