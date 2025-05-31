#include <iostream>
#include <iomanip>
#include <chrono>
#include "bigint.h"

using namespace std;
using namespace chrono;

long long timeIntMultiply(int iters) {
    int a = 1, b = 2, c;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iters; ++i) c = a * b;
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long timeLongMultiply(int iters) {
    long a = 1L, b = 2L, c;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iters; ++i) c = a * b;
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

long long timeBigintMultiply(int iters) {
    bigint a("9999999999999999999");
    bigint b("1234567890101112131");
    bigint c;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iters; ++i) c = a * b;
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

void demonstrateIntOverflow() {
    cout << "\n--- Overflow Demonstration ---" << endl;
    int a = 1234567890;
    int b = 987654321;
    int result = a * b;  // This overflows and produces incorrect value
    cout << "int a = 1234567890;\nint b = 987654321;\na * b = " << result << " (overflowed)" << endl;

    bigint bigA("1234567890");
    bigint bigB("987654321");
    bigint bigResult = bigA * bigB;
    cout << "bigint a = 1234567890;\nbigint b = 987654321;\na * b = " << bigResult << " (correct)" << endl;
}

int main() {
    vector<int> iterationCounts = {10, 100, 1000, 10000, 100000};

    cout << "All times below are in microseconds" << endl;
    cout << left << setw(12) << "iterations"
         << setw(36) << "pair<int,int> * pair<int,int>"
         << setw(36) << "pair<long,long> * pair<long,long>"
         << setw(40) << "pair<bigint , bigint> * pair<bigint , bigint>" << "\n";

    for (int n : iterationCounts) {
        long long intTime = timeIntMultiply(n);
        long long longTime = timeLongMultiply(n);
        long long bigintTime = timeBigintMultiply(n);

        cout << left << setw(12) << n
             << setw(36) << intTime
             << setw(36) << longTime
             << setw(40) << bigintTime << "\n";
    }

    demonstrateIntOverflow();
    return 0;
}