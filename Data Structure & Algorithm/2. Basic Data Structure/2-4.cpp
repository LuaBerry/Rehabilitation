#include<iostream>

using namespace std;

int main()
{
    int n;
    int* a;

    cout << "Set array length: ";
    cin >> n;
    a = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] : ";
        cin >> a[i];
    }

    cout << "-----Values-----\n";

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] : " << a[i] << endl;
    } 
}