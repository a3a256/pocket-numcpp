#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    // testing transpose functions

    std::vector<std::vector<int>> one = {{2, 6}, {7, 1}};
    std::vector<std::vector<int>> two = {{5, 6}, {9, 1}};

    NdArray np;

    np = np.dot(one, two);

    std::cout << np << '\n';

    return 0;
}