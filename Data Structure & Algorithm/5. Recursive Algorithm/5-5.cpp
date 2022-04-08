#include<iostream>
#include"IntStack.h"

using namespace std;

void recur(int n)
{
    IntStack* stk = new IntStack;
    Initialize(stk, 100);

    while(1)
    {
        if(n > 0)
        {
            Push(stk, n);
            n = n - 1;
            continue;
        }
        if(!IsEmpty(stk))
        {
            Pop(stk, &n);
            cout << n << endl;
            n = n - 2;
            continue;
        }
        break;
    }

    Terminate(stk);
    delete stk;
}

int main()
{
    int n;

    cout << "Input number: ";
    cin >> n;

    recur(n);
} 