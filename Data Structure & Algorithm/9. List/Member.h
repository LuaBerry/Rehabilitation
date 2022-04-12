#ifndef __Member
#define __Member

#include<string>
struct Member
{
    int no;
    std::string name;
};

int Compare(const Member* x, const Member* y);
#endif