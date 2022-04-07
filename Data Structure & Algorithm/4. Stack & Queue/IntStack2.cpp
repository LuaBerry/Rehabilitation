#include<iostream>
#include "IntStack2.h"

int Initialize(IntStack* s, int max)
{
    s->lptr = 0;
    s->rptr = max - 1;
    s->stk = new int[max];
    if(s->stk == NULL)
    {
        std::cout << "NULL";
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int LPush(IntStack* s, int x)
{
    if(IsFull(s))
    {
        return -1;
    }
    s->stk[s->lptr++] = x;

    return 0;
}

int LPop(IntStack* s, int* x)
{
    if(IsLEmpty(s))
    {
        return -1;
    }
    *x = s->stk[--s->lptr];
    return 0;
}

int LPeek(const IntStack* s, int* x)
{
    if(IsLEmpty(s))
    {
        return -1;
    }

    *x = s->stk[(s->lptr) - 1];
    return 0;
}

void LClear(IntStack* s)
{
    s->lptr = 0;
}

int Capacity(const IntStack* s)
{
    return s->max;
}

int LSize(const IntStack* s)
{
    return s->lptr;
}

int IsLEmpty(const IntStack* s)
{
    return s->lptr <= 0;
}

int IsFull(const IntStack* s)
{
    return s->lptr > s->rptr;
}

int LSearch(const IntStack* s, int x)
{
    for(int i = s->lptr - 1; i >= 0; i--)
    {
        if(s->stk[i] == x)
            return s->lptr - i;
    }
    return -1;
}

void LPrint(const IntStack* s)
{
    for(int i = s->lptr - 1; i >= 0; i--)
    {
        std::cout << s->stk[i] << " ";
    }
    std::cout << std::endl;
}
int RPush(IntStack* s, int x)
{
    if(IsFull(s))
    {
        return -1;
    }
    s->stk[s->rptr--] = x;

    return 0;
}

int RPop(IntStack* s, int* x)
{
    if(IsREmpty(s))
    {
        return -1;
    }

    *x = s->stk[++s->rptr];
    return 0;
}

int RPeek(const IntStack* s, int* x)
{
    if(IsREmpty(s))
    {
        return -1;
    }

    *x = s->stk[(s->rptr)];
    return 0;
}

void RClear(IntStack* s)
{
    s->rptr = s->max - 1;
}

int RSize(const IntStack* s)
{
    return (s->max - s->rptr) - 1;
}

int IsREmpty(const IntStack* s)
{
    return s->rptr >= s->max - 1;
}

int RSearch(const IntStack* s, int x)
{
    for(int i = s->rptr + 1; i < s->max; i++)
    {
        if(s->stk[i] == x)
            return i - s->rptr;
    }
    return -1;
}

void RPrint(const IntStack* s)
{
    for(int i = s->rptr + 1; i < s->max; i++)
    {
        std::cout << s->stk[i] << " ";
    }
    std::cout << std::endl;
}
void Terminate(IntStack* s)
{
    s->lptr = s->rptr = s->max = 0;
    if(s->stk != NULL)
        delete[] s->stk;
}