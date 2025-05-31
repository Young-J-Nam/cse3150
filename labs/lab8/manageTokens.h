#pragma once
#include <vector>
#include <memory>
#include "nfToken.h"

class manageTokens {
public:
    static void mintToken(std::vector<std::unique_ptr<nfToken>>& vault, const std::string& label);
    static void walletTransfer(std::vector<std::unique_ptr<nfToken>>& destination,
                               std::vector<std::unique_ptr<nfToken>>& source,
                               std::vector<std::unique_ptr<nfToken>>::iterator location);
};