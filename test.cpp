#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    std::vector<int> arr = {1, 2, 3, 3, 3, 4};

    NdArray n(arr);

    //tested cout overload function - working fine

    std::cout << n << '\n';

    // currently testing unique method

    NdArray np;

    n = np.unique(n);

    std::cout << n << '\n';
    return 0;
}