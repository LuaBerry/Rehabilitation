#include<iostream>
#include"IntSet.h"

using namespace std;

int main()
{
    IntSet *s1, *s2, *s3;
    s1 = new IntSet;
    s2 = new IntSet;
    s3 = new IntSet;
    Initialize(s1, 24);
    Initialize(s2, 24);
    Initialize(s3, 24);

    Add(s1, 10);
    Add(s1, 15);
    Add(s1, 20);
    Add(s1, 25);

    Assign(s2, s1);
    Add(s2, 12);
    Remove(s2, 20);

    Assign(s3, s2);
    
    cout << "S1: "; Println(s1);
    cout << "S2: "; Println(s2);
    cout << "S3: "; Println(s3);

    Terminate(s1);    delete s1;
    Terminate(s2);    delete s2;
    Terminate(s3);    delete s3;

    return 0;
}