#ifndef __ClosedHash
#define __ClosedHash

#include"member.h"

enum Status{
  Occupied, Empty, Deleted
};

struct Node
{
    Member* m;
    Status stat;
};

struct ClosedHash
{
    int size;
    Node* table;
};

void Initialize(ClosedHash *hash, int max);

Node* Search(ClosedHash *h, const Member *m);

int Add(ClosedHash *h, Member *n);

int Remove(ClosedHash *h, Member *n);

void Clear(ClosedHash *h);

void PrintAll(ClosedHash *h);

void Terminate(ClosedHash *h);

#endif