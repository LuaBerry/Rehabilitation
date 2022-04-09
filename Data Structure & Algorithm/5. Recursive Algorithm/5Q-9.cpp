#include<iostream>
//#include"IntStack.h"

using namespace std;

int pos[8];
int flag[8];
int flag_lu[15];
int flag_ld[15];

void printPos()
{
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(pos[j] == i) cout << "O ";
            else cout << "X ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void set(int x)
{
//    IntStack* stk = new IntStack;
//    Initialize(stk, 100);
    int y;
Top:
    for(y = 0; y < 8; y++)
    {
        if(!flag[y] && !flag_lu[x + y] && !flag_ld[x + (7 - y)])
        {
            pos[x] = y;
            if(x == 7)
                printPos();
            else
            {
                flag[y] = 1;
                flag_lu[x + y] = 1;
                flag_ld[x + (7 - y)] = 1;
                
                x++;
                goto Top;

                
                flag[y] = 0;
                flag_lu[x + y] = 0;
                flag_ld[x + (7 - y)] = 0;
            }
        }
    }
}

int main()
{
    int n;
    set(0);

    return 0;
}