#include<iostream>
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

using namespace std;

void quickSort(int* arr, int n)
{
    int pl = 0;
    int pr = n - 1;
    int piv = arr[n / 2];
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

    cout << "Piv: " << piv << endl;
    cout << pl << " " << pr << endl;
    cout << "Left Nums: ";

    for(int i = 0; i < pl; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nMiddle Nums: ";

    for(int i = pr + 1; i < pl; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nRight Nums: ";

    for(int i = pr + 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

}

int main()
{
    int* arr;
    int n;
    cout << "Input length: ";
    cin >> n;

    arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Input num: ";
        cin >> arr[i];
    }

    quickSort(arr, n);

    delete[] arr;
    
    return 0;
}