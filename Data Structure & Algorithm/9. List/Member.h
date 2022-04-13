#ifndef __Member
#define __Member

#include<string>
struct Member
{
    int no;
    std::string name;
};

Member* newMember(int no, std::string name);

int Compare(const Member* x, const Member* y);

int CompareNo(const Member* x, const Member* y);

int CompareName(const Member* x, const Member* y);

void PrintMember(const Member* x);

#endif