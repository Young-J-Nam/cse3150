#include "linkedList.h"
#include <iostream>
#include <string>

int main() {
    linkedList container;
    std::string input;

    while (true) {
        std::cout << "\n--- Linked List Menu ---\n";
        std::cout << "1. Insert at front\n";
        std::cout << "2. Insert at back\n";
        std::cout << "3. Remove first\n";
        std::cout << "4. Clear all\n";
        std::cout << "5. Display list\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose option (1-6): ";
        std::getline(std::cin, input);

        if (input == "1") {
            std::string value;
            std::cout << "Enter value to insert at front: ";
            std::getline(std::cin, value);
            container.insertAtFront(std::stoi(value));
        } else if (input == "2") {
            std::string value;
            std::cout << "Enter value to insert at back: ";
            std::getline(std::cin, value);
            container.insertAtBack(std::stoi(value));
        } else if (input == "3") {
            container.removeFirst();
            std::cout << "First element removed.\n";
        } else if (input == "4") {
            container.clearAll();
            std::cout << "List cleared.\n";
        } else if (input == "5") {
            std::cout << "Current list: ";
            container.display();
        } else if (input == "6") {
            std::cout << "Exiting.\n";
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}