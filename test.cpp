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

    // testing diag method

    std::vector<std::vector<float>> arr2 = {{1.2f, 2.3f, 5.1f}, {4.5f, 9.8f, 10.2f}, {3.2f, 4.3f, 7.1f}};

    v = np.diag(arr2);

    v = v.flatten();

    v = np.diag(v);

    std::cout << "checking diag function\n";
    std::cout << v << '\n';
    return 0;
}