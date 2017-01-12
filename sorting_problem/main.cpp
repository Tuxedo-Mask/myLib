#include "merge_sort.h"
#include <algorithm>

int main()
{
    std::srand(std::time(0));
    const int array_size = 10;
    std::vector<int> cp_array(array_size);
    int a[array_size];

    myLib::random_fill(a, array_size, 1000);
    myLib::copy(cp_array, a, array_size);

    std::sort(cp_array.begin(), cp_array.end());

    myLib::merge_sort(a, 0, array_size - 1, array_size);

    if(myLib::equal(cp_array, a, array_size)) {
        std::cout << "cp_array is equal to a" << std::endl;
    } else {
        std::cout << "cp_array is not equal to a" << std::endl;
    }
    myLib::print(a, array_size);

    return 0;
}
