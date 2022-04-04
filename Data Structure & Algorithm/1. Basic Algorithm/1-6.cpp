#include<iostream>

using namespace std;

int main()
{
    int i, n;
    int sum;
    cout << "1부터 n까지의 합을 구합니다.\n";
    
    do{
    cout << "n의 값 : ";
    cin >> n;
    } while(n<= 0);

    sum = 0;
    i = 1;
    while(i<=n)
        sum += i++;
    
    cout << "1부터 " << n << "까지의 합은 " << sum << "입니다." << endl;

    return 0;
}