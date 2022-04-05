#include<iostream>
#include<algorithm>
#include<random>

using namespace std;

int bin_search(const int* a, int n, int key)
{
    int pl = 0;
    int pr = n-1;
    int pc;

    int count = 0;

    while(count++, pl <= pr)
    {
        pc = (pl + pr) / 2;
        
        if(count++, a[pc] < key)
            pl = pc + 1;
        else if(count++, a[pc] > key)
            pr = pc - 1;
        else
        {
            cout << "Binary Search Count :" << count << endl;
            return pc;
        }
    }

    cout << "Binary Search Count :" << count << endl;

    return -1;
}

int linear_search2(int* a, int n, int key)
{
    int idx = -1;
    a[n] = key;
    
    int count = 0;

    for(int i = 0; count++, !(a[i] == key) || !(idx = i); i++);

    cout << "Linear Search Count :" << count << endl;
    return idx == n ? -1 : idx;
}

int main()
{
    int* a;
    int n, key, idx;
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dis(0, 10000);

    cout << "Binary Search\n";
    cout << "Input length: ";
    cin >> n;
    
    a = new int[n];

    for(int i = 0; i < n; i++)
    {
        a[i] = dis(gen);
    }

    sort(a, a+n);
    
    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: " << a[i] << endl;
    }

    cout << "Searching value: ";
    cin >> key;
    idx = bin_search(a, n, key);

    if(idx+1)
        cout << key << " is at a[" << idx << "].\n";
    else
        cout << "Searching failed, try other value.\n";

    idx = linear_search2(a, n, key);

    delete[] a;

    return 0;
}