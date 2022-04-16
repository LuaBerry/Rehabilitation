#include<iostream>
#include<string>
#include"BinTree.h"
#include"Member.h"

using namespace std;

void PrintConsole()
{
    cout <<"(1)Insert. (2)Remove. (3)Search. (4)Print. (0)Exit :";
}

int main()
{
    int input = 1;
    int x;
    string str;
    Node* root = NULL;
    Node* temp;
    while(input)
    {
        input = 0;
        PrintConsole();
        cin >> input;
        temp = NULL;
        switch (input)
        {
        case 1:
            cout << "Input No: "; cin >> x;
            cout << "Input Name: "; cin >> str;
            root = Add(root, newMember(x, str));
            break;
        case 2:
            cout << "Input No: "; cin >> x;
            if(Remove(&root, newMember(x, "")) == -1)
                cout << "Remove Failed\n;";
            else cout << "Remove success.\n";
            break;
        case 3:
                cout << "Input No: "; cin >> x;
                if((temp = Search(root, newMember(x, ""))) == NULL)
                    cout << "Not Found.\n";
                else
                    PrintMember(temp->m);
            break;
        case 4:
            PrintAll(root);
            break;
        }
    }
    Terminate(root);
    return 0;
}