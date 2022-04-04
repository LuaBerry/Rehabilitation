#include<iostream>

using namespace std;

int maxof(const int* a, int n)
{
    int max = a[0];
    for(int i = 0; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }

    return max;
}

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

    cout << "Max value is " << maxof(a, n) << endl;

    delete[] a;

    return 0;
}