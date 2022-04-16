#include"ChainHash.h"
#include"member.h"
#include<iostream>

using namespace std;

static int GetHash(ChainHash *hash, int n)
{
    return n % (hash->size);
}

static void SetNode(Node* node, Member* m, Node* prev, Node* next)
{
    node->m = m;
    node->prev = prev;
    node->next = next;
}

void Initialize(ChainHash *hash, int max)
{
    hash->size = max;
    hash->table = new Node*[max];
    for(int i = 0; i < max; i++)
    {
        Node* n = new Node;
        SetNode(n, NULL, NULL, NULL);
        hash->table[i] = n;
    }
}

Node* Search(ChainHash *h, const Member *m)
{
    int idx= GetHash(h, m->no);
    
    Node* node = (h->table[idx])->next;
    while(node != NULL)
    {
        if(!CompareNo(node->m, m))
            return node;
        
        node = node->next;
    }

    return NULL;
}

int Add(ChainHash *h, Member *m)
{
    if(Search(h, m) != NULL) return 0;

    int idx = GetHash(h, m->no);

    Node* node = new Node;
    Node* temp = (h->table[idx])->next;
    SetNode(node, m, h->table[idx], temp);
    (h->table[idx])->next = node;
    if(temp != NULL) temp->prev = node;

    return 1;
}

int Remove(ChainHash *h, Member *m)
{
    int idx = GetHash(h, m->no);
    Node* node = (h->table[idx])->next;
    int flag = 1;
    while(node != NULL)
    {
        if(!CompareNo(node->m, m))
            { flag = 0; break; }
        node = node->next;
    }
    if(flag) return 0;
    
    if(node->prev != NULL)
        (node->prev)->next = node->next;
    if(node->next != NULL)
        (node->next)->prev = node->prev;
    delete node;
    return 1;
}

void Clear(ChainHash *h)
{
    Node* node;

    for(int i = 0; i < h->size; i++)
    {
        node = (h->table[i])->next;
        while(node != NULL)
        {
            Remove(h, node->m);
            node = (h->table[i])->next;
        }
    }
}

void PrintAll(ChainHash *h)
{
    Node* node;

    for(int i = 0; i < h->size; i++)
    {
        std::cout << i << " -> ";
        node = (h->table[i])->next;
        while(node != NULL)
        {
            PrintMember(node->m);
            std::cout << " ";
            node = node->next;
        }
        std::cout <<"\n";
    }
}

void Terminate(ChainHash *h)
{
    Clear(h);
    for(int i = 0; i < h->size; i++)
        delete h->table[i];
    delete h->table;
    h->size;
}