#include<iostream>
#include"IntStack.h"

using namespace std;

void recur(int n)
{
    IntStack* stk = new IntStack;
    Initialize(stk, 100);

Top:
    if(n > 0)
    {
        Push(stk, n);
        n = n-1;
        goto Top;
    }
    if(!IsEmpty(stk))
    {
        Pop(stk, &n);
        cout << n << endl;
        n = n - 2;
        goto Top;
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