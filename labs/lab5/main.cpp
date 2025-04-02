#include "cos_fun.h"
#include "dot_prod_fun.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

int main(int argc, char* argv[]) {
    vector<vector<double>> vectors;
    
    for (int i = 1; i < argc; ++i) {
        stringstream ss(argv[i]);
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
        cerr << "Not enough vectors to compute distances!\n";
        return 1;
    }
    
    vector<pair<double, pair<int, int>>> distances;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double dist = cosine_distance(vectors[i], vectors[j]);
            distances.push_back({dist, {i, j}});
        }
    }
    
    sort(distances.begin(), distances.end());
    
    cout << "Pairs of vectors ordered by cosine closeness:\n";
    for (const auto& entry : distances) {
        cout << "Vector " << entry.second.first << " and Vector " << entry.second.second 
             << " -> Cosine Distance: " << entry.first << "\n";
    }
    
    return 0;
}
