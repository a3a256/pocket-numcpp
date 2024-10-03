#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    // testing NdArray cases
    // yet to test on higher dimensions

    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    std::vector<float> b = {1.1f, 2.1f, 3.5f, 4.9f};

    value t;

    NdArray np(a);

    t = np.det(np);

    std::cout << t << '\n';

    // tetsing [] overloading operators

    NdArray ap(a);

    std::cout << "Slicing operator\n";

    ap = ap[0];

    std::cout << ap << '\n';
    

    return 0;
}