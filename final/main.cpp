#include "timedSharedPtr.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

int main() {
    timedSharedPtr<int> userPtr;
    std::string command;

    while (true) {
        std::cout << "\n--- TimedSharedPtr Menu ---\n";
        std::cout << "1. Create new timedSharedPtr\n";
        std::cout << "2. Copy construct a new pointer\n";
        std::cout << "3. Move construct a new pointer\n";
        std::cout << "4. Check get()\n";
        std::cout << "5. Check use_count()\n";
        std::cout << "6. Sleep milliseconds\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose option: ";
        std::getline(std::cin, command);

        if (command == "1") {
            std::string value, ms;
            std::cout << "Enter integer value: ";
            std::getline(std::cin, value);
            std::cout << "Enter duration in ms: ";
            std::getline(std::cin, ms);
            userPtr = timedSharedPtr<int>(new int(std::stoi(value)), std::stoi(ms));
            std::cout << "Created new timedSharedPtr<int>.\n";

        } else if (command == "2") {
            timedSharedPtr<int> copyPtr = userPtr;
            std::cout << "Copy constructed pointer. use_count: " << copyPtr.use_count() << "\n";

        } else if (command == "3") {
            timedSharedPtr<int> movedPtr = std::move(userPtr);
            std::cout << "Move constructed pointer.\n";
            std::cout << "Original pointer use_count: " << userPtr.use_count() << "\n";
            std::cout << "Moved pointer use_count: " << movedPtr.use_count() << "\n";

        } else if (command == "4") {
            auto p = userPtr.get();
            if (p) {
                std::cout << "Pointer value: " << *p << "\n";
            } else {
                std::cout << "Pointer has expired or is null.\n";
            }

        } else if (command == "5") {
            std::cout << "Current use_count: " << userPtr.use_count() << "\n";

        } else if (command == "6") {
            std::string ms;
            std::cout << "Enter milliseconds to sleep: ";
            std::getline(std::cin, ms);
            std::this_thread::sleep_for(std::chrono::milliseconds(std::stoi(ms)));
            std::cout << "Slept for " << ms << " ms.\n";

        } else if (command == "7") {
            std::cout << "Exiting.\n";
            break;

        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}