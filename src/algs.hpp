#pragma once

#include <iostream>
#include <boost/array.hpp>
#include <boost/multi_array.hpp>
#include <boost/next_prior.hpp>

template <typename T, std::size_t dims>
using tensor = boost::multi_array<T,dims>;

// template <typename T>
// using matrix = tensor<T,2>;

auto& extents = boost::extents;

template <typename T, std::size_t num>
using array = boost::array<T,num>;

template <std::size_t dims>
using index = array<std::size_t,dims>;

template <typename T, std::size_t dims>
void print_t(std::ostream& os, const tensor<T,dims>& A);

template <typename T, std::size_t dims>
void print_t(std::ostream& os, const tensor<T,1>& A)
{
    using boost::next;
    typename tensor<T,dims>::const_iterator i;
    
    os << "[";
    for (i = A.begin(); i != A.end(); ++i) {
        os << *i;
        if (next(i) != A.end()){
            os << ',';
        }
    }
    os << "]";
}

template <typename T, std::size_t dims>
void print_t(std::ostream& os, const tensor<T,dims>& A)
{
    using boost::next;
    typename tensor<T,dims>::const_iterator i;
    
    os << "[" ;
    for (i = A.begin(); i != A.end(); ++i) {
        print_t<T,dims-1>(os, *i);
        if (next(i) != A.end()){
            os << ',' << std::endl;
        }
    }
    os << "]";
}

// template <typename T, std::size_t dims>
// tensor<T, dims> set_value(tensor<T, dims> A, T value){
    // auto ndims = A.num_dimensions();
    // auto shape = A.shape();
    // index<dims> idx = {};
    // A(idx) = value;
    // auto ele = A(idx); //dbg
    // std::size_t ii = 0;
    // while(ii<ndims){
        // if (idx[ii]<shape[ii]-1){
            // idx[ii]++;
            // auto ele = A(idx);//dbg
            // A(idx) = value;
            // ele = A(idx);//dbg
            // ii=0;
        // }else{
            // idx[ii]=0;
            // ii++;
        // }
    // }
    // return A;
// }
