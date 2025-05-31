#include "tokenizer.h"
#include <cctype>

void TokenProcessor::process(std::istream &input) {
    char symbol;
    std::string fragment;

    while (input.get(symbol)) {
        if (std::isalpha(symbol)) {
            fragment.clear();
            fragment += symbol;
            while (input.get(symbol) && std::isalpha(symbol)) {
                fragment += symbol;
            }
            if (input) input.unget();
            records.push_back({"WORD", fragment});
        } else if (std::isdigit(symbol)) {
            fragment.clear();
            fragment += symbol;
            while (input.get(symbol) && std::isdigit(symbol)) {
                fragment += symbol;
            }
            if (input) input.unget();
            records.push_back({"NUMBER", fragment});
        } else if (!std::isspace(symbol)) {
            fragment = symbol;
            records.push_back({"PUNCT", fragment});
        }
    }
}

Fragment TokenProcessor::retrieve(int index) const {
    return records.at(index);
}

int TokenProcessor::count() const {
    return static_cast<int>(records.size());
}
