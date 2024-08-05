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

    std::cout << np.nunique(arr) << '\n';

    // testing flattening function

    std::vector<std::vector<int>> arr1 = {{1, 2, 3}, {4, 5, 6}};

    NdArray v(arr1);
    std::cout << v << '\n';
    v = v.flatten();
    std::cout << v << '\n';
    return 0;
}