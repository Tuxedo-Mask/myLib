#include "merge_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "bubble_sort.h"
#include "utils.h"

int main()
{
    const int array_size = 10;
    int a[array_size];

    myLib::random_fill(a, array_size, 100);

    myLib::print(a, array_size);


    myLib::quick_sort(a, 0, array_size - 1, array_size);
    myLib::print(a, array_size);

    return 0;
}
