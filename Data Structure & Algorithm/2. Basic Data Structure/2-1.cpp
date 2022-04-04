#include<iostream>

using namespace std;

int main()
{
    int n = 5;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    cout << "-----Values-----\n";
    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: " << a[i] << endl;
    }
}