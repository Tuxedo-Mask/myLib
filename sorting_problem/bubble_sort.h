#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "utils.h"

namespace myLib
{

template <typename T>
void bubble_sort(T array[], unsigned int array_size)
{
    for (unsigned int i = 0; i < array_size - 1; ++i) {
        bool sorted = true;
        for (unsigned int j = 0; j < array_size - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                sorted = false;
            }
        }
        if (sorted) break;
    }
}
}

#endif
