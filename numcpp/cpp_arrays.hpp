#include <iostream>
#include <complex.h>
#include <vector>
#include <stdexcept>

namespace ndarray{
    template<typename T> class array{
        public:
            std::vector<T>arr;
            array(std::vector<T> val){arr = val;}
            virtual ~array(){}
    };
}

// template <typename T> class 2d_array{
//     private:
//         T* arr;

//     public:
//         2d_array(std::vector<std::vector<T>> mass);
// };



template <typename T> class NdArray{

    public:
        std::vector<std::vector<T>> arr2d;
        std::vector<T> arr1d;

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

        std::vector<int> shape(){
            int m, n;
            m = arr2d.size();
            n = arr2d[0].size();
            return {m, n};
        }

        void dot(NdArray<T> arr){
            std::vector<int> sh = shape();
            int m1 = sh[0], n1 = sh[1];
            sh = arr.shape();
            int m2 = sh[0], n2 = sh[1];
            std::string line = "Cannot multiply matrices of size ";
            line += '(' + std::to_string(m1) + ',' + std::to_string(n2) + ')';
            line += " and (" + std::to_string(m2) + ',' + std::to_string(n2) + ')';
            if(n1 != m2){
                throw std::invalid_argument(line);
            }
            int i, j, k;
            std::vector<std::vector<T>> res;
            std::vector<T> temp;
            T sum;
            for(i=0; i<m1; i++){
                for(j=0; j<n2; j++){
                    sum = 0;
                    for(k=0; k<n1; k++){
                        sum += arr2d[i][k]*arr.arr2d[k][j];
                    }
                    temp.push_back(sum);
                }
                res.push_back(temp);
                std::vector<T>().swap(temp);
            }
            arr2d = res;
            std::vector<std::vector<T>>().swap(res);
        }
};