#include<iostream>
#include"Member.h"

Member* newMember(int no, std::string name)
{
    Member* member = new Member;
    member->no = no;
    member->name = name;

    return member;
}

int Compare(const Member* x, const Member* y)
{
    if(x->no == y->no)
    {
        if (x->name.compare(y->name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int CompareNo(const Member* x, const Member* y)
{
    if(x->no == y->no)
        return 1;
    else
        return 0;
}

int CompareName(const Member* x, const Member* y)
{
    if (x->name.compare(y->name) == 0)
        return 1;
    else
        return 0;
}

void PrintMember(const Member* x)
{
    std::cout << x->no << " " << x->name << "\n";
}
