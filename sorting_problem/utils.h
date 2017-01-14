#ifndef UTILS_H
#define UTILS_H

namespace myLib
{

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
