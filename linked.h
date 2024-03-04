#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    int data;
    Node* nextPtr;
};

class Linked {
private:
    Node* headPtr;
    Node* tailPtr;

public:
    Linked();
    ~Linked();

    void add_front(int d);
    void add_back(int d);
    void del_front();
    void del_back();
    Node* Lfront();
    Node* Lback();
    bool empty() const;
    void insert(size_t index, int item);
    bool remove(size_t index);
    size_t find(int item);
    void printNode(size_t index);

    // Helper method to print the list
    void printList() const;

    size_t num_items;
};