#include "staticStack.h"
#include "staticQueue.h"
#include "staticList.h"

int main()
{
    myLib::staticStack<int, 105> ss;
    myLib::staticQueue<int, 105> sq;
    myLib::staticList<int, 105> sl;

    return 0;
}
