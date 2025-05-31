#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tokenizer.h"
#include <sstream>

TEST_CASE("Processor Basic Functionality") {
    std::string content = "dog 123 !\ncat 789 .";
    std::istringstream input(content);
    TokenProcessor p;
    p.process(input);

    CHECK(p.count() == 6);

    CHECK(p.retrieve(0).type == "WORD");
    CHECK(p.retrieve(0).text == "dog");

    CHECK(p.retrieve(1).type == "NUMBER");
    CHECK(p.retrieve(1).text == "123");

    CHECK(p.retrieve(2).type == "PUNCT");
    CHECK(p.retrieve(2).text == "!");

    CHECK(p.retrieve(3).type == "WORD");
    CHECK(p.retrieve(3).text == "cat");

    CHECK(p.retrieve(4).type == "NUMBER");
    CHECK(p.retrieve(4).text == "789");

    CHECK(p.retrieve(5).type == "PUNCT");
    CHECK(p.retrieve(5).text == ".");
}
