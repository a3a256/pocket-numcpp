#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    // testing transpose functions

    std::vector<std::vector<int>> int_arr = {{2, 6, 17}, {7, 1, 9}};
    std::vector<std::vector<float>> float_arr = {{2.4f, 3.1f, 8.6f}, {7.9f, 6.4f, 4.9f}};

    NdArray fl_arr(float_arr);
    NdArray in_arr(int_arr);
    NdArray np;

    np = np.transpose(fl_arr);

    std::cout << "NdArray dtype\n";

    std::cout << "Original float array\n"<< fl_arr << '\n';

    std::cout << "Float transposing\n" << np << '\n';

    np = np.transpose(in_arr);

    std::cout << "Original float array\n"<< in_arr << '\n';

    std::cout << "Float transposing\n" << np << '\n';

    fl_arr = np.transpose(float_arr);

    std::cout << "Vector dtype\n";

    std::cout << "Float transposing\n" << fl_arr << '\n';

    in_arr = np.transpose(int_arr);

    std::cout << "Float transposing\n" << fl_arr << '\n';

    return 0;
}