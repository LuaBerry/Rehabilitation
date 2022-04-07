#ifndef __IntQueue
#define __IntQueue

struct IntQueue
{
    int max;
    int num;
    int front;
    int rear;
    int* que;
};

int Initialize(IntQueue* q, int max);

int Enque(IntQueue* q, int x);

int Deque(IntQueue* q, int* x);

int Peek(const IntQueue* q, int* x);

void Clear(IntQueue* q);

int Capacity(const IntQueue* q);

int Size(const IntQueue* q);

int IsEmpty(const IntQueue* q);

int IsFull(const IntQueue* q);

int Search(const IntQueue* q, int x);

void Print(const IntQueue* q);

void Terminate(IntQueue* q);

#endif