#include<iostream>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

using namespace std;

void Array_reverse(int* a, int n)
{
    for(int i = 0; i < n/2; i++)
        swap(int,a[i], a[(n-1)-i]);
}

int main()
{
    int* a; int n;

    cout << "Input array length :";
    cin >> n;

    a = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] :";
        cin >> a[i];
    }

    Array_reverse(a,n);
    cout << "-----Reversed Values-----\n";

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] :" << a[i] << endl;
    }

    delete[] a;

    return 0;
}