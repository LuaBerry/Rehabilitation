#include<iostream>

using namespace std;

int main()
{
    int n, max;
    int* a;
    int cnt = 0;
    int input;

    cout << "Input length: ";
    cin >> max;

    a = new int[max];

    do
    {
        cout << "Input Number: ";
        cin >> n;
        a[(cnt++) % max] = n;

        cout << "Continue? (1. Yes / 2. No): ";
        cin >> input;
    } while (input == 1);
    
    cout << "Input total :" << cnt << ". Saved " << max << " number(s).\n";

    n = cnt - max;
    if(n < 0)
        n = 0;
    for(;n < cnt; n++)
    {
        cout << a[n % max] << " ";
    }

    delete[] a;

    return 0;
}