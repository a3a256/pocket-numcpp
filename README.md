# pocket-numcpp
Small numcpp package, that would be similar to Python's numpy basic functions

In order to initialise numcpp array and pass it onto constructor do the following:

```cpp
#include <iostream>
#include "numcpp/cpp_arrays.hpp"
#include <vector>


int main(){

    std::vector<std::vector<int>> a = {{1, 2}, {3, 4}};

    NdArray np(a);

    std::cout << np << '\n';

    return 0;

}
```
