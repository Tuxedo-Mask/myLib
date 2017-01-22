#include "list.h"

int main()
{
    myLib::List<int> myList;
    myList.pushBack(3);
    myList.pushBack(4);

    myLib::ListNode<int>* lnp = myList.find(3);

    if(lnp) {
        myList.insertAfter(10, lnp);
    }

    myList.print();
    myList.rPrint();
    
    return 0;
}
