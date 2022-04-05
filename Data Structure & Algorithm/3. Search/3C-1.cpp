#include<iostream>

using namespace std;

int sum(int n, int m)
{
    return n+m;
}

int mul(int n, int m)
{
    return n*m;
}

void func(int (*calc)(int, int))
{
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            cout << (*calc)(i,j) << " ";
        }

        cout << endl;
    }
}

int main()
{
    cout << "Sum\n";
    func(sum);
    cout << "Mul\n";
    func(mul);

    return 0;
}