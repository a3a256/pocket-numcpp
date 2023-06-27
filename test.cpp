#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    NdArray<int> np;

    std::vector<std::vector<int>> arr = {{1, 2, 3, 4, 5}};
    NdArray<int> np1;

    np1.array2d({{1}, {2}, {3}, {4}, {5}});

    np.array2d(arr);

    np1.dot(np);

    np1.show();

    narr::nd_arr<2, int> arr;

    // np.show();

    // std::vector<int> di = np.diag();

    // np.transpose();
    // np.show();


    return 0;
}