#include "timedSharedPtr.h"
#include <iostream>
#include <thread>
#include <chrono>

struct Node {
    int data;
    Node(int d) : data(d) {}
};

int main() {
    timedSharedPtr<Node> myNode(new Node(7), 100);
    timedSharedPtr<Node> myOtherNode = myNode;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "myNode.get(): " << myNode.get() << "\n";
    std::cout << "myNode.use_count(): " << myNode.use_count() << "\n";
    std::cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << "\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    std::cout << "myNode.get(): " << myNode.get() << "\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    std::cout << "Pointer should be expired now:\n";
    std::cout << "myNode.get(): " << myNode.get() << "\n";

    std::cout << "-------------\n";

    timedSharedPtr<int> p(new int(42));
    std::cout << p.get() << "\n";
    std::cout << "p.use_count(): " << p.use_count() << "\n";
    timedSharedPtr<int> q = p;
    std::cout << "p.use_count(): " << p.use_count() << "\n";
    std::cout << "q.use_count(): " << q.use_count() << "\n";

    return 0;
}