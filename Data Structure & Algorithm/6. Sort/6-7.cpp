#include<iostream>

using namespace std;

void shellSort(int* arr, int n)
{
    int h;
    for(h = 1; h < n / 3; h = h * 3 + 1);
    for(; h > 0 ; h /= 3)
    {
        int start = 0;
        cout << h << endl;
        for (int i = h; i < n ; i += 1)
        {
            int value = arr[i];
            int j;
            for (j = i - h; (j >= 0) && (arr[j] > value) ;j -= h)
                arr[j + h] = arr[j];
            arr[j + h] = value;
        }
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

    shellSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << "Num[" << i << "]: " << arr[i] << endl;
    }

    delete[] arr;
    
    return 0;
}