#include<iostream>

using namespace std;

int linear_search2(int* a, int n, int key)
{
    int idx = -1;
    a[n] = key;

    for(int i = 0; !(a[i] == key) || !(idx = i); i++);

    return idx == n ? -1 : idx;
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
    idx = linear_search2(a, n, key);

    if(idx+1)
        cout << key << " is at a[" << idx << "].\n";
    else
        cout << "Searching failed, try other value.\n";

    delete[] a;

    return 0;
}