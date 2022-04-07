#include<iostream>
#include"IntStack.h"

using namespace std;

int main()
{
    IntStack* s;
    s = new IntStack;
    int menu, x;

    if(Initialize(s, 64))
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
        cout << "Current data size: "<< Size(s) << " of " << Capacity(s) << "\n";
        cout << "1. Push 2. Pop 3. Peek 4. Print 0. Exit: ";
        cin >> menu;

        if(!menu) break;

        switch(menu)
        {
            case 1:
                cout << "Input number: ";
                cin >> x;
                if(Push(s, x)+1)
                    cout << "Push Successful.\n";
                else
                    cout << "Push Failed, Please check the capacity.\n";
                break;
            case 2:
                if(Pop(s, &x)+1)
                    cout << "Pop Successful. Output: " << x << endl; 
                else
                    cout << "Pop Failed, Please check if the stack is empty.\n";
                break;
            case 3:
                if(Peek(s, &x)+1)
                    cout << "Peek Successful. Output: " << x << endl;
                else
                    cout << "Peek Failed, Please check if the stack is empty.\n";
                break;
            case 4:
                Print(s);
                break;
        }
    }

    Terminate(s);

    delete s;
    
    return 0;
}