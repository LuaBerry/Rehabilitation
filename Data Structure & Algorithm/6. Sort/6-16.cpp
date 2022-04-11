#include<iostream>
#define MAX 101
using namespace std;

int freq[MAX];


void countSort(int* arr, int n)
{
    int* temp = new int[n];

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;
    for(int i = 1; i < MAX; i++)
        freq[i] += freq[i - 1];
    
    for(int i = 0; i < MAX; i++)
    {
        cout << i << ": " << freq[i] << " ";
        if((i % 11) == 10) cout << endl; 
    }

    for(int i = n - 1; i >= 0; i--)
        temp[--freq[arr[i]]] = arr[i];

    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
    cout << "5";
    delete[] temp;
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

    countSort(arr, n);

    cout << "b";

    for(int i = 0; i < n; i++)
    {
        cout << "num: " << arr[i] << endl;
    }

    delete[] arr;


    return 0;
}