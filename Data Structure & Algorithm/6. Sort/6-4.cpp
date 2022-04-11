#include<iostream>

#define swap(type, a, b) do{type temp = a; a = b; b = temp; } while(0)

using namespace std;

void straightSelectionSort(int* arr, int n)
{
    for (int i = 0; i < n ; i++)
    {
        int minIdx = i;
        for(int j = i; j < n; j++)
        {
            if(arr[minIdx] > arr[j])
                minIdx = j;
        }

        swap(int, arr[i], arr[minIdx]);

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

    straightSelectionSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << "Num[" << i << "]: " << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}