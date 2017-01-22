#include "list.h"

int main()
{
    myLib::List<int> myList;
    myList.pushBack(4);
    myList.pushBack(3);

    myLib::ListNode<int>* lnp = myList.find(3);

    if(lnp) {
        myList.erase(lnp);
    }

    myList.print();
    myList.rPrint();
    
    return 0;
}
