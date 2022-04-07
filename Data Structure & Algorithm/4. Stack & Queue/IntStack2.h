#ifndef __IntStack2
#define __IntStack2

struct IntStack
{
    int max;
    int lptr;
    int rptr;
    int *stk;
};

int Initialize(IntStack* s, int max);

int LPush(IntStack* s, int x);

int LPop(IntStack* s, int* x);

int LPeek(const IntStack* s, int* x);

void LClear(IntStack* s);

int Capacity(const IntStack* s);

int LSize(const IntStack* s);

int IsLEmpty(const IntStack* s);

int IsFull(const IntStack* s);

int LSearch(const IntStack* s, int x);

void LPrint(const IntStack* s);

int RPush(IntStack* s, int x);

int RPop(IntStack* s, int* x);

int RPeek(const IntStack* s, int* x);

void RClear(IntStack* s);

int RSize(const IntStack* s);

int IsREmpty(const IntStack* s);

int RSearch(const IntStack* s, int x);

void RPrint(const IntStack* s);

void Terminate(IntStack* s);

#endif