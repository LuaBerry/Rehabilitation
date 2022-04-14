#ifndef __BinTree
#define __BinTree

#include"Member.h"

struct Node
{
    Member* m;
    Node* left;
    Node* right;
};

void Initialize(Node *root);

Node* Search(Node *root, const Member *n, int compare(const Member *x, const Member *y));

Node* Add(Node *root, Member *n);

void Remove(Node *root);

void PrintAll(const Node *root);

void Terminate(Node *root);

#endif