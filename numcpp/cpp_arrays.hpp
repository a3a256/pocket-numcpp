#include <iostream>
#include <complex.h>
#include <vector>
#include <stdexcept>

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

        void transpose(){
            if(arr1d.size() != 0){
                to2d_arr();
            }

            int i, j;
            std::vector<std::vector<T>> res;
            std::vector<T> temp;
            for(i=0; i<arr2d[0].size(); i++){
                for(j=0; j<arr2d.size(); j++){
                    temp.push_back(arr2d[j][i]);
                }
                res.push_back(temp);
                std::vector<T>().swap(temp);
            }
            std::vector<T>().swap(temp);

            arr2d = res;
            std::vector<std::vector<T>>().swap(res);
        }

        void zeros(std::vector<int> dims){
            int n = dims.size();
            if(n == 1){
                std::vector<T> res(dims[0], 0);
                arr1d = res;
                std::vector<T>().swap(res);
            }

            if(n == 2){
                std::vector<std::vector<T>> res(dims[0], std::vector<T>(dims[1], 0));
                arr2d = res;
                std::vector<std::vector<T>>().swap(res);
            }
        }

        void dot(NdArray<T> arr){
            std::string line = "Cannot multiply matrices of size ";
            if(arr2d[0].size() != arr.arr2d.size()){
                throw std::invalid_argument("")
            }
            int i, j, k;
            return;
        }
};