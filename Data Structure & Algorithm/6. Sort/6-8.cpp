#include<iostream>
#define swap(type, x, y) {type temp = x; x = y; y = temp;} while(0);

using namespace std;

void quickSort(int* arr, int n)
{
    int pl = 0;
    int pr = n - 1;
    int piv = (pl + pr) / 2;
    while(pl < pr)
    {
        for(;arr[pl] < piv;pl++);
        for(;arr[pr] > piv;pr--);
        swap(int, arr[pl], arr[pr]);
    }
}

int main()
{

}