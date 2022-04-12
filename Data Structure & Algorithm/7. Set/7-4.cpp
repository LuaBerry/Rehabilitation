#include<iostream>
#include"IntSet.h"

using namespace std;

void PrintConsole(const IntSet* s1, const IntSet* s2)
{
    cout << "s1 = ";
    Println(s1);
    cout << "s2 = ";
    Println(s2);

    cout << "(1)Insert at S1. (2)Delete at S1. (3)Search at S1. (4) S1 -> S2. (5)Set Calculations.\n";
    cout << "(6)Insert at S2. (7)Delete at S2. (8)Search at S2. (9) S2 -> S1. (0)Exit: "; 
}

void PrintSetCalculations(const IntSet* s1, const IntSet* s2, IntSet* temp)
{
    cout << "s1 == s2 = " << ((Equal(s1, s2)) ? "true" : "false") << "\n";

    Assign(temp, Intersection(s1, s2));
    cout <<"s1 & s2 = "; Println(temp);
    Assign(temp, Union(s1, s2));
    cout <<"s1 | s2 = "; Println(temp);
    Assign(temp, Difference(s1, s2));
    cout <<"s1 - s2 = "; Println(temp);
}

int main()
{
    IntSet *s1, *s2, *temp;

    s1 = new IntSet;
    s2 = new IntSet;
    temp = new IntSet;

    Initialize(s1, 512);
    Initialize(s2, 512);
    Initialize(temp, 1024);

    int n = 1;
    int x = 0;

    while(n)
    {
        PrintConsole(s1, s2);
        cin >> n;

        switch (n)
        {

        case 1: //Insert at S1
            cout << "Data: ";
            cin >> x;
            Add(s1, x);
            break;        
        case 2: //Delete at S1
            cout << "Data: ";
            cin >> x;
            Remove(s1, x);
            break;
        case 3: //Search at S1
            cout << "Data: ";
            cin >> x;
            if(IsMember(s1, x) == -1) cout << x << " is not at s1.\n";
            else cout << x << " is at s1.\n";
            break;
        case 4: //S1->S2
            Assign(s2, s1);
            break;
        case 5: //Set Calculations
            PrintSetCalculations(s1, s2, temp);
            break;
        case 6: //Insert at S2
            cout << "Data: ";
            cin >> x;
            Add(s2, x);
            break;
        case 7: //Delete at S2
            cout << "Data: ";
            cin >> x;
            Remove(s2, x);
            break;
        case 8: //Search at S2
            cout << "Data: ";
            cin >> x;
            if(IsMember(s2, x) == -1) cout << x << " is not at s2.\n";
            else cout << x << " is at s2.\n";
            break;
        case 9: //S2->S1
            Assign(s2, s1);
            break;
        }
    }

    Terminate(s1);    delete s1;
    Terminate(s2);    delete s2;

    return 0;
}