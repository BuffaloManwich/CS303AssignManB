#include "linked.h"

Linked::Linked() : headPtr(nullptr), tailPtr(nullptr), num_items(0) {}

Linked::~Linked() {
    cout << "Destructor called\n";
    //Destructor will loop through the list and delete each node
    Node* tempPtr = headPtr;
    Node* delPtr = tempPtr;
    while (tempPtr != nullptr) {
        tempPtr = tempPtr->nextPtr;
        delete delPtr;
        delPtr = tempPtr;
        num_items--;
    }
    cout << "List is now deleted" << endl << endl;
    headPtr = nullptr;
    tailPtr = nullptr;
}

void Linked::add_front(int d) {
    Node* newNode = new Node{ d, headPtr };
    headPtr = newNode;
    if (num_items == 0) {
        tailPtr = newNode;
    }
    num_items++;
    cout << "Added " << d << " to the front of the list" << endl << endl;
}

void Linked::del_front() {
    if (headPtr == nullptr) {
        cout << "List is empty" << endl;
        return; // List is empty
    }
    Node* tempPtr = headPtr;
    cout << "Deleting value " << tempPtr->data << " from index 0." << endl;
    headPtr = headPtr->nextPtr;
    delete tempPtr;
    if (num_items == 1) {
        tailPtr = nullptr; // List became empty
        cout << "List is now empty" << endl;
    }
    num_items--;
}

Node* Linked::Lfront() {
    if (headPtr == nullptr) {
        cout << "List is empty" << endl;
        return nullptr;
    }
    return headPtr;
}

void Linked::printList() const {
    //start at the headPtr and loop - printing data from each node
    //condition: if headPtr is null, print "List is empty"
    if (headPtr == nullptr) {
        cout << "The list is empty\n";
    }
    else {
        Node* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            cout << tempPtr->data << " ";
            tempPtr = tempPtr->nextPtr;
        }
        cout << endl;
    }
}

bool Linked::remove(size_t index) {
    // Check if the index is out of bounds or if list is empty, should not happen due to input verification
    if (index >= num_items || index < 0 || headPtr == nullptr) {
        if (index < 0 || index >= num_items) {
            cout << "Invalid index" << endl;
        }
        else {
            cout << "List is empty" << endl;
        }
        return false;
    }

    Node* tempPtr = headPtr;
    Node* delPtr = nullptr;

    // Special case: removing the first node
    if (index == 0) {
        headPtr = headPtr->nextPtr;
        cout << "Deleting value " << tempPtr->data << " at index " << index << "." << endl;
        delete tempPtr;
        if (num_items == 1) { // If there was only one item
            tailPtr = nullptr;
            cout << "List is now empty" << endl;
        }
        num_items--;
    }
    else {
        // Iterate through the list to find the node just before the one we want to remove
        for (size_t i = 0; tempPtr != nullptr && i < index - 1; i++) {
            tempPtr = tempPtr->nextPtr;
        }
        
        // Now, tempPtr is pointing to the node just before the one to delete
        if (tempPtr == nullptr || tempPtr->nextPtr == nullptr) {
            // This should not happen, but it's good to check
            return false;
        }

        // tempPtr->nextPtr is the node to delete
        delPtr = tempPtr->nextPtr; // delPtr is pointing at the node to delete
        tempPtr->nextPtr = delPtr->nextPtr;  // tempPtr nextPtr is set to node after node-to-delete

        // If we are deleting the last node, update the tailPtr
        if (delPtr == tailPtr) {
            tailPtr = tempPtr;
        }
    }
    if (delPtr != nullptr){ 
        cout << "Removing " << delPtr->data << " from the list at index " << index << "." << endl << endl; 
    }
    
    delete delPtr;
    delPtr = nullptr;
    num_items--;
    return true;
}

void Linked::add_back(int d) {
    Node* newNode = new Node{ d, nullptr };
    if (num_items == 0) {
        headPtr = newNode;
        tailPtr = newNode;
    }
    else {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
    num_items++;
    cout << "Added " << d << " to the back of the list." << endl << endl;
}

void Linked::del_back() {
    if (headPtr == nullptr) {
        cout << "List is empty" << endl << endl;
        return;
    }

    if (headPtr == tailPtr) {
        delete headPtr;
        headPtr = nullptr;
        tailPtr = nullptr;
        cout << "List is now empty" << endl << endl;
    }
    else {
        Node* tempPtr = headPtr;
        while (tempPtr->nextPtr != tailPtr) {
            tempPtr = tempPtr->nextPtr;
        }
        cout << "Deleting value " << tempPtr->data << " at index " << num_items - 1 << "." << endl;

        delete tailPtr;
        tailPtr = tempPtr;
        tailPtr->nextPtr = nullptr;
        cout << "Removed the last element from the list." << endl;
    }
    num_items--;
}

Node* Linked::Lback() {
    if (tailPtr == nullptr) {
        cout << "List is empty" << endl << endl;
        return nullptr;
    }
    return tailPtr;
}

bool Linked::empty() const {
    return num_items == 0;
}

void Linked::insert(size_t index, int item) {
    if (index > num_items) {
        cout << "Index out of bounds. Adding to the back of the list." << endl;
        add_back(item);
        return;
    }

    if (index == 0) {
        add_front(item);
        return;
    }

    Node* newNode = new Node{ item, nullptr };
    Node* tempPtr = headPtr;
    // iterate through list until tempPtr is pointing at the node before the index
    for (size_t i = 0; i < index - 1; ++i) {
        tempPtr = tempPtr->nextPtr;
    }

    newNode->nextPtr = tempPtr->nextPtr;
    tempPtr->nextPtr = newNode;

    if (newNode->nextPtr == nullptr) {
        tailPtr = newNode;
    }

    num_items++;
    cout << "Inserted " << item << " at index " << index << "." << endl << endl;
}

size_t Linked::find(int item) {
    Node* tempPtr = headPtr;
    size_t index = 0;

    while (tempPtr != nullptr) {
        if (tempPtr->data == item) {
            cout << "Item " << item << " found at index " << index << "." << endl << endl;
            return index;
        }
        tempPtr = tempPtr->nextPtr;
        index++;
    }

    cout << "Item " << item << " not found in the list." << endl << endl;
    return num_items;
}

void Linked::printNode(size_t index) {
    if (index >= num_items || index < 0 || headPtr == nullptr) {
        if (index < 0 || index >= num_items) {
            cout << "Invalid index" << endl << endl;
        }
        else {
            cout << "List is empty" << endl << endl;
        }
    }
    else {
        Node* tempPtr = headPtr;
        for (size_t i = 0; i < index; ++i) {
            tempPtr = tempPtr->nextPtr;
        }
        cout << "Node at index " << index << ": " << tempPtr->data << endl << endl;
    }
}