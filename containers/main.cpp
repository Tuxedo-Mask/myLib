#include "staticHeap.h"

int main()
{
    myLib::staticHeap sh;
    sh.insert(1);
    sh.insert(2);
    sh.insert(3);
    sh.insert(4);
    sh.insert(5);
    sh.remove(0);
    sh.print();
    return 0;
}
