#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "utils.h"

namespace myLib
{

template <typename T>
void quick_sort(
                 T array[]
               , unsigned int left
               , unsigned int right
               , unsigned int array_size
               );

template <typename T>
unsigned int partition(
                        T array[]
                      , unsigned int left
                      , unsigned int right
                      );

template <typename T>
void quick_sort(
                 T array[]
               , unsigned int left
               , unsigned int right
               , unsigned int array_size
               )
{
        unsigned int pivot = partition(array, left, right);

        if(pivot < right) {
            quick_sort(array, left, pivot, array_size);
        }
        if(left < pivot) {
            quick_sort(array, pivot, right, array_size);
        }
}

template <typename T>
unsigned int partition(
                        T array[]
                      , unsigned int left
                      , unsigned int right
                      )
{
    int l = left;
    int r = right;
    unsigned int pivot = array[(left + right) / 2];
    while (l <= r) {
        while (array[l] < pivot) {
            ++l;
        }

        while (array[r] > pivot) {
            --r;
        }
        if(l <= r) {
            swap(array[l++], array[r--]);
        }
    }
    
    if (l < right) {
        return l;
    } else {
        return r;
    }
}

}

#endif
