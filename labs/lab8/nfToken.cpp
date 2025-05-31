#include "nfToken.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

nfToken::nfToken(const std::string& inputName) : label(inputName) {
    unsigned char result[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(inputName.c_str()), inputName.size(), result);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(result[i]);

    fingerprint = oss.str();
}

std::string nfToken::getName() const {
    return label;
}

std::string nfToken::getHash() const {
    return fingerprint;
}