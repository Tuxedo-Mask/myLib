#include "staticHeap.h"

const int array_size = 10;

int main()
{
    int array[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    myLib::staticHeap<int>::heapSort(array, array_size, myLib::less_or_equal);
    myLib::print(array, array_size);
    
    return 0;
}
