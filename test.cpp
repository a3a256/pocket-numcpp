#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    // testing NdArray cases

    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    std::vector<float> b = {1.1f, 2.1f, 3.5f, 4.9f};

    value t;

    NdArray np(a);

    t = np.det(np);

    std::cout << t << '\n';
    

    return 0;
}