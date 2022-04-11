#include<iostream>
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

using namespace std;

int n;

void quickSort(int* arr, int pl, int pr)
{
    int piv = arr[(pr + pl) / 2];
    int left = pl;
    int right = pr;
    while(pl <= pr)
    {
        for( ; arr[pl] < piv; pl++);
        for( ; arr[pr] > piv; pr--);
        if(pl <= pr)
        {
            swap(int, arr[pl], arr[pr]);
            pl++; pr--;
        }
    }
    cout << "num: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(left < pr) quickSort(arr, left, pr);
    if(pl < right) quickSort(arr, pl, right);
}

int main()
{
    int* arr;

    cout << "Input length: ";
    cin >> n;

    arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Input num: ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << "num: " << arr[i] << endl;
    }

    delete[] arr;
        
    return 0;
}