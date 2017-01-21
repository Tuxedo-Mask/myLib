#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <cassert>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "utils.h"

namespace myLib
{

template <typename T>
void merge_sort(
                 T array[]
               , int left
               , int right
               , int array_size
               );

template <typename T>
void merge(
            T array[]
          , int left
          , int middle
          , int right
          , int array_size
          );

template <typename T>
void merge_sort(
                 T array[]
               , int left
               , int right
               , int array_size
               )
{
    assert(0 <= array_size);
    assert(right < array_size);
    assert(left >= 0);

    if (left >= right) {
        return;
    }
    
    // sort left part of array
    merge_sort(
                array
              , left
              , (right + left) / 2
              , array_size
              );

    // sort right part of array
    merge_sort(
                array
              , (left + right) / 2 + 1
              , right
              , array_size
              );

    // merge sorted parts
    merge(
           array
         , left
         , (right + left )/2
         , right
         , array_size
         );
}

template <typename T>
void merge(
            T array[]
          , int left
          , int middle
          , int right
          , int array_size
          )
{
    assert(0 <= left);
    assert(left <= middle);
    assert(middle < right);
    assert(right < array_size);

    int buff_size = (right - left) + 1;
    std::vector<T> buff(buff_size);

    for (int i = 0, l = left, r = middle + 1; i < buff_size; ++i) {
        if((array[l] < array[r] && l <= middle) || r > right) {
            buff[i] = array[l++];
        } else {
            buff[i] = array[r++];
        }
    }

    for (int i = left; i < left + buff_size; ++i) {
        array[i] = buff[i - left];
    }
}

}

#endif
