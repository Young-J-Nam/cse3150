#include "rand_arr.h"
#include <iostream>

int* create_array(int n){
    if (n == 0){
        int *arr = nullptr;
        return arr;
    }
    int *arr = new int[2*n];

    for(int i = 0; i < n; i++){
        arr[i] = 1;
    }

    for(int i = n; i < (2*n); i++){
        arr[i] = -1;
    }

    return arr;
}