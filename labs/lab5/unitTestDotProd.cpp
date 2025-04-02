#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "dot_prod_fun.h"

using namespace std;

TEST_CASE("test dot product") {
  
    dot_product ;

    ll_start.insertAtBeginning(5);
    ll_end.insertAtEnd(-55);

    CHECK( 0 == ll_0.getSize() );
    CHECK( 1 == ll_start.getSize() );
    CHECK( 1 == ll_end.getSize() );
               
  };

TEST_CASE("Insertion at Various Positions") {
    LinkedList l1;
    l1.insertAtBeginning(10);
    l1.insertAtEnd(20);
    l1.insertAtBeginning(5);
    CHECK(l1.getValueAt(1) == 5);
    CHECK(l1.getValueAt(2) == 10);
    CHECK(l1.getValueAt(3) == 20);
}

TEST_CASE("Deletion from Different Positions") {
    LinkedList l1;
    l1.insertAtBeginning(10);
    l1.insertAtEnd(20);
    l1.insertAtBeginning(5);
    l1.deleteNodeNumber(2);
    CHECK(l1.getValueAt(1) == 5);
    CHECK(l1.getValueAt(2) == 10);
}

TEST_CASE("Edge Case Insertions") {
    LinkedList l1;
    l1.insertAtBeginning(1);
    l1.insertAtBeginning(2);
    l1.insertAtBeginning(3);
    CHECK(l1.getValueAt(1) == 3);
    l1.insertAtEnd(4);
    CHECK(l1.getValueAt(4) == 4);
}

TEST_CASE("Testing Copy Constructor") {
    LinkedList l1;
    l1.insertAtBeginning(5);
    l1.insertAtBeginning(10);
    LinkedList l2 = l1;
    CHECK(l2.getValueAt(1) == 10);
    CHECK(l2.getValueAt(2) == 5);
}

TEST_CASE("Testing Move Constructor") {
    LinkedList l1;
    l1.insertAtBeginning(1);
    l1.insertAtBeginning(2);
    LinkedList l2 = move(l1);
    CHECK(l1.getSize() == 0);
    CHECK(l2.getValueAt(1) == 2);
}

TEST_CASE("Testing Move Assignment Operator") {
    LinkedList l1, l2;
    l1.insertAtBeginning(1);
    l1.insertAtBeginning(2);
    l2 = move(l1);
    CHECK(l1.getSize() == 0);
    CHECK(l2.getValueAt(1) == 2);
}

TEST_CASE("Testing Deleting First Node") {
    LinkedList l1;
    l1.insertAtBeginning(3);
    l1.insertAtBeginning(2);
    l1.insertAtBeginning(1);
    l1.deleteNodeNumber(1);
    CHECK(l1.getValueAt(1) == 1);
}

TEST_CASE("Testing Get Last Element") {
    LinkedList l1;
    l1.insertAtBeginning(3);
    l1.insertAtEnd(4);
    Node* p = l1.getLastElement();
    CHECK(p->data == 4);
}

TEST_CASE("Testing Single Element List") {
    LinkedList l1;
    l1.insertAtBeginning(10);
    CHECK(l1.getSize() == 1);
    CHECK(l1.getValueAt(1) == 10);
}

TEST_CASE("Testing Multiple Deletions") {
    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.deleteNodeNumber(1);
    CHECK(l1.getValueAt(1) == 1);
    l1.deleteNodeNumber(1);
    CHECK(l1.getValueAt(1) == 1);
}

TEST_CASE("Testing Alternating Insertions and Deletions") {
    LinkedList l1;
    l1.insertAtBeginning(5);
    l1.insertAtBeginning(10);
    l1.deleteNodeNumber(2);
    CHECK(l1.getSize() == 1);
    CHECK(l1.getValueAt(1) == 10);
}



TEST_CASE("Testing Edge Case of PointerJumper") {
    LinkedList l1;
    l1.insertAtBeginning(3);
    l1.insertAtBeginning(2);
    l1.insertAtBeginning(1);
    l1.PointerJumper();
    CHECK(l1.getLastElement()->data == 3);
}

TEST_CASE("Testing Last Element Edge Cases") {
    LinkedList l1;
    l1.insertAtBeginning(1);
    l1.insertAtBeginning(2);
    CHECK(l1.getLastElement()->data == 1);
}
