#include<iostream>

using namespace std;

long long factorial(int n)
{
    if(n == 1) return 1;
    return n * factorial(n-1);
}

int main()
{
    int n;
    cout << "Input number: ";
    cin >> n;

    cout << n <<"! is " << factorial(n) << endl;

    return 0;
}