#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>

namespace myLib
{
// 1
template <typename T>
void print(
            T array[]
          , int array_size
          );

// 2
template <typename T>
void copy(
           std::vector<T>& dest
         , T array[]
         , int array_size
         );

// 3
template <typename T>
bool equal(
            std::vector<T>& dest
          , T array[]
          , int array_size
          );

// 4
template <typename T>
void random_fill(
                  T array[]
                , int array_size
                , int restriction
                );

// 5
template <typename T1>
int binary_search(
                   T1 array[]
                 , int array_size
                 , int number
                 , bool (* predicate)(int, int)
                 );

// 6
template <typename T1>
int binary_search_helper(
                          T1 sorted_array[]
                        , int number
                        , int left
                        , int right
                        , bool (* predicate)(int, int)
                        );

// 7
template <typename T>
bool greater_or_equal (T left, T right);

// 8
void sleep(int seconds);

// 9
template <typename T>
void swap(T& left, T& right);

// 1
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

// 2
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

// 3
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

// 4
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

// 5
template <typename T1>
int binary_search(
                   T1 sorted_array[]
                 , int array_size
                 , int number
                 , bool (* predicate)(int, int)
                 )
{
    int i =  binary_search_helper(sorted_array, number, 0, array_size - 1, predicate);
    if (array_size - 1 != i) {
        --i;
    }
    return sorted_array[i] == number ? i : -1;
}

// 6
template <typename T1>
int binary_search_helper(
                          T1 sorted_array[]
                        , int number
                        , int left
                        , int right
                        , bool (* predicate)(int, int)
                        )
{
    while (right - left > 1 ) {
        int middle = (right + left) / 2;
        // std::cout << "left = " << left << " right = " << right << std::endl;
        // std::cout << "middle = " << middle << " sorted_array[middle] " << sorted_array[middle]<< std::endl;
        // sleep(1);
        if (predicate(number, sorted_array[middle]) ) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return right;
}

// 7
template <typename T>
bool greater_or_equal (T left, T right)
{
    return left >= right ? true : false; 
}

// 8
unsigned int microseconds  = 1000000;
void sleep(int seconds)
{
    usleep(microseconds * seconds);
}

// 9
template <typename T>
void swap(T& left, T& right)
{
    T buff = left;
    left = right;
    right = buff;
}

}

#endif
