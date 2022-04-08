#include<iostream>

using namespace std;

void recur(int n)
{
    if(n > 0)
    {
        recur(n - 1);
        cout << n << endl;
        recur(n - 2);
    }
}

int main()
{
    int n;

    cout << "Input number: ";
    cin >> n;

    recur(n);
} 