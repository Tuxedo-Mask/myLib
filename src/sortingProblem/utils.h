#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

typedef unsigned int size_t;

namespace myLib
{
// 1
template <typename T>
void print(
            T array[]
          , size_t array_size
          );

// 2
template <typename T>
void copy(
           std::vector<T>& dest
         , T array[]
         , size_t array_size
         );

// 3
template <typename T>
void copy(
           T dest_array[]
         , T from_array[]
         , size_t array_size
         );

// 4
template <typename T>
bool equal(
            std::vector<T>& dest
          , T array[]
          , size_t array_size
          );

// 5
template <typename T>
void random_fill(
                  T array[]
                , size_t array_size
                , size_t restriction
                );

// 6 TODO need more investigation in case of bugs
template <typename T>
int binary_search(
                   T array[]
                 , size_t array_size
                 , T number
                 , bool (* predicate)(T, T)
                 );

// 7
template <typename T>
size_t binary_search_helper(
                          T sorted_array[]
                        , T number
                        , size_t left
                        , size_t right
                        , bool (* predicate)(T, T)
                        );

// 8
template <typename T>
bool greate_or_equal (T left, T right);

// 9
template <typename T>
bool less_or_equal (T left, T right);

// 10
template <typename T>
void swap(T& left, T& right);

// 11
void sleep(int seconds);

// 12
void space(size_t how_many);

// 13
void message(std::string msg);

// 1
template <typename T>
void print(
            T array[]
          , size_t array_size
          )
{
    for (size_t i = 0; i < array_size; ++i) {
        std::cout << "array [" << i << "] == " << array[i] << std::endl;
    }

    std::cout << std::endl;
}

// 2
template <typename T>
void copy(
           std::vector<T>& dest
         , T array[]
         , size_t array_size
         )
{
    assert(array_size <= dest.size());
    for (size_t i = 0; i < array_size; ++i) {
        dest[i] = array[i];
    }
}

// 3
template <typename T>
void copy(
           T dest_array[]
         , T from_array[]
         , size_t array_size
         )
{
    for (size_t i = 0; i < array_size; ++i) {
        dest_array[i] = from_array[i];
    }
}

// 4
template <typename T>
bool equal(
            std::vector<T>& dest
          , T array[]
          , size_t array_size
          )
{
    for (size_t i = 0; i < array_size; ++i) {
        if(dest[i] != array[i]) {
            return false;
        }
    }
    return true;
}

// 5
template <typename T>
void random_fill(
                  T array[]
                , size_t array_size
                , size_t restriction
                )
{
    for (size_t i = 0; i < array_size; ++i) {
        array[i] = std::rand() % restriction;
    }
}

// 6
template <typename T>
int binary_search(
                   T sorted_array[]
                 , size_t array_size
                 , T number
                 , bool (* predicate)(T, T)
                 )
{
    int i =  binary_search_helper(sorted_array, number, 0, array_size - 1, predicate);
    if (array_size - 1 != i) {
        --i;
    }
    return sorted_array[i] == number ? i : -1;
}

// 7
template <typename T>
int binary_search_helper(
                          T sorted_array[]
                        , T number
                        , int left
                        , int right
                        , bool (* predicate)(int, int)
                        )
{
    while (right - left > 1 ) {
        int middle = (right + left) / 2;
        if (predicate(number, sorted_array[middle]) ) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return right;
}

// 8
template <typename T>
bool greate_or_equal (T left, T right)
{
    return left >= right ? true : false; 
}

// 9
template <typename T>
bool less_or_equal (T left, T right)
{
    return left <= right ? true : false; 
}

// 10
template <typename T>
void swap(T& left, T& right)
{
    T buff = left;
    left = right;
    right = buff;
}

// 11
unsigned int microseconds  = 100000;
void sleep(int seconds)
{
    usleep(seconds * microseconds);
}

// 12
void space(size_t how_many)
{
    for (size_t i = 0; i < how_many; ++i) {
        std::cout << std::endl;
    }
}

// 13
void message(std::string msg)
{
    std::cout << msg << std::endl;
}

}

#endif
