#include"member.h"
#include"ClosedHash.h"
#include<iostream>

static int GetHash(ClosedHash *hash, int n)
{
    return ((n + 1) % (hash->size));
}

static int IsFull(ClosedHash *hash)
{
    for(int i = 0; i < hash->size; i++)
    {
        if(hash->table[i].stat != Occupied)
            return 0;
    }
    return 1;
}

static void SetNode(ClosedHash *hash, int index, Member* m, Status stat)
{
    Node* n = &(hash->table[index]);
    n->m = m;
    n->stat = stat;
}

void Initialize(ClosedHash *hash, int max)
{
    hash->size = max;
    hash->table = new Node[max];
    for(int i = 0; i < max; i++)
    {
        hash->table[i].m = NULL;
        hash->table[i].stat = Empty;
    }
}

Node* Search(ClosedHash *h, const Member *m)
{
    int idx = GetHash(h, m->no);

    while((h->table[idx]).stat != Empty)
    {
        if((h->table[idx]).stat == Occupied)
            if(!CompareNo(h->table[idx].m, m))
            {
                return &(h->table[idx]);
            }
        idx = GetHash(h, idx);
    }

    return 0;
}

int Add(ClosedHash *h, Member *m)
{
    if(IsFull(h)) return 0;
    int idx = GetHash(h, m->no);

    int flag = 1;
    while((h->table[idx]).stat == Occupied)
        idx = GetHash(h, idx);

    SetNode(h, idx, m, Occupied);
    return 1;
}

int Remove(ClosedHash *h, Member *m)
{
    int idx = GetHash(h, m->no);

    int flag = 1;
    while((h->table[idx]).stat != Empty)
    {
        if((h->table[idx]).stat == Occupied)
            if(!CompareNo(h->table[idx].m, m))
            {
                h->table[idx].m = NULL;
                h->table[idx].stat = Deleted;
                return 1;
            }
        idx = GetHash(h, idx);
    }
    return 0;
}

void Clear(ClosedHash *h)
{
    for(int i = 0; i < h->size; i++)
    {
        h->table[i].m = NULL;
        h->table[i].stat = Empty;
    }
}

void PrintAll(ClosedHash *h)
{
    for(int i = 0; i < h->size; i++)
    {
        std::cout << i << " -> ";
        if((h->table[i]).stat == Occupied)
            PrintMember(h->table[i].m);
        std::cout << "\n";
    }
}

void Terminate(ClosedHash *h)
{
    h->size = 0;
    delete h->table;
}