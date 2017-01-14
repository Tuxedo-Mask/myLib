#include "merge_sort.h"
#include "utils.h"
#include <algorithm>

int main()
{
    const int array_size = 10;
    int a[array_size];

    myLib::random_fill(a, array_size, 100);

    myLib::merge_sort(a, 0, array_size - 1, array_size);

    myLib::print(a, array_size);
    for (int j = 0; j < 1000; ++j) {
        int i = myLib::binary_search<int>(a, array_size, j, myLib::greater_or_equal);
        if (-1 != i){
            std::cout << "i == " << i << " a[i] = " << a[i] << std::endl;
        }
    }



    return 0;
}
