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

    // slicing arrays


    std::cout << "Checking select value slicing method\n";
    std::cout << np.select_value(2, 2) << '\n';

    np = np.select_column(0);


    std::cout << "Checking select columns slicing method\n";
    std::cout << np << '\n';

    NdArray check(a);

    check = check.select_row(1);


    std::cout << "Checking select row slicing method\n";
    std::cout << check << '\n';
    

    return 0;
}