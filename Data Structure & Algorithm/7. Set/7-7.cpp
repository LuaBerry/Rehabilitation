#include<iostream>
#include"BitSet.h"

using namespace std;

void PrintConsole(const BitSet s1, const BitSet s2)
{
    cout << "s1 = ";
    Println(s1);
    cout << "s2 = ";
    Println(s2);

    cout << "(1)Insert at S1. (2)Delete at S1. (3)Search at S1. (4) S1 -> S2. (5)Set Calculations.\n";
    cout << "(6)Insert at S2. (7)Delete at S2. (8)Search at S2. (9) S2 -> S1. (0)Exit: "; 
}

void PrintSetCalculations(const BitSet s1, const BitSet s2)
{
    cout << "s1 == s2 = " << ((s1 == s2) ? "true" : "false") << "\n";

    cout <<"s1 & s2 = "; Println(s1 & s2);
    cout <<"s1 | s2 = "; Println(s1 | s2);
    cout <<"s1 - s2 = "; Println(s1 & ~s2);
}

int main()
{
    BitSet s1 = BitSetNull;
    BitSet s2 = BitSetNull;

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
            Add(&s1, x);
            break;        
        case 2: //Delete at S1
            cout << "Data: ";
            cin >> x;
            Remove(&s1, x);
            break;
        case 3: //Search at S1
            cout << "Data: ";
            cin >> x;
            if(IsMember(s1, x)) cout << x << " is at s1.\n";
            else cout << x << " is not at s1.\n";
            break;
        case 4: //S1->S2
            s2 = s1;
            break;
        case 5: //Set Calculations
            PrintSetCalculations(s1, s2);
            break;
        case 6: //Insert at S2
            cout << "Data: ";
            cin >> x;
            Add(&s2, x);
            break;
        case 7: //Delete at S2
            cout << "Data: ";
            cin >> x;
            Remove(&s2, x);
            break;
        case 8: //Search at S2
            cout << "Data: ";
            cin >> x;
            if(IsMember(s2, x)) cout << x << " is at s2.\n";
            else cout << x << " is not at s2.\n";
            break;
        case 9: //S2->S1
            s1 = s2;
            break;
        }
    }

    return 0;
}