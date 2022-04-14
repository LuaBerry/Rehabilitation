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
    return (x->no) - (y->no);
}

int CompareNo(const Member* x, const Member* y)
{
    if(x->no > y->no)
        return 1;
    else if(x->no == y->no)
        return 0;
    else
        return -1;
}

int CompareName(const Member* x, const Member* y)
{
    return (x->name.compare(y->name));
}

void PrintMember(const Member* x)
{
    std::cout << x->no << " " << x->name << "\n";
}
