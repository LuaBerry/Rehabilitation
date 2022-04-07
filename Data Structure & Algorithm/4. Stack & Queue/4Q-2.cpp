#include<iostream>
#include"IntStack2.h"

using namespace std;

int main()
{
    IntStack* s;
    s = new IntStack;
    int menu, x, lr, res;

    if(Initialize(s, 8))
    {
        cout << "Failed to Initialize Stack.\n";

        return 1;
    }
    else
    {
        cout << "Initialize successful.\n";
    }
    while(true)
    {
        cout << "Current data size: L: "<< LSize(s) << " R: " << RSize(s) << " of " << Capacity(s) << "\n";
        cout << "1.Left Stack 2. Right Stack :";
        do
        {
            cin >> lr;
        } while(lr != 1 && lr != 2);

        cout << "1. Push 2. Pop 3. Peek 4. Print 5.Search 6. Clear 0. Exit: ";
        cin >> menu;

        if(!menu) break;
        if(lr - 2)
        {
            switch(menu)
            {
                case 1:
                    cout << "Input number: ";
                    cin >> x;
                    if(LPush(s, x)+1)
                        cout << "Push Successful.\n";
                    else
                        cout << "Push Failed, Please check the capacity.\n";
                    break;
                case 2:
                    if(LPop(s, &x)+1)
                        cout << "Pop Successful. Output: " << x << endl; 
                    else
                        cout << "Pop Failed, Please check if the stack is empty.\n";
                    break;
                case 3:
                    if(LPeek(s, &x)+1)
                        cout << "Peek Successful. Output: " << x << endl;
                    else
                        cout << "Peek Failed, Please check if the stack is empty.\n";
                    break;
                case 4:
                    LPrint(s);
                    break;
                case 5:
                    cout << "Input number: ";
                    cin >> x;
                    res = LSearch(s,x);
                    if(res == -1)
                    {
                        cout << "Search Failed.\n";
                    }
                    else
                    {
                        cout << x << " is at " << res << endl;
                    }
                    break;
                case 6:
                    LClear(s);
                    cout << "Clear L Stack.\n";
                    break;
            }
        }
        else
        {
            switch(menu)
            {
                case 1:
                    cout << "Input number: ";
                    cin >> x;
                    if(RPush(s, x)+1)
                        cout << "Push Successful.\n";
                    else
                        cout << "Push Failed, Please check the capacity.\n";
                    break;
                case 2:
                    if(RPop(s, &x)+1)
                        cout << "Pop Successful. Output: " << x << endl; 
                    else
                        cout << "Pop Failed, Please check if the stack is empty.\n";
                    break;
                case 3:
                    if(RPeek(s, &x)+1)
                        cout << "Peek Successful. Output: " << x << endl;
                    else
                        cout << "Peek Failed, Please check if the stack is empty.\n";
                    break;
                case 4:
                    RPrint(s);
                    break;
                case 5:
                    cout << "Input number: ";
                    cin >> x;
                    res = RSearch(s,x);
                    if(res == -1)
                    {
                        cout << "Search Failed.\n";
                    }
                    else
                    {
                        cout << x << " is at " << res << endl;
                    }
                    break;
                case 6:
                    RClear(s);
                    cout << "Clear R Stack.\n";
                    break;
            }
        }
    }

    Terminate(s);

    delete s;
    
    return 0;
}