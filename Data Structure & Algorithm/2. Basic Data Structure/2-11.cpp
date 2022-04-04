#include<iostream>

using namespace std;

int main()
{
    int prime[500];
    int prime_ptr = 0;
    int flag;
    prime[prime_ptr++] = 2;
    prime[prime_ptr++] = 3;
    for(int n = 5; n < 1000; n +=2)
    {
        flag = 0;
        for(int i = 1; prime[i] * prime[i] <= n; i++)
        {
            if(n % prime[i] == 0)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
            prime[prime_ptr++] = n;
    }
    for(int i = 0; i < prime_ptr; i++)
    {
        cout << prime[i] << " ";
        if(i && i % 10 == 0)
            cout << endl;
    }

    return 0;
}