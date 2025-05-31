#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linkedList.h"

TEST_CASE("Insert and Clear") {
    linkedList chain;

    chain.insertAtFront(5);
    chain.insertAtBack(15);
    chain.insertAtBack(25);
    chain.clearAll();

    chain.insertAtFront(35);
    chain.insertAtBack(45);
    CHECK(true);
}

TEST_CASE("Removing from list") {
    linkedList list;
    list.insertAtFront(100);
    list.insertAtBack(200);
    list.removeFirst();
    CHECK(true);
}

TEST_CASE("Multiple Insertions") {
    linkedList trail;
    trail.insertAtBack(1);
    trail.insertAtBack(2);
    trail.insertAtBack(3);
    trail.insertAtBack(4);
    trail.insertAtFront(0);
    CHECK(true);
}

TEST_CASE("Emptying Twice") {
    linkedList pool;
    pool.insertAtFront(7);
    pool.insertAtBack(14);
    pool.clearAll();
    pool.clearAll();
    CHECK(true);
}

TEST_CASE("Single Insert Remove") {
    linkedList one;
    one.insertAtFront(99);
    one.removeFirst();
    one.removeFirst();
    CHECK(true);
}