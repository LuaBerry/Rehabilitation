#include<iostream>

using namespace std;

//n: disk num, x: starting point y: destination
void hanoi(int n, int x, int y)
{
    //m: middle point = int 1~3 except x and y
    int m = 6 - x - y;
    if(n > 1) hanoi (n-1, x, m);
    cout << "Move disk[" << n << "] from " << x << " to " << y << ".\n";
    if(n > 1) hanoi (n-1, m, y);
}

int main()
{
    int n;

    cout << "Set the height of hanoi tower: ";
    cin >> n;

    hanoi(n, 1, 3);

    return 0;
}