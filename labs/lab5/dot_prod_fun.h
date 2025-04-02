#ifndef dotprodfun_H
#define dotprodfun_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

double dot_product(const vector<double>& a, const vector<double>& b) {
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

double magnitude(const vector<double>& v) {
    return sqrt(dot_product(v, v));
}

#endif