#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    // testing NdArray cases

    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};
    std::vector<float> b = {1.1f, 2.1f};

    NdArray one(a);
    NdArray two(b);

    NdArray np;

    np = np.add(one, two);

    std::cout << np << '\n';

    np = np.subtract(one, two);

    std::cout << np << '\n';

    np = np.multiply(one, two);

    std::cout << np << '\n';

    np = np.divide(one, two);

    std::cout << np << '\n';

    return 0;
}