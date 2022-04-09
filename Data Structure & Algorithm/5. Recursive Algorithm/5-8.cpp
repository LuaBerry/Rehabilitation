#include<iostream>

using namespace std;

int pos[8];
int flag[8];

void printPos()
{
    for(int i = 0; i < 8; i++)
    {
        cout << pos[i] << " ";
    }
    cout << "\n";
}

void set(int n)
{
    for(int i = 0; i < 8; i++)
    {
        if(!flag[i])
        {
            pos[n] = i;
            if(n == 7)
                printPos();
            else
            {
                flag[i] = 1;
                set(n+1);
                flag[i] = 0;
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