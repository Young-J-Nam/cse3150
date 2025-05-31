#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "manageTokens.h"

TEST_CASE("Token Creation Check") {
    std::vector<std::unique_ptr<nfToken>> collection;

    manageTokens::mintToken(collection, "PieceA");
    CHECK(collection.size() == 1);
    CHECK(collection[0]->getName() == "PieceA");

    manageTokens::mintToken(collection, "");
    CHECK(collection.size() == 2);
    CHECK(collection[1]->getName() == "");
}

TEST_CASE("Token Properties - Repeats and Size") {
    std::vector<std::unique_ptr<nfToken>> group;

    manageTokens::mintToken(group, "Repeated");
    manageTokens::mintToken(group, "Repeated");
    CHECK(group.size() == 2);
    CHECK(group[0]->getHash() == group[1]->getHash());

    std::string oversized(5000, 'Z');
    manageTokens::mintToken(group, oversized);
    CHECK(group.size() == 3);
    CHECK(group[2]->getName() == oversized);
}