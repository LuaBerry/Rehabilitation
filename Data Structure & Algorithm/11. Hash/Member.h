#ifndef __Member
#define __Member

#define MEMBER_NO 1
#define MEMBER_NAME 2

#include<string>
struct Member
{
    int no;
    std::string name;
};

Member* newMember(int no, std::string name);

int CompareNo(const Member* x, const Member* y);

int CompareName(const Member* x, const Member* y);

void PrintMember(const Member* x);

#endif