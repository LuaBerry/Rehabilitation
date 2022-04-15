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

Node* Search(Node *root, const Member *m);

Node* Add(Node *root, Member *n);

int Remove(Node **root, Member *n);

void PrintAll(const Node *root);

void Terminate(Node *root);

#endif