#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <cassert>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

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
void print(
            T array[]
          , int array_size
          );

template <typename T>
void copy(
           std::vector<T>& dest
         , T array[]
         , int array_size
         );

template <typename T>
bool equal(
            std::vector<T>& dest
          , T array[]
          , int array_size
          );

template <typename T>
void random_fill(
                  T array[]
                , int array_size
                , int restriction
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

template <typename T>
void print(
            T array[]
          , int array_size
          )
{
    for (int i = 0; i < array_size; ++i) {
        std::cout << "array [" << i << "] == " << array[i] << std::endl;
    }

    std::cout << std::endl;
}

template <typename T>
void copy(
           std::vector<T>& dest
         , T array[]
         , int array_size
         )
{
    assert(array_size <= dest.size());
    for (int i = 0; i < array_size; ++i) {
        dest[i] = array[i];
    }
}

template <typename T>
bool equal(
            std::vector<T>& dest
          , T array[]
          , int array_size
          )
{
    for (int i = 0; i < array_size; ++i) {
        if(dest[i] != array[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void random_fill(
                  T array[]
                , int array_size
                , int restriction
                )
{
    for (int i = 0; i < array_size; ++i) {
        array[i] = std::rand() % restriction;
    }
}

}

#endif
