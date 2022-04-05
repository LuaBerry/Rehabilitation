#include<iostream>

using namespace std;

int linear_search(const int* a, int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int* a;
    int n, key, idx;
    cout << "Linear Search\n";
    cout << "Input length: ";
    cin >> n;
    
    a = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }

    
    cout << "Searching value: ";
    cin >> key;
    idx = linear_search(a, n, key);

    if(idx+1)
        cout << key << " is at a[" << idx << "].\n";
    else
        cout << "Searching failed, try other value.\n";

    delete[] a;

    return 0;
}