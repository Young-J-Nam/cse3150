#include "cos_fun.h"
#include "dot_prod_fun.h"
#include <cmath>

double cosine_similarity(const std::vector<double>& a, const std::vector<double>& b) {
    return dot_product(a, b) / (magnitude(a) * magnitude(b));
}

double cosine_distance(const std::vector<double>& a, const std::vector<double>& b) {
    return 1.0 - cosine_similarity(a, b);
}
