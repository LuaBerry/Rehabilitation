#include<iostream>
#include"BitSet.h"

int IsMember(const BitSet s, int n)
{
    return s & SetOf(n);
}

void Add(BitSet* s, int n)
{
    *s |= SetOf(n);
}

void Remove(BitSet* s, int n)
{
    *s &= ~SetOf(n);
}

int Size(const BitSet s)
{
    BitSet temp = s;
    int count = 0;

    while(temp)
    {
        temp &= (temp-1);
        count++;
    }

    return count;
}

void Print(const BitSet s)
{
    std::cout << "{ ";
    for(int i = 0; i < BitSetMax; i++)
    {
        if(IsMember(s, i))
            std::cout << i << " ";
    }
    std::cout <<"}";
}

void Println(const BitSet s)
{
    Print(s);
    std::cout << "\n";
}