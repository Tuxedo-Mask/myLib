#include "staticList.h"

int main()
{
    myLib::staticList<int> l;
    l.push_front(0);
    l.push_front(1);
    l.push_front(2);
    l.back_print();
    return 0;
}
