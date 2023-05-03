#include <iostream>
#include <complex.h>
#include <vector>

// template <typename T> class 2d_array{
//     private:
//         T* arr;

//     public:
//         2d_array(std::vector<std::vector<T>> mass);
// };



template <typename T> class NdArray{
    private:

        std::vector<std::vector<T>> arr2d;
        std::vector<std::complex<T>> arr1d;


    public:

        void array2d(std::vector<std::vector<T>> arr){
            arr2d = arr;
        }

        void show(){
            int i, j, length;
            if(arr1d.size() != 0){
                length = arr1d.size();
                for(i=0; i<length; i++){
                    std::cout << arr1d[i] << " ";
                }
                std::cout << "\n";
                return;
            }

            if(arr2d.size() != 0){
                length = arr2d.size();
                for(i=0; i<length; i++){
                    for(j=0; j<arr2d[i]; j++){
                        std::cout << arr2d[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                return;
            }
        }
};