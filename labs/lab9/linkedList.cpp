#include "linkedList.h"
#include <iostream>

linkedList::linkedList() : head(nullptr) {}

linkedList::~linkedList() {
    clearAll();
}

void linkedList::insertAtFront(int number) {
    node* n = new node{number, head};
    head = n;
}

void linkedList::insertAtBack(int number) {
    node* n = new node{number, nullptr};
    if (!head) {
        head = n;
    } else {
        node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = n;
    }
}

void linkedList::removeFirst() {
    if (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void linkedList::clearAll() {
    while (head) {
        removeFirst();
    }
}

void linkedList::display() const {
    node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}