#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    // testing NdArray cases

    std::vector<int> a = {1, 2, 3, 4};
    std::vector<float> b = {1.1f, 2.1f, 3.5f, 4.9f};

    // NdArray one(a);
    // NdArray two(b);

    NdArray np;

    np = np.add(a, b);

    std::cout << np << '\n';

    np = np.subtract(a, b);

    std::cout << np << '\n';

    np = np.multiply(a, b);

    std::cout << np << '\n';

    np = np.divide(a, b);

    std::cout << np << '\n';

    return 0;
}