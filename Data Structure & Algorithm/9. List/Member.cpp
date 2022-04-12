#include"Member.h"

int Compare(const Member* x, const Member* y)
{
    if(x->no == y->no)
    {
        if (x->name.compare(y->name) == 0)
        {
            return 0;
        }
    }
    return 1;
}
