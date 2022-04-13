#include<iostream>
#include<string>
#include"CircDbLinkedList.h"
#include"Member.h"

using namespace std;
void PrintConsole()
{
    cout << "(1)Insert node to Head. (2)Insert node to Tail. (3)Delete node at Head. (4)Delete node at Tail.\n";
    cout << "(5)Print current Node. (6)Delete current Node. (7)Search by Number. (8)Search by Name.\n";
    cout << "(9)Print all. (10)Select cur->next (11)Select cur->prev (12)Clear all. (0)Exit. : ";
}

int main()
{
    int input, x;
    string str;

    List* list = new List;
    Initialize(list);

    input = 1;

    while(input)
    {
        Member* mem;
        input = 0;
        PrintConsole();
        cin >> input;
        switch (input)
        {
            case 1: //Insert node to Head.
                cout << "Input No: "; cin >> x;
                cout << "Input Name: "; cin >> str;
                InsertFront(list, newMember(x, str));
                break;
            case 2: //Insert node to Tail.
                cout << "Input No: "; cin >> x;
                cout << "Input Name: "; cin >> str;
                InsertRear(list, newMember(x, str));
                break;
            case 3: //Delete node to Head.
                RemoveFront(list);
                break;
            case 4: //Delete node to Tail.
                RemoveRear(list);
                break;
            case 5: //Print current Node.
                PrintlnCurrent(list);
                break;
            case 6: //Delete current Node.
                RemoveCurrent(list);
                break;
            case 7: //Search by Number.
                cout << "Input No: "; cin >> x;
                mem = newMember(x, "");
                if(Search(list, mem, CompareNo))
                    PrintCurrent(list);
                else
                    cout << "No :" << x << " is not at the list.\n";
                break;
            case 8: //Search by Name.
                cout << "Input Name: "; cin >> str;
                mem = newMember(-1, str);
                if(Search(list, mem, CompareName))
                    PrintCurrent(list);
                else
                    cout << "Name :" << str << " is not at the list.\n";
                break;
            case 9: //Print all.
                PrintAll(list);
                break;
            case 10: //Cur->next
                Next(list);
                break;
            case 11://Cur->prev
                Prev(list);
                break;
            case 12:
                Clear(list);
                break;
        }
    }

    Terminate(list);
    
    return 0;
}