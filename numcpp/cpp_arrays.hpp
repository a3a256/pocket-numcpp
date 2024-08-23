#include <iostream>
#include <complex.h>
#include <vector>
#include <stdexcept>
#include <string>
#include <set>

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
    bool is_int=false, is_float=false, is_obj=false;

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

    // implementing assignment overload "=" operators

    value operator=(const int v){

        if(!is_obj && !is_int && !is_float){
            is_int = true;
            num = v;
            return *this;
        }

        if(is_obj){
            throw std::invalid_argument("Cannot assign string to int/float dtype");
        }

        if(is_float){
            dec = (float)v;
            return *this;
        }

        num = v;
        return *this;
    }

    value operator=(const float v){

        if(!is_obj && !is_int && !is_float){
            is_float = true;
            dec = v;
            return *this;
        }

        if(is_obj){
            throw std::invalid_argument("Cannot assign string to int/float dtype");
        }

        if(is_int){
            num = (int)v;
            return *this;
        }

        dec = v;
        return *this;
    }

    value operator=(const std::string v){

        if(!is_obj && !is_int && !is_float){
            is_obj = true;
            line = v;
            return *this;
        }

        if(is_int || is_float){
            throw std::invalid_argument("Cannot assign int/float to string dtype");
        }

        line = v;
        return *this;
    }


    // up to make it up for various scenarios like int + str, float + str, float + int, int + int, float + float, etc.
    value operator+=(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec += v.dec;
        }else if(is_int && v.is_int){
            num += v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator+=(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num += v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator+=(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec += v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator+=(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    // implementing overloading operators for +
    value operator+(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec += v.dec;
        }else if(is_int && v.is_int){
            num += v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator+(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num += v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator+(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec += v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator+(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }


    // implementing overloading operators such as - and -=
    value operator-=(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec -= v.dec;
        }else if(is_int && v.is_int){
            num -= v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator-=(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num -= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator-=(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec -= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator-=(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    // implementing overloading operators for +
    value operator-(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec -= v.dec;
        }else if(is_int && v.is_int){
            num -= v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator-(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num -= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator-(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec -= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator-(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    // implementing multiplication overload operators
    // implement the change of dtypes from int to float and from float to int(but most likely implement from int to float)

    value operator*=(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec *= v.dec;
        }else if(is_int && v.is_int){
            num *= v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator*=(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num *= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator*=(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec *= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator*=(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    // implementing overloading operators for * operator
    value operator*(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec *= v.dec;
        }else if(is_int && v.is_int){
            num *= v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator*(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num *= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator*(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec *= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator*(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    // implementing division overload operators

    value operator/=(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec /= v.dec;
        }else if(is_int && v.is_int){
            num /= v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator/=(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num /= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator/=(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec /= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator/=(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    // implementing overloading operators for / operator
    value operator/(const value v){
        if(is_obj || v.is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float && v.is_float){
            dec /= v.dec;
        }else if(is_int && v.is_int){
            num /= v.num;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator/(const int v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_int){
            num /= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }
        return *this;
    }

    value operator/(const float v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float){
            dec /= v;
        }else{
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
    }

    value operator/(const std::string v){
        if(is_obj){
            throw std::invalid_argument("Does not support str item assignment");
        }

        if(is_float || is_int){
            throw std::invalid_argument("Does not support add function for different data types");
        }

        return *this;
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


        std::string dtype = "";
        // Implemented struct shape for numcpp array

        struct dimensions{
            int one_dim=-1;
            std::vector<int> two_dim;
            // definition of a cout overload operator for shape struct
            friend std::ostream& operator<<(std::ostream &os, const dimensions& val);
        };
        // cout overload operator for NdArray class - definition
        friend std::ostream& operator<<(std::ostream& os, NdArray& arr);

        // adding empty constructor as another edge case

        NdArray(){}

        // Constructors overloading for 1d arrays and their shapes for different data types

        // sub problem of constructors implemented partially - constructors that would accept set of unique values with various data types
        // only implemented to output 1d arrays
        // research whether there are scenarios for unique() method that would output 2-d arrays of unique values
        // implement them

        NdArray(std::set<int> stk){
            std::vector<value>().swap(array1d);
            value t;
            t.is_int = true;
            for(auto it: stk){
                t.num = it;
                array1d.push_back(t);
            }

            shape.one_dim = array1d.size();
            dtype = "int";
            std::set<int>().swap(stk);
        }

        NdArray(std::set<float> stk){
            std::vector<value>().swap(array1d);
            value t;
            t.is_float = true;
            for(auto it: stk){
                t.dec = it;
                array1d.push_back(t);
            }
            dtype = "float";
            shape.one_dim = array1d.size();
        }

        NdArray(std::set<value> stk){
            std::vector<value>().swap(array1d);
            for(auto it: stk){
                array1d.push_back(it);
            }
            dtype = "object";
            shape.one_dim = array1d.size();
        }



        NdArray(std::vector<int> arr1d){
            std::vector<value>().swap(array1d);
            int i;
            value t;
            for(i=0; i<arr1d.size(); i++){
                t.is_int = true;
                t.num = arr1d[i];
                array1d.push_back(t);
            }
            dtype = "int";
            shape.one_dim = (int)arr1d.size();
            std::vector<int>().swap(shape.two_dim);
        }

        NdArray(std::vector<float> arr1d){
            std::vector<value>().swap(array1d);
            int i;
            value t;
            for(i=0; i<arr1d.size(); i++){
                t.is_float = true;
                t.dec = arr1d[i];
                array1d.push_back(t);
            }
            dtype = "float";
            shape.one_dim = (int)arr1d.size();
            std::vector<int>().swap(shape.two_dim);
        }

        NdArray(std::vector<std::string> arr1d){
            std::vector<value>().swap(array1d);
            int i;
            value t;
            for(i=0; i<arr1d.size(); i++){
                t.is_obj = true;
                t.line = arr1d[i];
                array1d.push_back(t);
            }
            dtype = "object";
            shape.one_dim = (int)arr1d.size();
            std::vector<int>().swap(shape.two_dim);
        }

        NdArray(std::vector<value> arr1d){
            array1d = arr1d;
            shape.one_dim = (int)arr1d.size();
            std::vector<int>().swap(shape.two_dim);
        }

        // Constructors overloading for 2d arrays and their shapes for different data types

        NdArray(std::vector<std::vector<int>> arr2d){
            std::vector<std::vector<value>>().swap(array2d);
            int i, j;
            value t;
            t.is_int = true;
            t.num = 0;
            std::vector<value> temp;
            for(i=0; i<arr2d.size(); i++){
                for(j=0; j<arr2d[i].size(); j++){
                    t.is_int = true;
                    t.num = arr2d[i][j];
                    temp.push_back(t);
                }
                array2d.push_back(temp);
                std::vector<value>().swap(temp);
            }
            dtype = "int";
            std::vector<int>().swap(shape.two_dim);
            shape.two_dim.push_back((int)arr2d.size());
            shape.two_dim.push_back((int)arr2d[0].size());
        }

        NdArray(std::vector<std::vector<float>> arr2d){
            std::vector<std::vector<value>>().swap(array2d);
            int i, j;
            value t;
            t.is_float = true;
            t.dec = 0.0f;
            std::vector<value> temp;
            for(i=0; i<arr2d.size(); i++){
                for(j=0; j<arr2d[i].size(); j++){
                    t.is_float = true;
                    t.dec = arr2d[i][j];
                    temp.push_back(t);
                }
                array2d.push_back(temp);
                std::vector<value>().swap(temp);
            }
            dtype = "float";
            std::vector<int>().swap(shape.two_dim);
            shape.two_dim.push_back((int)arr2d.size());
            shape.two_dim.push_back((int)arr2d[0].size());
        }

        NdArray(std::vector<std::vector<std::string>> arr2d){
            std::vector<std::vector<value>>().swap(array2d);
            int i, j;
            value t;
            t.is_obj = true;
            t.line = "0.0";
            std::vector<value> temp;
            for(i=0; i<arr2d.size(); i++){
                for(j=0; j<arr2d[i].size(); j++){
                    t.is_obj = true;
                    t.line = arr2d[i][j];
                    temp.push_back(t);
                }
                array2d.push_back(temp);
                std::vector<value>().swap(temp);
            }
            dtype = "object";
            std::vector<int>().swap(shape.two_dim);
            shape.two_dim.push_back((int)arr2d.size());
            shape.two_dim.push_back((int)arr2d[0].size());
        }

        NdArray(std::vector<std::vector<value>> arr2d){
            array2d = arr2d;
            std::vector<int>().swap(shape.two_dim);
            shape.two_dim.push_back((int)arr2d.size());
            shape.two_dim.push_back((int)arr2d[0].size());
        }

        dimensions shape;

        // plan to investigate whether you can or cannot add float or int to string values like usual in Python, whether it is possible
        // or not in OG numpy or not

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

        // implement flattening out the 2d array so far?
        // do we need non-changing implementation of 1d array?
        NdArray flatten(){
            std::vector<value> arr;
            int i, j;
            if(array1d.size() != 0){
                for(i=0; i<array1d.size(); i++){
                    arr.push_back(array1d[i]);
                }
                NdArray array(arr);
                return array;
            }

            for(i=0; i<array2d.size(); i++){
                for(j=0; j<array2d[i].size(); j++){
                    arr.push_back(array2d[i][j]);
                }
            }

            NdArray array(arr);

            return array;
        }


        // find out how reshaping work with 1d or does it reshape from 2d into 1d array
        // yet to implement for the case above and for cases when one of the parameters equals '-1'
        // implement overall

        // implement for general use, because already implemented for special cases
        NdArray reshape(int row, int col=0){
            int i, j, total_vals, index;
            total_vals = -1;
            if(array1d.size() != 0){
                total_vals = shape.one_dim;
            }else{
                total_vals = shape.two_dim[0] * shape.two_dim[1];
            }

            // implemented shapes of an array to be reshaped for error line to throw when argument is invalid
            std::string dims = "";
            if(shape.two_dim.size() != 0){
                dims += '(' + std::to_string(shape.two_dim[0]) + ',' + std::to_string(shape.two_dim[1]) + ')';
            }else{
                dims += '(' + std::to_string(shape.one_dim) + ",)";
            }
            // implement shapes of array that was supposed to be like when argument is invalid
            std::string out_dims = "";
            if(col == 0){
                out_dims = "(" + std::to_string(row) + ",)";
            }else{
                out_dims = "(" + std::to_string(row) + "," + std::to_string(col) + ")";
            }

            std::string error_line = "Could not broadcast array " + dims + " into " + out_dims;

            // implemented an indirect flattening out of the arrays, i.e. for case when col is not specified
            if(col == 0){
                if(row != total_vals){
                    throw std::invalid_argument(error_line);
                }else{
                    std::vector<value> arr;
                    if(array1d.size() != 0){
                        arr = array1d;
                    }else{
                        for(i=0; i<array2d.size(); i++){
                            for(j=0; j<array2d[i].size(); j++){
                                arr.push_back(array2d[i][j]);
                            }
                        }
                    }

                    NdArray vector(arr);
                    return vector;
                }
            }
            std::vector<std::vector<value>> new_arr;

            value val;
            val.is_int = true;
            val.num = 0;
            // implementation of special cases when one of the parameters is 1 and the other one is -1
            if(col == -1 && row == 1){
                if(array1d.size() != 0){
                    new_arr.assign(1, std::vector<value>(array1d.size(), val));
                    new_arr[0] = array1d;
                    NdArray vec(new_arr);
                    return vec;
                }

                if(array2d.size() != 0){
                    new_arr.assign(1, std::vector<value>(total_vals, val));
                    index = 0;
                    for(i=0; i<array2d.size(); i++){
                        for(j=0; j<array2d[i].size(); j++){
                            new_arr[0][index] = array2d[i][j];
                            index ++;
                        }
                    }

                    NdArray vec(new_arr);

                    return vec;
                }
            }

            if(row == -1 && col == 1){
                if(array1d.size() != 0){
                    new_arr.assign(array1d.size(), std::vector<value>(1, val));
                    for(i=0; i<array1d.size(); i++){
                        new_arr[i][0] = array1d[i];
                    }
                    NdArray vec(new_arr);

                    return vec;
                }

                if(array2d.size() != 0){
                    new_arr.assign(total_vals, std::vector<value>(1, val));
                    for(i=0; i<array2d.size(); i++){
                        for(j=0; j<array2d[i].size(); j++){
                            new_arr[index][0] = array2d[i][j];
                        }
                    }
                    NdArray vec(new_arr);
                    return vec;
                }
            }

            // implementation of basic reshaping

            if(total_vals != row*col){
                throw std::invalid_argument(error_line);
            }

            if(array2d.size() != 0){
                for(i=0; i<array2d.size(); i++){
                    for(j=0; j<array2d[i].size(); j++){
                        array1d.push_back(array2d[i][j]);
                    }
                }
            }

            new_arr.assign(row, std::vector<value>(col, val));
            index = 0;
            for(i=0; i<row; i++){
                for(j=0; j<col; j++){
                    new_arr[i][j] = array1d[index];
                    index ++;
                }
            }

            NdArray vec(new_arr);

            return vec;
        }
        // yet to implement this one???
        // void array2d(std::vector<std::vector<value>> arr){
        //     return;
        // }

        // implementing diagonal method for internal use, using it on another NdArray, vetcors of different data type

        NdArray diag(){

            if(array1d.size() != 0){
                value val;
                if(array1d[0].is_float){
                    val.is_float = true;
                    val.dec = 0.0f;
                }else if(array1d[0].is_int){
                    val.is_int = true;
                    val.num = 0;
                }else{
                    val.is_obj = true;
                    val.line = "";
                }
                std::vector<std::vector<value>> new_arr(array1d.size(), std::vector<value>(array1d.size(), val));
                int i, j;
                for(i=0; i<new_arr.size(); i++){
                    for(j=0; j<new_arr.size(); j++){
                        if(i == j){
                            new_arr[i][j] = array1d[i];
                        }
                    }
                }

                NdArray vec(new_arr);
                return vec;
            }
            std::vector<value> res;
            int i, j;
            for(i=0; i<array2d.size(); i++){
                for(j=0; j<array2d[0].size(); j++){
                    if(i == j){
                        res.push_back(array2d[i][j]);
                    }
                }
            }

            NdArray vec(res);

            return vec;
        }

        NdArray diag(NdArray arr){

            if(arr.array1d.size() != 0){
                value val;
                if(arr.array1d[0].is_float){
                    val.is_float = true;
                    val.dec = 0.0f;
                }else if(arr.array1d[0].is_int){
                    val.is_int = true;
                    val.num = 0;
                }else{
                    val.is_obj = true;
                    val.line = "";
                }
                std::vector<std::vector<value>> new_arr(arr.array1d.size(), std::vector<value>(arr.array1d.size(), val));
                int i, j;
                for(i=0; i<new_arr.size(); i++){
                    for(j=0; j<new_arr.size(); j++){
                        if(i == j){
                            new_arr[i][j] = arr.array1d[i];
                        }
                    }
                }

                NdArray vec(new_arr);
                return vec;
            }
            std::vector<value> res;
            int i, j;
            for(i=0; i<arr.array2d.size(); i++){
                for(j=0; j<arr.array2d[0].size(); j++){
                    if(i == j){
                        res.push_back(arr.array2d[i][j]);
                    }
                }
            }

            NdArray vec(res);

            return vec;
        }
        // diag method for integer vector
        NdArray diag(std::vector<int> arr){
            value val;
            val.is_int = true;
            val.num = 0;

            std::vector<std::vector<value>> new_arr(arr.size(), std::vector<value>(arr.size(), val));

            int i, j;
            for(i=0; i<arr.size(); i++){
                for(j=0; j<arr.size(); j++){
                    if(i == j){
                        val.num = arr[i];
                        new_arr[i][j] = val;
                    }
                }
            }

            NdArray vec(new_arr);
            return vec;
        }

        NdArray diag(std::vector<std::vector<int>> arr){
            value val;
            val.is_int = true;
            val.num = 0;

            std::vector<value> new_arr(arr.size(), val);

            int i, j;
            for(i=0; i<arr.size(); i++){
                for(j=0; j<arr.size(); j++){
                    if(i == j){
                        val.num = arr[i][j];
                        new_arr[i] = val;
                    }
                }
            }

            NdArray vec(new_arr);
            return vec;
        }
        // diag method for float vectors
        NdArray diag(std::vector<float> arr){
            value val;
            val.is_float = true;
            val.dec = 0.0f;

            std::vector<std::vector<value>> new_arr(arr.size(), std::vector<value>(arr.size(), val));

            int i, j;
            for(i=0; i<arr.size(); i++){
                for(j=0; j<arr.size(); j++){
                    if(i == j){
                        val.dec = arr[i];
                        new_arr[i][j] = val;
                    }
                }
            }

            NdArray vec(new_arr);
            return vec;
        }

        NdArray diag(std::vector<std::vector<float>> arr){
            value val;
            val.is_float = true;
            val.dec = 0;

            std::vector<value> new_arr(arr.size(), val);

            int i, j;
            for(i=0; i<arr.size(); i++){
                for(j=0; j<arr.size(); j++){
                    if(i == j){
                        val.dec = arr[i][j];
                        new_arr[i] = val;
                    }
                }
            }

            NdArray vec(new_arr);
            return vec;
        }

        // implementing diag for string vectors
        NdArray diag(std::vector<std::string> arr){
            value val;
            val.is_obj = true;
            val.line = "";

            std::vector<std::vector<value>> new_arr(arr.size(), std::vector<value>(arr.size(), val));

            int i, j;
            for(i=0; i<arr.size(); i++){
                for(j=0; j<arr.size(); j++){
                    if(i == j){
                        val.line = arr[i];
                        new_arr[i][j] = val;
                    }
                }
            }

            NdArray vec(new_arr);
            return vec;
        }

        NdArray diag(std::vector<std::vector<std::string>> arr){
            value val;
            val.is_obj = true;
            val.line = "";

            std::vector<value> new_arr(arr.size(), val);

            int i, j;
            for(i=0; i<arr.size(); i++){
                for(j=0; j<arr.size(); j++){
                    if(i == j){
                        val.line = arr[i][j];
                        new_arr[i] = val;
                    }
                }
            }

            NdArray vec(new_arr);
            return vec;
        }






        // implementing transpose methods for 2d arrays. 1d arrays are all ignored and returned as they are but still edge cases for overload
        // functions are implemented for different data types in methods' parameters

        // as a built-in method, resembling np.array().T method - change - implement this one later


        // this method accepts NdArray classes, similar to np.transpose() of Python version but implemente as overloading function
        // for different parameters
        NdArray transpose(NdArray arr){
            return transpose_method(arr);
        }


        // the followng transpose methods are overloading functions for different parameter inputs
        // different containers with different data types
        NdArray transpose(std::vector<std::vector<int>> arr){
            NdArray vec(arr);
            return transpose_method(vec);
        }

        NdArray transpose(std::vector<std::vector<float>> arr){
            NdArray vec(arr);
            return transpose_method(vec);
        }

        NdArray transpose(std::vector<std::vector<std::string>> arr){
            NdArray vec(arr);
            return transpose_method(vec);
        }

        // this and the following three overload methods are special cases for 1d vectors passed into transpose method
        NdArray transpose(std::vector<int> arr){
            NdArray vec(arr);

            return transpose_method(vec);
        }

        NdArray transpose(std::vector<float> arr){
            NdArray vec(arr);

            return transpose_method(vec);
        }

        NdArray transpose(std::vector<std::string> arr){
            NdArray vec(arr);

            return transpose_method(vec);
        }


        // zeros method outputs the 2-d matrix full of zeros - need to add the error for throwing more than three values dims

        NdArray zeros(std::vector<int> dims){
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
            return *this;
        }

        NdArray ones(std::vector<int> dims){
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

            return *this;
        }

        // so far astype method implemented for converting from float to int for 1d arrays

        // yet to implement for other dtypes

        // implement an error in case to trasform from string to float/int

        NdArray astype(std::string data_type){
            value val;
            int i, j;
            if(data_type == "string"){
                val.is_obj = true;
                val.line = "";
            }else if(data_type == "float"){
                val.is_float = true;
                val.dec = 0.0f;
            }else{
                val.is_int = true;
                val.num = 0;
            }
            if(array1d.size() != 0){
                std::vector<value> res(array1d.size(), val);
                for(i=0; i<res.size(); i++){
                    if(data_type == "string"){
                        if(array1d[i].is_float){
                            res[i].line = std::to_string(array1d[i].dec);
                        }else if(array1d[i].is_int){
                            res[i].line = std::to_string(array1d[i].num);
                        }else{
                            res[i] = array1d[i];
                        }
                    }else if(data_type == "float"){
                        if(array1d[i].is_float){
                            res[i] = array1d[i];
                        }else if(array1d[i].is_int){
                            res[i].dec = (float)array1d[i].num;
                        }else{
                            res[i].dec = std::stof(array1d[i].line);
                        }
                    }else if(data_type == "int"){
                        if(array1d[i].is_float){
                            res[i].num = (int)array1d[i].dec;
                        }else if(array1d[i].is_int){
                            res[i] = array1d[i];
                        }else{
                            res[i].num = std::stoi(array1d[i].line);
                        }
                    }else{
                        throw std::invalid_argument("Data type not listed");
                    }
                }

                NdArray vec(res);

                return vec;
            }

            std::vector<std::vector<value>> res(array2d.size(), std::vector<value>(array2d[0].size(), val));
            for(i=0; i<res.size(); i++){
                for(j=0; j<res[i].size(); j++){
                    if(data_type == "string"){
                        if(array2d[i][j].is_float){
                            res[i][j].line = std::to_string(array2d[i][j].dec);
                        }else if(array2d[i][j].is_int){
                            res[i][j].line = std::to_string(array2d[i][j].num);
                        }else{
                            res[i][j] = array2d[i][j];
                        }
                    }else if(data_type == "float"){
                        if(array2d[i][j].is_float){
                            res[i][j] = array2d[i][j];
                        }else if(array2d[i][j].is_int){
                            res[i][j].dec = (float)array2d[i][j].num;
                        }else{
                            res[i][j].dec = std::stof(array2d[i][j].line);
                        }
                    }else if(data_type == "int"){
                        if(array2d[i][j].is_float){
                            res[i][j].num = (int)array2d[i][j].dec;
                        }else if(array2d[i][j].is_int){
                            res[i][j] = array2d[i][j];
                        }else{
                            res[i][j].num = std::stoi(array2d[i][j].line);
                        }
                    }else{
                        throw std::invalid_argument("Data type not listed");
                    }
                }
            }

            NdArray vec(res);

            return vec;
        }

        // unique method implementation - planning on relocating this classic method to private class
        // another plan is to make overload functions that would change the data types of array and represent vectors with various
        // dtypes in their containers as NdArrays and put the into a private function - seems like a better idea
        // same plan is for other functions - such as transpose, astype etc.

        // implemented unique method that would accept NdArrays as private method
        // private unique method solves basic solution for both 1d and 2d array
        // public unique methods are built for all types of basic possible inputs

        NdArray unique(NdArray arr){
            return unique_method(arr);
        }

        NdArray unique(std::vector<int> arr){
            NdArray vec(arr);
            return unique_method(arr);
        }

        NdArray unique(std::vector<float> arr){
            NdArray vec(arr);
            return unique_method(vec);
        }

        NdArray unique(std::vector<std::string> arr){
            NdArray vec(arr);
            return unique_method(vec);
        }

        NdArray unique(std::vector<std::vector<int>> arr){
            NdArray vec(arr);
            return unique_method(arr);
        }

        NdArray unique(std::vector<std::vector<float>> arr){
            NdArray vec(arr);
            return unique_method(vec);
        }

        NdArray unique(std::vector<std::vector<std::string>> arr){
            NdArray vec(arr);
            return unique_method(vec);
        }


        // implementation of nunique method showing the number of unique values (not the unique values themselves)

        int nunique(NdArray arr){
            return nunique_method(arr);
        }

        int nunique(std::vector<std::vector<int>> arr){
            NdArray vec(arr);
            return nunique_method(vec);
        }

        int nunique(std::vector<std::vector<float>> arr){
            NdArray vec(arr);
            return nunique_method(vec);
        }

        int nunique(std::vector<std::vector<std::string>> arr){
            NdArray vec(arr);
            return nunique_method(vec);
        }

        int nunique(std::vector<int> arr){
            NdArray vec(arr);
            return nunique_method(vec);
        }

        int nunique(std::vector<float> arr){
            NdArray vec(arr);
            return nunique_method(vec);
        }

        int nunique(std::vector<std::string> arr){
            NdArray vec(arr);
            return nunique_method(vec);
        }

        // implementation of publicly accessible method of dot - multiplication of two 2-d matrices of various dtypes
        // overload functions for both vector containers with various dtypes and their combinations

        NdArray dot(NdArray arr_one, NdArray arr_two){
            return mat_mul(arr_one, arr_two);
        }

        NdArray dot(std::vector<std::vector<int>> one, std::vector<std::vector<int>> two){
            NdArray arr_one(one);
            NdArray arr_two(two);

            return mat_mul(arr_one, arr_two);
        }

        NdArray dot(std::vector<std::vector<float>> one, std::vector<std::vector<float>> two){
            NdArray arr_one(one);
            NdArray arr_two(two);

            return mat_mul(arr_one, arr_two);
        }

        NdArray dot(std::vector<std::vector<int>> one, std::vector<std::vector<float>> two){
            NdArray arr_one(one);
            NdArray arr_two(two);

            return mat_mul(arr_one, arr_two);
        }

        NdArray dot(std::vector<std::vector<float>> one, std::vector<std::vector<int>> two){
            NdArray arr_one(one);
            NdArray arr_two(two);

            return mat_mul(arr_one, arr_two);
        }



        // methods for pointwise elements addition
        // implemented overloading methods for practically every case of inputs as parameters
        // 1d and 2d vector containers vs NdArray types - done
        // 1d vs 1d vectors with various (int, float) data types stored in them - done
        // 1d vs 2d and vice versa vector container with various data types stored - done
        // 2d vs 2d vectors with various data types - done

        
        // basic case for NdArray vectors
        NdArray add(NdArray one, NdArray two){
            return mat_add(one, two);
        }

        // cases for NdArrays vs 1d and 2d vector containers

        NdArray add(NdArray one, std::vector<float> two){
            NdArray vec(two);
            return mat_add(one, vec);
        }

        NdArray add(NdArray one, std::vector<int> two){
            NdArray vec(two);
            return mat_add(one, vec);
        }

        NdArray add(NdArray one, std::vector<std::vector<float>> two){
            NdArray vec(two);
            return mat_add(one, vec);
        }

        NdArray add(NdArray one, std::vector<std::vector<int>> two){
            NdArray vec(two);
            return mat_add(one, vec);
        }

        NdArray add(std::vector<float> one, NdArray two){
            NdArray vec(one);
            return mat_add(vec, two);
        }

        NdArray add(std::vector<int> one, NdArray two){
            NdArray vec(one);
            return mat_add(vec, two);
        }

        NdArray add(std::vector<std::vector<float>> one, NdArray two){
            NdArray vec(one);
            return mat_add(vec, two);
        }

        NdArray add(std::vector<std::vector<int>> one, NdArray two){
            NdArray vec(one);
            return mat_add(vec, two);
        }

        // 1d vs 1d vectors

        NdArray add(std::vector<int> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<int> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<float> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<float> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }
        
        // 2d vs 1d vector containers interaction cases

        NdArray add(std::vector<int> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<int> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<float> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<float> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<std::vector<int>> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<std::vector<float>> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<std::vector<int>> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<std::vector<float>> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        // 2d vs 2d vectors containers interactions

        NdArray add(std::vector<std::vector<int>> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<std::vector<int>> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<std::vector<float>> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<std::vector<float>> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(NdArray one, int two){
            std::vector<int> v;
            v.push_back(two);
            NdArray vec(v);
            return mat_add(one, vec);
        }

        NdArray add(int one, NdArray two){
            std::vector<int> v;
            v.push_back(one);
            NdArray vec(v);
            return mat_add(vec, two);
        }

        NdArray add(NdArray one, float two){
            std::vector<float> v;
            v.push_back(two);
            NdArray vec(v);
            return mat_add(one, vec);
        }

        NdArray add(float one, NdArray two){
            std::vector<float> v;
            v.push_back(one);
            NdArray vec(v);
            return mat_add(vec, two);
        }

        NdArray add(std::vector<int> one, int two){
            std::vector<int> v;
            v.push_back(two);
            NdArray vec1(one);
            NdArray vec2(v);
            return mat_add(vec1, vec2);
        }

        NdArray add(int one, std::vector<int> two){
            std::vector<int> v;
            v.push_back(one);
            NdArray vec1(v);
            NdArray vec2(two);
            return mat_add(vec1, vec2);
        }

        NdArray add(std::vector<int> one, float two){
            std::vector<float> v;
            v.push_back(two);
            NdArray vec(v);
            
            return mat_add(one, vec);
        }

        NdArray add(float one, NdArray two){
            std::vector<float> v;
            v.push_back(one);
            NdArray vec(v);
            return mat_add(vec, two);
        }


        // methods for pointwise elements subtraction
        // implemented overloading methods for practically every case of inputs as parameters
        // 1d and 2d vector containers vs NdArray types - done
        // 1d vs 1d vectors with various (int, float) data types stored in them - done
        // 1d vs 2d and vice versa vector container with various data types stored - done
        // 2d vs 2d vectors with various data types - done

        
        // basic case for NdArray vectors
        NdArray subtract(NdArray one, NdArray two){
            return mat_subtract(one, two);
        }

        // cases for NdArrays vs 1d and 2d vector containers

        NdArray subtract(NdArray one, std::vector<float> two){
            NdArray vec(two);
            return mat_subtract(one, vec);
        }

        NdArray subtract(NdArray one, std::vector<int> two){
            NdArray vec(two);
            return mat_subtract(one, vec);
        }

        NdArray subtract(NdArray one, std::vector<std::vector<float>> two){
            NdArray vec(two);
            return mat_subtract(one, vec);
        }

        NdArray subtract(NdArray one, std::vector<std::vector<int>> two){
            NdArray vec(two);
            return mat_subtract(one, vec);
        }

        NdArray subtract(std::vector<float> one, NdArray two){
            NdArray vec(one);
            return mat_subtract(vec, two);
        }

        NdArray subtract(std::vector<int> one, NdArray two){
            NdArray vec(one);
            return mat_subtract(vec, two);
        }

        NdArray subtract(std::vector<std::vector<float>> one, NdArray two){
            NdArray vec(one);
            return mat_subtract(vec, two);
        }

        NdArray subtract(std::vector<std::vector<int>> one, NdArray two){
            NdArray vec(one);
            return mat_subtract(vec, two);
        }

        // 1d vs 1d vectors

        NdArray subtract(std::vector<int> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<int> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<float> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<float> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }
        
        // 2d vs 1d vector containers interaction cases

        NdArray subtract(std::vector<int> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<int> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<float> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<float> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<std::vector<int>> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<std::vector<float>> one, std::vector<int> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<std::vector<int>> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<std::vector<float>> one, std::vector<float> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        // 2d vs 2d vectors containers interactions

        NdArray subtract(std::vector<std::vector<int>> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<std::vector<int>> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<std::vector<float>> one, std::vector<std::vector<int>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }

        NdArray subtract(std::vector<std::vector<float>> one, std::vector<std::vector<float>> two){
            NdArray vec1(one);
            NdArray vec2(two);
            return mat_subtract(vec1, vec2);
        }


    private:

        // implemented basic matrix multiplication between two NdArray 2-d matrices
        // yet to research the interaction between 1d and 2d matrices and between 1d matrices
        // implement the error in shape broadcasting in future to throw an error
        // yet to implement various dynamics - between 1d vectors
        // yet to implement case for inputs 1d and 2d matrices

        NdArray mat_mul(NdArray one, NdArray two){
            if(one.shape.two_dim[1] != two.shape.two_dim[0]){
                std::string error_line = "Cannot broadcast and multiply matrices of shapes (" + std::to_string(one.shape.two_dim[0]) + ", " + std::to_string(one.shape.two_dim[1]) + ") and (";
                error_line += std::to_string(two.shape.two_dim[0]) + ", " +std::to_string(two.shape.two_dim[1]) + ")\n";
                throw std::invalid_argument(error_line);
            }
            if(one.dtype == "float" && two.dtype == "int"){
                two = two.astype("float");
            }else if(one.dtype == "int" && two.dtype == "float"){
                one = one.astype("float");
            }

            value val, backup_val;
            if(one.dtype == "float"){
                val.is_float = true;
                val.dec = 0.0f;
            }else if(two.dtype == "int"){
                val.is_int = true;
                val.num = 0;
            }

            backup_val = val;

            value temp;

            std::vector<std::vector<value>> res;
            std::vector<value> t_mat;

            int i, j, k;
            for(i=0; i<one.shape.two_dim[0]; i++){
                for(j=0; j<two.shape.two_dim[1]; j++){
                    temp = val;
                    for(k=0; k<one.shape.two_dim[1]; k++){
                        backup_val = one.array2d[i][k];
                        backup_val *= two.array2d[k][j];
                        temp += backup_val;
                    }
                    t_mat.push_back(temp);
                }
                res.push_back(t_mat);
                std::vector<value>().swap(t_mat);
            }

            NdArray vec(res);

            return vec;
        }

        // implemented matrices and vectors addition in private class to be universal for different kinds of parameters input
        // for overload functions
        // implemented pretty much all edge cases for 1d vectors - done
        // implemented addition of 1d vectors to 2d matrices - done
        // implemented the addition of matrices - done

        NdArray mat_add(NdArray one, NdArray two){
            if(one.dtype == "float" && two.dtype == "int"){
                two = two.astype("float");
            }
            if(one.dtype == "int" && two.dtype == "float"){
                one = one.astype("float");
            }
            if(one.shape.two_dim.size() == 0 && two.shape.two_dim.size() == 0){
                if(one.shape.one_dim == 1 || two.shape.one_dim == 1){
                    value val_to_add;
                    val_to_add = (one.shape.one_dim == 1)?(one.array1d[0]):(two.array1d[0]);
                    std::vector<value> res;
                    res = (one.shape.one_dim == 1)?(two.array1d):(one.array1d);
                    for(int i=0; i<res.size(); i++){
                        res[i] += val_to_add;
                    }

                    NdArray vec(res);
                    return vec;
                }

                if(one.shape.one_dim != two.shape.one_dim){
                    std::string error_line = "Cannot broadcats together shapes of size (";
                    error_line += std::to_string(one.shape.one_dim) + ",) and (" + std::to_string(two.shape.one_dim) + ",)\n";
                    throw std::invalid_argument(error_line);
                }

                for(int i = 0; i<one.shape.one_dim; i++){
                    one.array1d[i] += two.array1d[i];
                }

                return one;
            }

            if(one.shape.two_dim.size() == 0 || two.shape.two_dim.size() == 0){
                std::string error_line = "Cannot broadcast together shapes of size (";
                int i, j;
                if(one.shape.two_dim.size() == 0){
                    if(one.shape.one_dim != two.shape.two_dim[1]){
                        error_line += std::to_string(one.shape.one_dim) + ",) and (";
                        error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ")\n";
                        throw std::invalid_argument(error_line);
                    }

                    if(one.shape.one_dim == 1){
                        for(i=0; i<two.shape.two_dim[0]; i++){
                            for(j=0; j<two.shape.two_dim[1]; j++){
                                two.array2d[i][j] += one.array1d[0];
                            }
                        }

                        return two;
                    }

                    for(i=0; i<two.shape.two_dim[0]; i++){
                        for(j=0; j<two.shape.two_dim[1]; j++){
                            two.array2d[i][j] += one.array1d[j];
                        }
                    }

                    return two;
                }
                if(two.shape.two_dim.size() == 0){
                    if(one.shape.two_dim[1] != two.shape.one_dim){
                        error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ") and (";
                        error_line += std::to_string(one.shape.one_dim) + ",)\n";
                        throw std::invalid_argument(error_line);
                    }

                    if(two.shape.one_dim == 1){
                        for(i=0; i<one.shape.two_dim[0]; i++){
                            for(j=0; j<one.shape.two_dim[1]; j++){
                                one.array2d[i][j] += two.array1d[0];
                            }
                        }

                        return one;
                    }

                    for(i=0; i<one.shape.two_dim[0]; i++){
                        for(j=0; j<one.shape.two_dim[1]; j++){
                            one.array2d[i][j] += two.array1d[j];
                        }
                    }

                    return one;
                }
            }


            if(one.shape.two_dim[1] != two.shape.two_dim[1] && one.shape.two_dim[0] != two.shape.two_dim[0]){
                std::string error_line = "Cannot broadcast together shapes of size (";
                error_line += std::to_string(one.shape.two_dim[0]) + ',' + std::to_string(one.shape.two_dim[1]) + ") and (";
                error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ")\n";

                throw std::invalid_argument(error_line);
            }

            int i, j;
            for(i=0; i<one.shape.two_dim[0]; i++){
                for(j=0; j<one.shape.two_dim[1]; j++){
                    one.array2d[i][j] += two.array2d[i][j];
                }
            }

            return one;
        };



        // implemented matrices and vectors subtraction in private class to be universal for different kinds of parameters input
        // for overload functions
        // implemented pretty much all edge cases for 1d vectors - done
        // implemented subtraction of 1d vectors to 2d matrices - done
        // implemented the subtraction of matrices - done


        NdArray mat_subtract(NdArray one, NdArray two){
            if(one.dtype == "float" && two.dtype == "int"){
                two = two.astype("float");
            }
            if(one.dtype == "int" && two.dtype == "float"){
                one = one.astype("float");
            }
            if(one.shape.two_dim.size() == 0 && two.shape.two_dim.size() == 0){
                if(one.shape.one_dim == 1 || two.shape.one_dim == 1){
                    value val_to_add;
                    val_to_add = (one.shape.one_dim == 1)?(one.array1d[0]):(two.array1d[0]);
                    std::vector<value> res;
                    res = (one.shape.one_dim == 1)?(two.array1d):(one.array1d);
                    for(int i=0; i<res.size(); i++){
                        res[i] -= val_to_add;
                    }

                    NdArray vec(res);
                    return vec;
                }

                if(one.shape.one_dim != two.shape.one_dim){
                    std::string error_line = "Cannot broadcats together shapes of size (";
                    error_line += std::to_string(one.shape.one_dim) + ",) and (" + std::to_string(two.shape.one_dim) + ",)\n";
                    throw std::invalid_argument(error_line);
                }

                for(int i = 0; i<one.shape.one_dim; i++){
                    one.array1d[i] -= two.array1d[i];
                }

                return one;
            }

            if(one.shape.two_dim.size() == 0 || two.shape.two_dim.size() == 0){
                std::string error_line = "Cannot broadcast together shapes of size (";
                int i, j;
                if(one.shape.two_dim.size() == 0){
                    if(one.shape.one_dim != two.shape.two_dim[1]){
                        error_line += std::to_string(one.shape.one_dim) + ",) and (";
                        error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ")\n";
                        throw std::invalid_argument(error_line);
                    }

                    if(one.shape.one_dim == 1){
                        for(i=0; i<two.shape.two_dim[0]; i++){
                            for(j=0; j<two.shape.two_dim[1]; j++){
                                two.array2d[i][j] -= one.array1d[0];
                            }
                        }

                        return two;
                    }

                    for(i=0; i<two.shape.two_dim[0]; i++){
                        for(j=0; j<two.shape.two_dim[1]; j++){
                            two.array2d[i][j] -= one.array1d[j];
                        }
                    }

                    return two;
                }
                if(two.shape.two_dim.size() == 0){
                    if(one.shape.two_dim[1] != two.shape.one_dim){
                        error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ") and (";
                        error_line += std::to_string(one.shape.one_dim) + ",)\n";
                        throw std::invalid_argument(error_line);
                    }

                    if(two.shape.one_dim == 1){
                        for(i=0; i<one.shape.two_dim[0]; i++){
                            for(j=0; j<one.shape.two_dim[1]; j++){
                                one.array2d[i][j] -= two.array1d[0];
                            }
                        }

                        return one;
                    }

                    for(i=0; i<one.shape.two_dim[0]; i++){
                        for(j=0; j<one.shape.two_dim[1]; j++){
                            one.array2d[i][j] -= two.array1d[j];
                        }
                    }

                    return one;
                }
            }


            if(one.shape.two_dim[1] != two.shape.two_dim[1] && one.shape.two_dim[0] != two.shape.two_dim[0]){
                std::string error_line = "Cannot broadcast together shapes of size (";
                error_line += std::to_string(one.shape.two_dim[0]) + ',' + std::to_string(one.shape.two_dim[1]) + ") and (";
                error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ")\n";

                throw std::invalid_argument(error_line);
            }

            int i, j;
            for(i=0; i<one.shape.two_dim[0]; i++){
                for(j=0; j<one.shape.two_dim[1]; j++){
                    one.array2d[i][j] -= two.array2d[i][j];
                }
            }

            return one;
        };



        // implemented matrices and vectors pointwise multiplication in private class to be universal for different kinds of parameters input
        // for overload functions
        // implemented pretty much all edge cases for 1d vectors - done
        // implemented addition of 1d vectors to 2d matrices - done
        // implemented the addition of matrices - done

        NdArray pointwise_multiplication(NdArray one, NdArray two){
            if(one.dtype == "float" && two.dtype == "int"){
                two = two.astype("float");
            }
            if(one.dtype == "int" && two.dtype == "float"){
                one = one.astype("float");
            }
            if(one.shape.two_dim.size() == 0 && two.shape.two_dim.size() == 0){
                if(one.shape.one_dim == 1 || two.shape.one_dim == 1){
                    value val_to_add;
                    val_to_add = (one.shape.one_dim == 1)?(one.array1d[0]):(two.array1d[0]);
                    std::vector<value> res;
                    res = (one.shape.one_dim == 1)?(two.array1d):(one.array1d);
                    for(int i=0; i<res.size(); i++){
                        res[i] *= val_to_add;
                    }

                    NdArray vec(res);
                    return vec;
                }

                if(one.shape.one_dim != two.shape.one_dim){
                    std::string error_line = "Cannot broadcats together shapes of size (";
                    error_line += std::to_string(one.shape.one_dim) + ",) and (" + std::to_string(two.shape.one_dim) + ",)\n";
                    throw std::invalid_argument(error_line);
                }

                for(int i = 0; i<one.shape.one_dim; i++){
                    one.array1d[i] *= two.array1d[i];
                }

                return one;
            }

            if(one.shape.two_dim.size() == 0 || two.shape.two_dim.size() == 0){
                std::string error_line = "Cannot broadcast together shapes of size (";
                int i, j;
                if(one.shape.two_dim.size() == 0){
                    if(one.shape.one_dim != two.shape.two_dim[1]){
                        error_line += std::to_string(one.shape.one_dim) + ",) and (";
                        error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ")\n";
                        throw std::invalid_argument(error_line);
                    }

                    if(one.shape.one_dim == 1){
                        for(i=0; i<two.shape.two_dim[0]; i++){
                            for(j=0; j<two.shape.two_dim[1]; j++){
                                two.array2d[i][j] *= one.array1d[0];
                            }
                        }

                        return two;
                    }

                    for(i=0; i<two.shape.two_dim[0]; i++){
                        for(j=0; j<two.shape.two_dim[1]; j++){
                            two.array2d[i][j] *= one.array1d[j];
                        }
                    }

                    return two;
                }
                if(two.shape.two_dim.size() == 0){
                    if(one.shape.two_dim[1] != two.shape.one_dim){
                        error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ") and (";
                        error_line += std::to_string(one.shape.one_dim) + ",)\n";
                        throw std::invalid_argument(error_line);
                    }

                    if(two.shape.one_dim == 1){
                        for(i=0; i<one.shape.two_dim[0]; i++){
                            for(j=0; j<one.shape.two_dim[1]; j++){
                                one.array2d[i][j] *= two.array1d[0];
                            }
                        }

                        return one;
                    }

                    for(i=0; i<one.shape.two_dim[0]; i++){
                        for(j=0; j<one.shape.two_dim[1]; j++){
                            one.array2d[i][j] *= two.array1d[j];
                        }
                    }

                    return one;
                }
            }


            if(one.shape.two_dim[1] != two.shape.two_dim[1] && one.shape.two_dim[0] != two.shape.two_dim[0]){
                std::string error_line = "Cannot broadcast together shapes of size (";
                error_line += std::to_string(one.shape.two_dim[0]) + ',' + std::to_string(one.shape.two_dim[1]) + ") and (";
                error_line += std::to_string(two.shape.two_dim[0]) + ',' + std::to_string(two.shape.two_dim[1]) + ")\n";

                throw std::invalid_argument(error_line);
            }

            int i, j;
            for(i=0; i<one.shape.two_dim[0]; i++){
                for(j=0; j<one.shape.two_dim[1]; j++){
                    one.array2d[i][j] *= two.array2d[i][j];
                }
            }

            return one;
        };

        NdArray unique_method(NdArray arr){
            std::set<value> stk;
            int i, j;
            if(arr.shape.two_dim.size() == 0){
                for(i=0; i<arr.shape.one_dim; i++){
                    stk.insert(arr.array1d[i]);
                }
                NdArray vec(stk);

                return vec;
            }

            for(i=0; i<arr.shape.two_dim[0]; i++){
                for(j=0; j<arr.shape.two_dim[1]; j++){
                    stk.insert(arr.array2d[i][j]);
                }
            }

            NdArray vec(stk);

            return vec;
        }
        // this method accepts NdArray classes, similar to np.transpose() of Python version but implemente as overloading function
        NdArray transpose_method(NdArray arr){
            if(arr.array1d.size() != 0){
                return arr;
            }

            int i, j;
            std::vector<std::vector<value>> res;
            std::vector<value> temp;
            for(i=0; i<arr.array2d[0].size(); i++){
                for(j=0; j<arr.array2d.size(); j++){
                    temp.push_back(arr.array2d[j][i]);
                }
                res.push_back(temp);
                std::vector<value>().swap(temp);
            }

            NdArray vec(res);
            return vec;
        }

        int nunique_method(NdArray arr){
            return unique(arr).shape.one_dim;
        }
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
std::ostream& operator<<(std::ostream& os, NdArray::dimensions& val){
    if(val.one_dim > -1){
        os << '(' << val.one_dim << ",)";
        return os;
    }

    os << '(' << val.two_dim[0] << ',' << val.two_dim[1] << ')';
    return os;
}