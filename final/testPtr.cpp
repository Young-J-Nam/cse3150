#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "timedSharedPtr.h"
#include <thread>
#include <chrono>

TEST_CASE("Basic usage and reference count") {
    timedSharedPtr<int> p(new int(99), 500);
    CHECK(p.get() != nullptr);
    CHECK(p.use_count() == 1);

    timedSharedPtr<int> q = p;
    CHECK(p.use_count() == 2);
    CHECK(q.use_count() == 2);
}

TEST_CASE("Expiration behavior") {
    timedSharedPtr<int> p(new int(123), 100);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    CHECK(p.get() == nullptr);
    CHECK(p.use_count() == 1);
}

TEST_CASE("Move semantics") {
    timedSharedPtr<int> p(new int(55), 100);
    timedSharedPtr<int> q = std::move(p);
    CHECK(q.get() != nullptr);
    CHECK(q.use_count() == 1);
    CHECK(p.get() == nullptr);
    CHECK(p.use_count() == 0);
}