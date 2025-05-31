#ifndef NFTOKEN_H
#define NFTOKEN_H

#include <string>

class nfToken {
private:
    std::string label;
    std::string fingerprint;

public:
    nfToken(const std::string& inputName);
    std::string getName() const;
    std::string getHash() const;
};

#endif