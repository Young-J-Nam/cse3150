#ifndef cosfun_H
#define cosfun_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "dot_prod_fun.h"

using namespace std;

double cosine_similarity(const vector<double>& a, const vector<double>& b) {
    return dot_product(a, b) / (magnitude(a) * magnitude(b));
}


double cosine_distance(const vector<double>& a, const vector<double>& b) {
    return 1.0 - cosine_similarity(a, b);
}