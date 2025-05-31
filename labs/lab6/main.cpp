#include "tokenizer.h"
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::cout << "Enter text to tokenize (Ctrl+D or Ctrl+Z to finish):\n";

    TokenProcessor processor;
    while (std::getline(std::cin, line)) {
        std::istringstream input_stream(line);
        processor.process(input_stream);
    }

    std::cout << "\nProcessed Tokens:\n";
    for (int i = 0; i < processor.count(); ++i) {
        Fragment token = processor.retrieve(i);
        std::cout << "[" << token.type << "] " << token.text << "\n";
    }

    return 0;
}
