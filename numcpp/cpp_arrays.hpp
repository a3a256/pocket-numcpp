#include <iostream>
#include <complex.h>
#include <vector>
#include <stdexcept>
#include <string>

// namespace narr{
//     template<size_t dimcount, typename T> struct nd_arr{
//         typedef std::vector<typename nd_arr<dimcount-1, T>::type> type;
//     };

//     template<typename T>
//     struct nd_arr<0, T>{
//         typedef T type;
//     };

//     template<typename T>
//     nd_arr<1, T> shape(){
//         return;
//     }
// };

// template <size_t dim, typename T> class array{
//     private:
//         int d = static_cast<int>(dim);

//     public:

//         narr::nd_arr<1, int>shape(){
//             return;
//         }

//         void dot(narr::nd_arr<size_t dimcount, typename T> two){
//             return;
//         }
// };

struct value{
    int num;
    float dec;
    std::string line;
    bool is_int, is_float, is_obj;

    bool operator>(const value &val) const{
        if(is_int){
            return num > val.num;
        }
        if(is_float){
            return dec > val.dec;
        }
        return line > val.line;
    }

    bool operator<(const value &val) const{
        if(is_int){
            return num < val.num;
        }
        if(is_float){
            return dec < val.dec;
        }
        return line < val.line;
    }

    value operator+=(const float v){
        if(is_int){
            is_int = false;
            is_float = true;
            dec = (float)num + v;
            return *this;
        }
        if(is_float){
            dec += v;
            return *this;
        }
        if(is_obj){
            line += std::to_string(v);

            return *this;
        }
    }
    // up to make it up for various scenarios like int + str, float + str, float + int, int + int, float + float, etc.
    value operator+=(const value v){
        if(v.is_int || v.is_float && is_obj){
            line += std::to_string((v.is_int)?(v.num):(v.dec));
        }
        // if(is_float){
        //     if()
        // }
    }

    friend std::ostream& operator<<(std::ostream& os, const value& val);
};

std::ostream& operator<<(std::ostream& os, const value& val){
    if(val.is_int){
        os << val.num;
        return os;
    }
    if(val.is_float){
        os << val.dec;
        return os;
    }
    if(val.is_obj){
        os << val.line;
    }

    return os;
}

// add this part to NdArray class as inside objects

// struct shape{
//         int one_dim=-1;
//         std::vector<int> two_dim;

//         friend std::ostream& operator<<(std::ostream &os, const shape& arr);
// };

// std::ostream& operator<<(std::ostream& os, const shape& arr){
//     if(arr.one_dim > -1){
//         os << '(' << arr.one_dim << ",)";
//         return os;
//     }

//     os << '(' << arr.two_dim[0] << ',' << arr.two_dim[1] << ')';
//     return os;
// }

/*
Change lots of function and convert value types to "value" struct
*/
class NdArray{

    public:
        std::vector<value> array1d;
        std::vector<std::vector<value>> array2d;

        // Implemented struct shape for numcpp array

        struct shape{
            int one_dim=-1;
            std::vector<int> two_dim;
            // definition of a cout overload operator for shape struct
            friend std::ostream& operator<<(std::ostream &os, const shape& val);
        };
        // cout overload operator for NdArray class - definition
        friend std::ostream& operator<<(std::ostream& os, NdArray& arr);

        std::vector<std::vector<value>> operator+(std::vector<std::vector<value>> mat){
            int i, j;
            for(i=0; i<mat.size(); i++){
                for(j=0; j<mat[0].size(); j++){
                    array2d[i][j] += mat[i][j];
                }
            }

            return array2d;
        }

        std::vector<std::vector<value>> operator+(float val){
            int i, j;
            for(i=0; i<array2d.size(); i++){
                for(j=0; j<array2d[i].size(); j++){
                    array2d[i][j] += val;
                }
            }

            return array2d;
        }
        // yet to implement this one???
        // void array2d(std::vector<std::vector<value>> arr){
        //     return;
        // }

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

        std::vector<value> diag(){
            std::vector<value> res;
            int i, j;
            for(i=0; i<array2d.size(); i++){
                for(j=0; j<array2d[0].size(); j++){
                    if(i == j){
                        res.push_back(array2d[i][j]);
                    }
                }
            }

            return res;
        }

        // void to1d_arr(){
        //     int i, j;
        //     for(i=0; i<arr2d.size(); i++){
        //         for(j=0; j<arr2d[i].size(); j++){
        //             arr1d.push_back(arr2d[i][j]);
        //         }
        //     }
        // }

        // void to2d_arr(){
        //     arr2d.push_back(arr1d);
        //     std::vector<T>().swap(arr1d);
        // }

        void transpose(){
            if(arr1d.size() != 0){
                to2d_arr();
            }

            int i, j;
            std::vector<std::vector<value>> res;
            std::vector<value> temp;
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
            value val;
            val.is_int = true;
                val.num = 0;
            if(n == 1){
                std::vector<value> res(dims[0], val);
                array1d = res;
                std::vector<value>().swap(res);
            }

            if(n == 2){
                std::vector<std::vector<value>> res(dims[0], std::vector<value>(dims[1], val));
                array2d = res;
                std::vector<std::vector<value>>().swap(res);
            }
        }

        void ones(std::vector<int> dims){
            int n = dims.size();
            value val;
            val.is_int = true;
            val.num = 1;
            if(n == 1){
                std::vector<value> res(dims[0], val);
                array1d = res;
                std::vector<value>().swap(res);
            }

            if(n == 2){
                std::vector<std::vector<value>> res(dims[0], std::vector<value>(dims[1], val));
                array2d = res;
                std::vector<std::vector<value>>().swap(res);
            }
        }


        // convert shape to class??
        // struct shape{
        //     std::vector<int> one_dim;
        //     std::vector<std::vector<int>> two_dim;
        // };

        // friend std::ostream& operator<<(std::ostream& os, shape& arr);

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


    private:

    // added function to show

        // void show(){
        //     int i, j, length;
        //     if(array1d.size() != 0){
        //         length = array1d.size();
        //         for(i=0; i<length; i++){
        //             std::cout << array1d[i] << " ";
        //         }
        //         std::cout << "\n";
        //         return;
        //     }

        //     if(array2d.size() != 0){
        //         length = array2d.size();
        //         for(i=0; i<length; i++){
        //             for(j=0; j<array2d[i].size(); j++){
        //                 std::cout << array2d[i][j] << " ";
        //             }
        //             std::cout << "\n";
        //         }
        //         return;
        //     }
        // }
};

// implementation of a cout << overload operato for NdArray portrayal of vectors
std::ostream& operator<<(std::ostream& os, NdArray &arr){
    int i, j, length;
    if(arr.array1d.size() != 0){
        length = arr.array1d.size();
        for(i=0; i<length; i++){
            os << arr.array1d[i] << " ";
        }
        os << "\n";
        return os;
    }

    if(arr.array2d.size() != 0){
        length = arr.array2d.size();
        for(i=0; i<length; i++){
            for(j=0; j<arr.array2d[i].size(); j++){
                os << arr.array2d[i][j] << " ";
            }
            os << "\n";
        }
    }

    return os;
}

// implementation of a cout << overload operato for shape struct
std::ostream& operator<<(std::ostream& os, NdArray::shape& val){
    if(val.one_dim > -1){
        os << '(' << val.one_dim << ",)";
        return os;
    }

    os << '(' << val.two_dim[0] << ',' << val.two_dim[1] << ')';
    return os;
}