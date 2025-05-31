#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "nfToken.h"
#include "manageTokens.h"

void showVault(const std::vector<std::unique_ptr<nfToken>>& vault, const std::string& label) {
    std::cout << "\n" << label << " contents:\n";
    for (size_t i = 0; i < vault.size(); ++i) {
        std::cout << "[" << i << "] " << vault[i]->getName() << " | Hash: " << vault[i]->getHash().substr(0, 10) << "...\n";
    }
    if (vault.empty()) std::cout << "(empty)\n";
}

int main() {
    std::vector<std::unique_ptr<nfToken>> vaultA;
    std::vector<std::unique_ptr<nfToken>> vaultB;

    std::string command;
    while (true) {
        std::cout << "\n--- NFT Vault Menu ---\n";
        std::cout << "1. Mint token into Vault A or B\n";
        std::cout << "2. Transfer a token between Vaults\n";
        std::cout << "3. Show both vaults\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter command (1-4): ";
        std::getline(std::cin, command);

        if (command == "1") {
            std::string name;
            std::cout << "Enter token label: ";
            std::getline(std::cin, name);
            std::string target;
            std::cout << "Mint into Vault A or B? (A/B): ";
            std::getline(std::cin, target);
            if (target == "A" || target == "a") {
                manageTokens::mintToken(vaultA, name);
                std::cout << "Token '" << name << "' minted in Vault A.\n";
            } else if (target == "B" || target == "b") {
                manageTokens::mintToken(vaultB, name);
                std::cout << "Token '" << name << "' minted in Vault B.\n";
            } else {
                std::cout << "Invalid vault.\n";
            }

        } else if (command == "2") {
            std::cout << "Choose transfer direction:\n";
            std::cout << "1. Vault A → Vault B\n";
            std::cout << "2. Vault B → Vault A\n";
            std::cout << "Enter 1 or 2: ";
            std::string direction;
            std::getline(std::cin, direction);

            std::vector<std::unique_ptr<nfToken>>* source = nullptr;
            std::vector<std::unique_ptr<nfToken>>* destination = nullptr;

            if (direction == "1") {
                source = &vaultA;
                destination = &vaultB;
            } else if (direction == "2") {
                source = &vaultB;
                destination = &vaultA;
            } else {
                std::cout << "Invalid direction.\n";
                continue;
            }

            if (source->empty()) {
                std::cout << "Selected source vault is empty.\n";
            } else {
                showVault(*source, "Source Vault");
                std::cout << "Enter index of token to transfer: ";
                std::string indexStr;
                std::getline(std::cin, indexStr);

                try {
                    int index = std::stoi(indexStr);
                    if (index >= 0 && static_cast<size_t>(index) < source->size()) {
                        manageTokens::walletTransfer(*destination, *source, source->begin() + index);
                        std::cout << "Token transferred successfully.\n";
                    } else {
                        std::cout << "Invalid index.\n";
                    }
                } catch (...) {
                    std::cout << "Invalid input.\n";
                }
            }

        } else if (command == "3") {
            showVault(vaultA, "Vault A");
            showVault(vaultB, "Vault B");

        } else if (command == "4") {
            std::cout << "Exiting.\n";
            break;

        } else {
            std::cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}