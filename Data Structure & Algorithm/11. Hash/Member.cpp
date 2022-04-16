#include<iostream>
#include"Member.h"

Member* newMember(int no, std::string name)
{
    Member* member = new Member;
    member->no = no;
    member->name = name;

    return member;
}

int CompareNo(const Member* x, const Member* y)
{
    return (x->no) - (y->no);
}

int CompareName(const Member* x, const Member* y)
{
    return (x->name.compare(y->name));
}

void PrintMember(const Member* x)
{
    std::cout << "(" << x->no << ") " << x->name;
}
