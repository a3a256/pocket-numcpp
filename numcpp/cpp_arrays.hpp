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
        std::vector<T> arr1d;


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
                    for(j=0; j<arr2d[i].size(); j++){
                        std::cout << arr2d[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                return;
            }
        }

        std::vector<T> diag(){
            std::vector<T> res;
            int i, j;
            for(i=0; i<arr2d.size(); i++){
                for(j=0; j<arr2d[0].size(); j++){
                    if(i == j){
                        res.push_back(arr2d[i][j]);
                    }
                }
            }

            return res;
        }

        void to1d_arr(){
            int i, j;
            for(i=0; i<arr2d.size(); i++){
                for(j=0; j<arr2d[i].size(); j++){
                    arr1d.push_back(arr2d[i][j]);
                }
            }
        }

        void to2d_arr(){
            arr2d.push_back(arr1d);
            std::vector<T>().swap(arr1d);
        }

        std::vector<std::vector<T>> transpose(){
            return;
        }
};