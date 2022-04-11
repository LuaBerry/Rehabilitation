#include<iostream>

#define MAX_HEAP 1000
#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)
#define max(x, y) x > y ? x : y;

#define lchild(x) (x * 2) + 1
#define rchild(x) (x * 2) + 2

using namespace std;

void heapize(int* arr, int left, int right)
{
    int temp = arr[left];
    int child, parent;
    for(parent = left; parent < (right + 1) / 2; parent = child)
    {
        int cl = lchild(parent);
        int cr = rchild(parent);
        child = (cr <= right && arr[cr] > arr[cl]) ? cr : cl;

        if(temp >= arr[child])
            break;

        arr[parent] = arr[child];
    }

    arr[parent] = temp;
}

void heapSort(int* arr, int n)
{
    for(int i = (n - 1) / 2; i >= 0; i--)
        heapize(arr, i, n-1);
    for(int i = n - 1; i > 0; i--)
    {
        swap(int, arr[0], arr[i]);
        heapize(arr, 0, i - 1);
    }
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

    heapSort(arr, n);

    cout << "b";
    for(int i = 0; i < n; i++)
    {
        cout << "num: " << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}