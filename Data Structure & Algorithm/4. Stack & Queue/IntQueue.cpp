#include<iostream>
#include"IntQueue.h"

int Initialize(IntQueue* q, int max)
{
    q->que = new int[max];
    if(q->que == NULL)
    {
        std::cout << "Initialize Failed.\n";

        return -1;
    }
    q->front = q->rear = q->num = 0;
    q->max = max;

    return 0;
}

int Enque(IntQueue* q, int x)
{
    if(IsFull(q))
    {
        std::cout << "Queue is already full.\n";
        return -1;
    }

    q->que[q->rear] = x;

    if(q->rear >= (q->max - 1))
        q->rear = 0;
    else
        q->rear++;
    
    q->num++;

    return 0;
}

int Deque(IntQueue* q, int* x)
{
    if(IsEmpty(q))
    {
        std::cout << "Queue is already empty.\n";
        return -1;
    }

    *x = q->que[q->front];

    if(q->front >= (q->max - 1))
        q->front = 0;
    else
        q->front++;

    q->num--;

    return 0;
}

int Peek(const IntQueue* q, int* x)
{
    if(IsEmpty(q))
    {
        std::cout << "Queue is already empty.\n";
        return -1;
    }

    *x = q->que[q->front];

    return 0;
}

void Clear(IntQueue* q)
{
    q->front = q->rear = 0;
    q->num = 0;
}

int Capacity(const IntQueue* q)
{
    return q->max;
}

int Size(const IntQueue* q)
{
    return q->num;
}

int IsEmpty(const IntQueue* q)
{
    return (q->num) <= 0;
}

int IsFull(const IntQueue* q)
{
    return (q->num) >= (q->max);
}

int Search(const IntQueue* q, int x)
{
    for(int i = 0; i < q->num; i++)
        if(q->que[(i+q->front) % q->max] == x)
            return i+1;

    return -1;
}

void Print(const IntQueue* q)
{
    for(int i = 0; i < q->num; i++)
        std::cout << q->que[(i+q->front) % q->max] << " ";
    
    std::cout << std::endl;
}

void Terminate(IntQueue* q)
{
    Clear(q);
    delete[] q->que;
}