#include<iostream>
#include"BinTree.h"
#include"Member.h"

static void SetNode(Node *node, Member *m, Node *left, Node *right)
{
    node->m = m;
    node->left = left;
    node->right = right;
}

Node* Search(Node *root, const Member *m)
{
    int cmp;

    if(root == NULL) return NULL;
    else if((cmp = CompareNo(root->m, m)) == 0) return root;
    else if(cmp > 0) Search(root->left, m);
    else Search(root->right, m);
}

Node* Add(Node *root, Member *m)
{
    int cmp;
    if(root == NULL)
    {
        root = new Node;
        SetNode(root, m, NULL, NULL); 
    }
    else if(!(cmp = CompareNo(root->m, m)))
    {
        std::cout << "Same member is in the Tree.\n";
        return NULL;
    }
    else if(cmp > 0) root->left = Add(root->left, m);
    else if(cmp < 0) root->right = Add(root->right, m);

    return root;
}

int Remove(Node **root, Member *m)
{

    Node **node = root;
    int cmp;
    while(1)
    {
        if(root == NULL) return -1;
        else if((cmp = CompareNo((*node)->m, m)) == 0) break;
        else if(cmp > 0) node = &((*node)->left);
        else node = &((*node)->right);
    }

    Node *child, *temp, **left;
    if(*node == NULL) return -1;

    if((*node)->left == NULL)
        child = (*node)->right;
    else
    {
        *left = (*node)->left;
        while((*left)->right !=NULL)
            *left = (*left)->right;
        child = *left;
        *left = child->left;
        child->left = (*node)->left;
        child->right = (*node)->right;
    }
    temp = *node;
    *node = child;

    delete temp;

    return 0;
}

void PrintAll(const Node *root)
{
    if(root == NULL) return;

    PrintAll(root->left);
    PrintMember(root->m);
    PrintAll(root->right);
}

void Terminate(Node *root)
{
    if(root == NULL) return;
    
    Terminate(root->left);
    Terminate(root->right);
    delete root;
}