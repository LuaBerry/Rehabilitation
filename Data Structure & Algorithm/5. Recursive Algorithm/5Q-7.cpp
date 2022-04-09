#include<iostream>
#include"IntStack.h"

using namespace std;

//n: disk num, x: starting point y: destination
void hanoi(int n, int x, int y)
{
    int disknum = n;
    int start = x;
    int dest = y;
    //m: middle point = int 1~3 except x and y
    int m;
    IntStack* diskNumStk = new IntStack;
    IntStack* startStk = new IntStack;
    IntStack* destStk = new IntStack;
    Initialize(diskNumStk, 100);
    Initialize(startStk, 100);
    Initialize(destStk, 100);

    while(1)
    {
        m = 6 - start - dest;
        if(disknum > 0)
        {
            Push(diskNumStk, disknum);
            Push(startStk, start);
            Push(destStk, dest);
            disknum -= 1;
            dest = m;

            continue;
        }
        if(!IsEmpty(diskNumStk))
        {
            Pop(diskNumStk, &disknum);
            Pop(startStk, &start);
            Pop(destStk, &dest);
            cout << "Move disk[" << disknum << "] from " << start << " to " << dest << ".\n";
            start = 6 - start - dest;
            disknum -= 1;

            continue;
        }

        break;
    }
}

int main()
{
    int n;

    cout << "Set the height of hanoi tower: ";
    cin >> n;

    hanoi(n, 1, 3);

    return 0;
}