#include<iostream>

using namespace std;

void straightInsertionSort(int* arr, int n)
{
    for (int i = 1; i < n ; i++)
    {
        int value = arr[i];
        int j;
        for (j = i - 1; (j >= 0) && (arr[j] > value) ;j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = value;

        //cout to see the process
        for(int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

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

    straightInsertionSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << "Num[" << i << "]: " << arr[i] << endl;
    }

    delete[] arr;
    
    return 0;
}