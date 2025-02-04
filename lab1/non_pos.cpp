#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"

bool non_pos(const int* arr, int len) {
    int current_sum = 0;
    for (int i = 0; i < len; ++i) {
        current_sum += arr[i];
        if (current_sum > 0) {
            return false;
        }
    }
    return true;
}


TEST_CASE("Test case 1: All neg") {
    int test1[] = {-1, -1, -1, -1};
    CHECK(non_pos(test1, 4));
}

TEST_CASE("Test case 2: All pos") {
    int test2[] = {1, 1, 1, 1};
    CHECK_FALSE(non_pos(test2, 4));
}

TEST_CASE("Test case 3: First ele pos") {
    int test3[] = {1, -1, -1, -1};
    CHECK_FALSE(non_pos(test3, 4));
}

TEST_CASE("Test case4: Sum exceeds in middle") {
    int test4[] = {-1, 1, 1, -1};
    CHECK_FALSE(non_pos(test4, 4));
}

TEST_CASE("Test case5: Sum reaches zero but not exceed") {
    int test5[] = {-1, 1, -1, 1};
    CHECK(non_pos(test5, 4));
}

TEST_CASE("Test case6: Ends at zero after negatives") {
    int test6[] = {-1, -1, 1, 1};
    CHECK(non_pos(test6, 4));
}

TEST_CASE("Test case7: All negatives again") {
    int test7[] = {-1, -1, -1, -1};
    CHECK(non_pos(test7, 4));
}

TEST_CASE("Test case 8: Empty List"){
    int test8[] = {};
    CHECK(non_pos(test8, 0));
}