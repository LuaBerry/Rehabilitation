#include<iostream>

using namespace std;

int gcd(int x, int y)
{
    if(!y)
        return x;
    return gcd (y, x % y);
}

int main()
{
    int n, m;
    cout << "Input num1: ";
    cin >> n;
    cout << "Input num2: ";
    cin >> m;

    cout << "GCD of " << n << " and " << m << " is " << gcd(n,m) << endl;

    return 0;
}