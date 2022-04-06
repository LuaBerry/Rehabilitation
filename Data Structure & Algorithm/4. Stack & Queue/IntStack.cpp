#include<iostream>
#include "IntStack.h"

int Initialize(IntStack* s, int max)
{
    s->ptr = 0;
    if((s->stk = new int[max]) == NULL)
    {
        s->max = 0;
        return 0;
    }
    s->max = max;
    return 1;
}