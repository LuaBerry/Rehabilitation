#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "Member.h"

#define idxNULL -1

typedef int id;

struct Node
{
    Member* data;
    id next;
    id fnext;
};

struct List
{
    Node* N;
    id head;
    id max;
    id deleted;
    id cur;
};


void Initialize(List *list, int max);

id Search(List *list, const Member *n, int compare(const Member *x, const Member *y));

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

#endif