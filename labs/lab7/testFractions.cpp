#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bigint.h"
#include "fractions.h"

TEST_CASE("undefined fractions") {
    std::pair<bigint, bigint> f1 = {bigint("5"), bigint("0")}; 
    std::pair<bigint, bigint> f2 = {bigint("1"), bigint("2")}; 

    CHECK_THROWS_AS(addFractions(f1, f2), std::invalid_argument);
    CHECK_THROWS_AS(multiplyFractions(f1, f2), std::invalid_argument);

    CHECK_THROWS_AS(addFractions(f2, f1), std::invalid_argument);
    CHECK_THROWS_AS(multiplyFractions(f2, f1), std::invalid_argument);
}
TEST_CASE("Zero numerator should not throw") {
    auto f1 = std::make_pair(bigint("0"), bigint("99"));
    auto f2 = std::make_pair(bigint("1"), bigint("3"));

    auto sum = addFractions(f1, f2);
    CHECK(sum.first == bigint("1") * bigint("99"));
    CHECK(sum.second == bigint("297"));

    auto prod = multiplyFractions(f1, f2);
    CHECK(prod.first == bigint("0"));
    CHECK(prod.second == bigint("297"));
}

TEST_CASE("bigint with very large values") {
    std::pair<bigint, bigint> f1 = {bigint("12345678901234567890"), bigint("2")};
    std::pair<bigint, bigint> f2 = {bigint("9876543210987654321"), bigint("5")};

    auto sum = addFractions(f1, f2);
    CHECK(sum.first == bigint("5") * bigint("12345678901234567890") + bigint("2") * bigint("9876543210987654321"));
    CHECK(sum.second == bigint("10"));

    auto prod = multiplyFractions(f1, f2);
    CHECK(prod.first == bigint("12345678901234567890") * bigint("9876543210987654321"));
    CHECK(prod.second == bigint("10"));
}


TEST_CASE("Addition of simple fractions") {
    auto f1 = std::make_pair(bigint("1"), bigint("2"));
    auto f2 = std::make_pair(bigint("1"), bigint("3"));
    auto result = addFractions(f1, f2); 

    CHECK(result.first == bigint("5"));
    CHECK(result.second == bigint("6"));
}

TEST_CASE("Multiplication of simple fractions") {
    auto f1 = std::make_pair(bigint("2"), bigint("3"));
    auto f2 = std::make_pair(bigint("3"), bigint("4"));
    auto result = multiplyFractions(f1, f2); 

    CHECK(result.first == bigint("6"));
    CHECK(result.second == bigint("12"));
}

TEST_CASE("Addition with large values") {
    auto f1 = std::make_pair(bigint("12345678901234567890"), bigint("2"));
    auto f2 = std::make_pair(bigint("9876543210987654321"), bigint("5"));
    auto sum = addFractions(f1, f2);

    CHECK(sum.first == bigint("5") * f1.first + bigint("2") * f2.first);
    CHECK(sum.second == bigint("10"));
}

TEST_CASE("Multiplication with large values") {
    auto f1 = std::make_pair(bigint("12345678901234567890"), bigint("2"));
    auto f2 = std::make_pair(bigint("9876543210987654321"), bigint("5"));
    auto prod = multiplyFractions(f1, f2);

    CHECK(prod.first == f1.first * f2.first);
    CHECK(prod.second == f1.second * f2.second);
}

TEST_CASE("Fractions with negative numbers") {
    auto f1 = std::make_pair(bigint("-3"), bigint("4"));
    auto f2 = std::make_pair(bigint("5"), bigint("6"));
    auto result = addFractions(f1, f2); 

    CHECK(result.first == bigint("-3") * bigint("6") + bigint("5") * bigint("4"));
    CHECK(result.second == bigint("24"));
}
