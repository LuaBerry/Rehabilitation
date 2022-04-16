#include<iostream>
#include<string>
#include"ChainHash.h"
#include"Member.h"

using namespace std;

void PrintConsole()
{
    cout <<"(1)Insert. (2)Remove. (3)Search. (4)Print. (5)Clear. (0)Exit :";
}

int main()
{
    int input = 1;
    int x;
    string str;

    Node* temp;
    ChainHash* hash = new ChainHash;

    Initialize(hash, 13);

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
            Add(hash, newMember(x, str));
            break;
        case 2:
            cout << "Input No: "; cin >> x;
            if(Remove(hash, newMember(x, "")))
                cout << "Remove Success\n;";
            else cout << "Remove Failed.\n";
            break;
        case 3:
                cout << "Input No: "; cin >> x;
                if((temp = Search(hash, newMember(x, ""))) == NULL)
                    cout << "Not Found.";
                else
                    PrintMember(temp->m);
                cout << endl;
            break;
        case 4:
            PrintAll(hash);
            break;
        case 5:
            Clear(hash);
            break;
        }
    }
    Terminate(hash);
    return 0;
}