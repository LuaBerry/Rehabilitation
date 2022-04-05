#include<iostream>

#define VMAX 21

using namespace std;

struct PhysCheck
{
    string name;
    int height;
    double vision;
};

double ave_height(const PhysCheck a[], int n)
{
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += (a++->height);
    }
    return sum/n;
}

int main()
{
    PhysCheck* phys;
    int n;
    cout << "Input number: ";
    cin >> n;

    phys = new PhysCheck[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Name: "; cin >> phys[i].name;
        cout << "Height: "; cin >> phys[i].height;
        cout << "Vision: "; cin >> phys[i].vision;
    }
    cout << "-----Result-----\n";
    for(int i = 0; i < n; i++)
    {
        cout << "Name: " << phys[i].name << endl;
        cout << "Height: " << phys[i].height << endl;
        cout << "Vision: " << phys[i].vision << endl;
    }
    cout << "Average height: " << ave_height(phys, n);

    delete[] phys;

    return 0;
}