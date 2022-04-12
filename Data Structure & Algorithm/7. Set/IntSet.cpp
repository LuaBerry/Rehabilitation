#include<iostream>
#include"IntSet.h"

int Initialize(IntSet* s, int max)
{
    s->max = max;
    s->num = 0;
    s->set = new int[max];

    return 0;
}

int IsMember(const IntSet* s, int n)
{
    for(int i = 0; i < s->num; i++)
    {
        if(s->set[i] == n)
            return i;
    }
    return -1;
}

void Add(IntSet* s, int n)
{
    if(Size(s) < Capacity(s) && (IsMember(s, n) == -1))
    {
        s->set[s->num++] = n;
    }
}

void Remove(IntSet* s, int n)
{
    int idx = IsMember(s, n);
    if(idx != -1)
    {
        s->num -= 1;
        s->set[idx] = s->set[s->num];
    }
}

int Capacity(const IntSet* s)
{
    return s->max;
}

int Size(const IntSet* s)
{
    return s->num;
}

void Assign(IntSet* s1, const IntSet* s2)
{
    s1->num = 0;
    for(int i = 0; i < s1->max && i < s2->num; i++)
    {
        s1->set[s1->num++] = s2->set[i];
    }
}

int Equal(const IntSet* s1, const IntSet* s2)
{
    if(s1->num == s2->num)
    {
        for(int i = 0; i < s1->num; i++)
        {
            if(IsMember(s1, s2->set[i]) == -1)
                return 0;
        }
        return 1;
    }
    return 0;
}

IntSet* Union(const IntSet* s1, const IntSet* s2)
{
    IntSet* retSet = new IntSet;
    Initialize(retSet, (s1->num) + (s2->num));

    Assign(retSet, s1);
    for(int i = 0; i < s2->num; i++)
    {
        Add(retSet, s2->set[i]);
    }

    return retSet;
}

IntSet* Intersection(const IntSet* s1, const IntSet* s2)
{
    IntSet* retSet = new IntSet;
    Initialize(retSet, (s1->num));

    for(int i = 0; i < s2->num; i++)
        if(IsMember(s1, s2->set[i]) != -1)
            Add(retSet, s2->set[i]);

    return retSet;
}

IntSet* Difference(const IntSet* s1, const IntSet* s2)
{
    IntSet* retSet = new IntSet;
    Initialize(retSet, (s1->num));

    Assign(retSet, s1);

    for(int i = 0; i < s1->num; i++)
        if(IsMember(s2, s1->set[i]) != -1)
            Remove(retSet, s1->set[i]);

    return retSet;
}

void Print(const IntSet* s)
{
    std::cout << "{ ";
    for(int i = 0; i < s->num; i++)
    {
        std::cout << s->set[i] << " ";
    }
    std::cout << "}";
}

void Println(const IntSet* s)
{
    Print(s);
    std::cout << std::endl;
}

void Terminate(IntSet* s)
{
    delete[] s->set;
    s->max = s->num = 0;
}
