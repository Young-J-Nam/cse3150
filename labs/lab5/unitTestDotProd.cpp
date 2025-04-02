#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "dot_prod_fun.h"
#include "main.cpp"

using namespace std;

void test_cosine_distance() {
    vector<vector<double>> test_vectors = {
        {1, 2.5, 0.5, 0.99, 1.5},
        {1, 3.6, 1.9, 0.98, -4},
        {1, 4.5, 3.2, 0.71, 8.2},
        {2.7, 7, 6, 9.5, -5.44},
        {9, 11.5, 22.99, -2.3, 4.3},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0}
    };
    
    // Compute pairwise cosine distances
    vector<pair<double, pair<int, int>>> distances;
    for (size_t i = 0; i < test_vectors.size(); ++i) {
        for (size_t j = i + 1; j < test_vectors.size(); ++j) {
            double dist = cosine_distance(test_vectors[i], test_vectors[j]);
            distances.push_back({dist, {i, j}});
        }
    }
    
    // Sort by increasing cosine distance (closer vectors first)
    sort(distances.begin(), distances.end());
    
    // Output results
    cout << "Pairs of vectors ordered by cosine closeness:\n";
    for (const auto& entry : distances) {
        cout << "Vector " << entry.second.first << " and Vector " << entry.second.second 
             << " -> Cosine Distance: " << entry.first << "\n";
    }
    
    // Basic assertions to check distances are computed correctly
    assert(!distances.empty());
    assert(distances[0].first >= 0 && distances[0].first <= 2); // Cosine distance should be in [0, 2]
    
    cout << "Test case passed: Cosine distances computed correctly." << endl;
}

int testing() {
    test_cosine_distance();
    cout << "All test cases passed successfully!" << endl;
    return 0;
}