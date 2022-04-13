#ifndef __LinkedList
#define __LinkedList

#include "Member.h"

struct Node
{
    Member* data;
    Node* next;
};

struct List
{
    Node* head;
    Node* cur;
};


void Initialize(List *list);

Node* Search(List *list, const Member *n, int compare(const Member *x, const Member *y));

void InsertFront(List *list, Member *n);

void InsertRear(List *list, Member *n);

void RemoveFront(List *list);

void RemoveRear(List *list);

void RemoveCurrent(List *list);

void Clear(List *list);

void PrintCurrent(const List *list);

void PrintlnCurrent(const List *list);

void PrintAll(const List *list);

void Terminate(List *list);

#endif