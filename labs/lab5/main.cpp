// in a new file or above main in the same file

#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <iostream>
#include "cos_fun.h"
#include "dot_prod_fun.h"
using namespace std;

vector<pair<double, pair<int, int>>> compute_cosine_distances(const vector<string>& input_strs) {
    vector<vector<double>> vectors;

    for (const auto& str : input_strs) {
        stringstream ss(str);
        vector<double> temp_vector;
        double num;
        while (ss >> num) {
            temp_vector.push_back(num);
        }
        if (!temp_vector.empty()) {
            vectors.push_back(temp_vector);
        }
    }

    if (vectors.size() < 2) {
        throw runtime_error("Not enough vectors to compute distances!");
    }

    vector<pair<double, pair<int, int>>> distances;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double dist = cosine_distance(vectors[i], vectors[j]);
            distances.push_back({dist, {i, j}});
        }
    }

    sort(distances.begin(), distances.end());
    return distances;
}
