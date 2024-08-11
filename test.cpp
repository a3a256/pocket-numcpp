#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    // testing transpose functions

    std::vector<std::vector<float>> one = {{2.5f, 6.3f}, {7.4f, 1.9f}};
    std::vector<std::vector<int>> two = {{5, 6}, {9, 1}};

    NdArray np;

    np = np.dot(one, two);

    std::cout << np << '\n';

    return 0;
}