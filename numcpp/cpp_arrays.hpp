#include <iostream>
#include <complex.h>
#include <vector>

template <typename T> class 2d_array{
    private:
        T* arr;

    public:
        2d_array(std::vector<std::vector<T>>);
};