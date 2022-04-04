#include<iostream>

using namespace std;

int main()
{
    int n;

    cout << "Input Height :";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n-i; j++)
            cout << " ";
            
        for(int j = 0; j < i*2+1; j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}