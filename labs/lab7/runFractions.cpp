#include <iostream>
#include "bigint.h"
#include "fractions.h"

int main() {
    std::string a1, b1, a2, b2;
    std::cout << "Enter numerator and denominator for first fraction: ";
    std::cin >> a1 >> b1;
    std::cout << "Enter numerator and denominator for second fraction: ";
    std::cin >> a2 >> b2;

    std::pair<bigint, bigint> f1 = {bigint(a1), bigint(b1)};
    std::pair<bigint, bigint> f2 = {bigint(a2), bigint(b2)};

    try {
        auto sum = addFractions(f1, f2);
        auto product = multiplyFractions(f1, f2);

        std::cout << "Sum: " << sum.first << " / " << sum.second << "\n";
        std::cout << "Product: " << product.first << " / " << product.second << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}