#include<iostream>
#define MAX_BUFFER 100

using namespace std;

int* buffer = new int[MAX_BUFFER];

void merge(int* arr, int left, int right)
{
    if(left < right)
    {
        int center = (left + right) / 2;

        merge(arr, left, center);
        merge(arr, center + 1, right);

        int arrP = 0;
        int i, j;
        for(i = left, j = center + 1; i <= center && j <= right; )
        {
            if(arr[i] < arr[j])
                buffer[arrP++] = arr[i++];
            else
                buffer[arrP++] = arr[j++];
        }
        while(i <= center) buffer[arrP++] = arr[i++];
        while(j <= right) buffer[arrP++] = arr[j++];

        int k = 0;
        for(int i = left; i <= right; i++)
        {
            arr[i] = buffer[k++];
        }
    }
}

void mergeSort(int* arr, int n)
{
    merge(arr, 0, n - 1);
}

int main()
{
    int n;
    int* arr;

    cout << "Input length: ";
    cin >> n;

    arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Input num: ";
        cin >> arr[i];
    }

    cout << "a";

    mergeSort(arr, n);

    cout << "b";
    for(int i = 0; i < n; i++)
    {
        cout << "num: " << arr[i] << endl;
    }

    delete[] arr;
    delete[] buffer;

    return 0;
}