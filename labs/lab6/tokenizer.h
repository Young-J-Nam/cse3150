#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <istream>

struct Fragment {
    std::string type;
    std::string text;
};

class TokenProcessor {
public:
    void process(std::istream &input);
    Fragment retrieve(int index) const;
    int count() const;

private:
    std::vector<Fragment> records;
};

#endif
