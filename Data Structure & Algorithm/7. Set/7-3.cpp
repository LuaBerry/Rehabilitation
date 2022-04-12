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

    if(IsMember(s1, 15) != -1) cout << "15 is at S1";
    else cout << "15 is not at S1";
    cout << endl;

    if(IsMember(s2, 25) != -1) cout << "25 is at S2";
    else cout << "25 is not at S2";
    cout << endl;

    if(IsMember(s3, 20) != -1) cout << "20 is at S3";
    else cout << "20 is not at S3";
    cout << endl;

    if(Equal(s1, s2)) cout << "S1 and S2 is same";
    else cout << "S1 and S2 is not same";
    cout << endl;
    
    if(Equal(s2, s3)) cout << "S2 and S3 is same";
    else cout << "S2 and S3 is not same";
    cout << endl;

    Terminate(s1);    delete s1;
    Terminate(s2);    delete s2;
    Terminate(s3);    delete s3;

    return 0;
}