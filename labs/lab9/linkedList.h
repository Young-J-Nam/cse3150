#pragma once

class linkedList {
private:
    struct node {
        int value;
        node* next;
    };

    node* head;

public:
    linkedList();
    ~linkedList();

    void insertAtFront(int number);
    void insertAtBack(int number);
    void removeFirst();
    void clearAll();
    void display() const;
};