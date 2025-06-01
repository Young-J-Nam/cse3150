#include <iostream>
#include <chrono>
#include "bigint.h"

using namespace std;
using namespace chrono;

long long timeBigintMultiply(int iters) {
    bigint a("9999999999999999999");
    bigint b("1234567890101112131");
    bigint c;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iters; ++i) c = a * b;
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

int main() {
    int iters;
    std::cout << "Enter number of iterations for bigint multiplication: ";
    std::cin >> iters;

    auto time = timeBigintMultiply(iters);
    std::cout << "Time for " << iters << " bigint multiplications: " << time << " microseconds.\n";
    return 0;
}
