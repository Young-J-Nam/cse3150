#ifndef FRACTIONS_H
#define FRACTIONS_H

#include "bigint.h" 
#include <utility> 
#include <stdexcept> 

std::pair<bigint, bigint> addFractions(std::pair<bigint, bigint> f1, std::pair<bigint, bigint> f2) { //add two large fractions
    const bigint ZERO("0");
    if (f1.second == ZERO || f2.second == ZERO) {
        throw std::invalid_argument("Denominator can't be zero");
    }
    bigint a = f1.first;
    bigint b = f1.second; 
    bigint c = f2.first; 
    bigint d = f2.second; 
    bigint numerator = a * d + c * b;
    bigint denominator = b * d;
    return {numerator, denominator}; 
}

std::pair<bigint, bigint> multiplyFractions(std::pair<bigint, bigint> f1, std::pair<bigint, bigint> f2) //multiplies two large fractions
 {
    //the denominator of any fraction cannot be zero, otherwise, it will be undefined 
    const bigint ZERO("0");
    if (f1.second == ZERO || f2.second == ZERO) {
        throw std::invalid_argument("Denominator can't be zero");
    }
    
    bigint numerator = f1.first * f2.first;
    bigint denominator = f1.second * f2.second;
    return {numerator, denominator};
}

#endif