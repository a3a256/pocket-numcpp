#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    NdArray<int> np;

    std::vector<std::vector<int>> arr = {{1, 2, 3, 4, 5}};

    np.array2d(arr);


    return 0;
}