#ifndef __CircDbLinkedList
#define __CircDbLinkedList

#include "Member.h"

struct Node
{
    Member* data;
    Node* next;
    Node* prev;
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

void PrintCurrent(List *list);

void PrintlnCurrent(List *list);

void PrintAll(List *list);

void Terminate(List *list);

int Next(List *);

int Prev(List *);

#endif