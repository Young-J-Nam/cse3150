#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "cos_fun.h"
#include "dot_prod_fun.h"

#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Your testable logic
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

TEST_CASE("Cosine distance between simple 2D vectors") {
    vector<string> input = {
        "1 0",   // Vector 0
        "0 1",   // Vector 1
        "1 1"    // Vector 2
    };

    auto result = compute_cosine_distances(input);

    CHECK(result.size() == 3);

    CHECK(doctest::Approx(result[0].first).epsilon(0.001) == 0.29289); // (0,2) or (1,2)
    CHECK(doctest::Approx(result[1].first).epsilon(0.001) == 0.29289); // (0,2) or (1,2)
    CHECK(doctest::Approx(result[2].first).epsilon(0.001) == 1.0);     // (0,1)
}

TEST_CASE("Cosine distance between identical vectors") {
    vector<string> input = {
        "1 2 3",
        "1 2 3"
    };

    auto result = compute_cosine_distances(input);

    CHECK(result.size() == 1);
    CHECK(doctest::Approx(result[0].first).epsilon(0.001) == 0.0); // identical -> distance 0
}


TEST_CASE("Cosine distance between opposite vectors") {
    vector<string> input = {
        "1 0",
        "-1 0"
    };

    auto result = compute_cosine_distances(input);

    CHECK(result.size() == 1);
    CHECK(doctest::Approx(result[0].first).epsilon(0.001) == 2.0); // angle 180° → similarity -1 → distance 2
}

TEST_CASE("Cosine distance ignores empty or invalid input vectors") {
    vector<string> input = {
        "1 0 0",
        "   ",          // should be ignored
        "0 1 0",
        "",             // should be ignored
        "0 0 1"
    };

    auto result = compute_cosine_distances(input);

    CHECK(result.size() == 3); // 3 valid vectors = 3 unique pairs

    // Quick sanity check on a known pair
    CHECK(doctest::Approx(result[2].first).epsilon(0.001) == 1.0); // orthogonal vectors
}
