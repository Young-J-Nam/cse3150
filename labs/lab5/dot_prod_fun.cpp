#include "dot_prod_fun.h"
#include <cmath>

double dot_product(const std::vector<double>& a, const std::vector<double>& b) {
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

double magnitude(const std::vector<double>& v) {
    return std::sqrt(dot_product(v, v));
}
