#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "utils.h"
namespace myLib
{
template <typename T>
void insertion_sort(T array[], unsigned int array_size)
{
    for (unsigned int i = 1; i < array_size; ++i) {
        T key = array[i];
        unsigned  j = i;
        while (array[j - 1] > key) {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = key;
    }
}
}

#endif
