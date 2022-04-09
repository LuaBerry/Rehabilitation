#include<iostream>

using namespace std;

int pos[8];
int flag[8];
int flag_lu[15];
int flag_ld[15];

void printPos()
{
    for(int i = 0; i < 8; i++)
    {
        cout << pos[i] << " ";
    }
    cout << "\n";
}

void set(int x)
{
    for(int y = 0; y < 8; y++)
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
                set(x+1);
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