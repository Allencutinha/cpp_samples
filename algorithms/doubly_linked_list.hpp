#pragma once
#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Insert a new node at the front of the list
    void pushFront(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    // Insert a new node at the back of the list
    void pushBack(int data)
    {
        Node* newNode = new Node(data);
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        size++;
    }

    // Remove the node at the front of the list
    void popFront()
    {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Remove the node at the back of the list
    void popBack()
    {
        if (tail == nullptr) {
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    // Print the contents of the list
    void printList()
    {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
namespace dll {
int test()
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(0);
    list.printList(); // Output: 0 1 2 3
    list.popFront();
    list.printList(); // Output: 1 2 3
    list.popBack();
    list.printList(); // Output: 1 2
    return 0;
}
} // namespace dll
