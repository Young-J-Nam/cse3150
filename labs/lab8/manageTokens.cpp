#include "manageTokens.h"

void manageTokens::mintToken(std::vector<std::unique_ptr<nfToken>>& vault, const std::string& label) {
    vault.push_back(std::make_unique<nfToken>(label));
}

void manageTokens::walletTransfer(std::vector<std::unique_ptr<nfToken>>& destination, 
                                  std::vector<std::unique_ptr<nfToken>>& source,
                                  std::vector<std::unique_ptr<nfToken>>::iterator location) {
    if (source.empty() || location == source.end()) return;
    destination.push_back(std::move(*location));
    source.erase(location);
}