#ifndef __IntSet
#define __Intset

struct IntSet
{
    int max;
    int num;
    int* set;
};

int Initialize(IntSet* s, int max);

int IsMember(const IntSet* s, int n);

void Add(IntSet* s, int n);

void Remove(IntSet* s, int n);

int Capacity(const IntSet* s);

int Size(const IntSet* s);

void Assign(IntSet* s1, const IntSet* s2);

int Equal(const IntSet* s1, const IntSet* s2);

IntSet* Union(const IntSet* s1, const IntSet* s2);

IntSet* Intersection(const IntSet* s1, const IntSet* s2);

IntSet* Difference(const IntSet* s1, const IntSet* s2);

void Print(const IntSet* s);

void Println(const IntSet* s);

void Terminate(IntSet* S);

#endif