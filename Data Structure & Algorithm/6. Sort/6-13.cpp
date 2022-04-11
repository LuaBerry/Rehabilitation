#include<iostream>

using namespace std;

void merge(int* arrA, int na, int* arrB, int nb)
{
    int* arrResult = new int[na + nb];
    int i, j;
    int arrP = 0;
    for(i = 0, j = 0; i < na && j < nb; )
    {
        if(arrA[i] < arrB[j])
            arrResult[arrP++] = arrA[i++];
        else
            arrResult[arrP++] = arrB[j++];
    }
    while(i < na) arrResult[arrP++] = arrA[i++];
    while(j < nb) arrResult[arrP++] = arrB[j++];

    for(i = 0; i < na + nb; i++)
    {
        cout << arrResult[i] << " ";
    }
    cout << endl;
}

int main()
{
    int* arrA;
    int* arrB;
    int na, nb;
    cout << "Input A length: ";
    cin >> na;

    arrA = new int[na];

    cout << "Input B length: ";
    cin >> nb;

    arrB = new int[nb];

    for(int i = 0; i < na; i++)
    {
        cout << "Input A num: ";
        cin >> arrA[i];
    }
    for(int i = 0; i < nb; i++)
    {
        cout << "Input B num: ";
        cin >> arrB[i];
    }

    merge(arrA, na, arrB, nb);

    delete[] arrA;
    delete[] arrB;

    return 0;
}