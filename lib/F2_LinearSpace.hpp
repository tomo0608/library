#pragma once

#include<vector>
#include "utility.hpp"

namespace tomo0608{
    template<typename T> // unsigned int, unsigned long long
    struct F2_LinearSpace
    {
        std::vector<T> basis;  // basis of linear space
        F2_LinearSpace(){}
        F2_LinearSpace(std::vector<T> basis, bool is_reduced=false):basis(basis){
            if(!is_reduced) reduce();
        }

        int dim(){return basis.size();}

        bool add_element(T x){
            for(auto && e: basis){
                if(v == 0) break;
                chmin(v, v ^ e);
            }
            if(v == 0) return false;
            basis.emplace_back(v);
            return true;
        }

        void reduce(){
            F2_LinearSpace tmp;
            for(auto &&e: basis)tmp.add_element(e);
            *this = tmp;
        }

        bool contains(T v){
            for(auto && e: basis){
                if(v == 0) break;
                chmin(v, v ^ e);
            }
            return v == 0;
        }

        bool is_independent(T v){
            return !contains(v);
        }

        T get_max(T xor_val = 0){ // return max_{v \in V} v ^ xor_val
            for(auto &&e: basis)chmax(xor_val, xor_val ^ e);
            return xor_val;
        }

        T get_min(T xor_val = 0){ // return min_{v \in V} v ^ xor_val
            for(auto &&e: basis)chmin(xor_val, xor_val ^ e);
            return xor_val;
        }

        static F2_LinearSpace union(F2_LinearSpace a, F2_LinearSpace b){
            if(a.dim() < b.dim())std::swap(a, b);
            for(auto &&e: b.basis)a.add_element(e);
            return a;
        }

        // TODO :  orthogonal_space, intersection
    };
    
}// namespace tomo0608