#ifndef __ChainHash
#define __ChainHash

#include"member.h"

struct Node
{
    Member* m;
    Node* prev;
    Node* next;
};

struct ChainHash
{
    int size;
    Node** table;
};

void Initialize(ChainHash *hash, int max);

Node* Search(ChainHash *h, const Member *m);

int Add(ChainHash *h, Member *n);

int Remove(ChainHash *h, Member *n);

void Clear(ChainHash *h);

void PrintAll(ChainHash *h);

void Terminate(ChainHash *h);

#endif