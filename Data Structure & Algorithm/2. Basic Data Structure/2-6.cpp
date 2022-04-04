#include<iostream>
#include<random>
using namespace std;

int maxof(const int* a, int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(max < a[i]) max = a[i];
    }
    return max;
}

int main()
{
    int* a; int n;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,1000);

    cout << "Input array length\n";
    cin >> n;

    a = new int[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = dis(gen);
    }

    cout << "Number generated as :\n";
    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] : " << a[i] << endl;
    }
    cout << "Max is : " << maxof(a, n) << endl;

    delete[] a;

    return 0;
}