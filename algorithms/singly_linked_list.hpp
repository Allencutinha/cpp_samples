#pragma once

#include <cstddef>

template <typename T>
class SinglyLinkedList {
 public:
  SinglyLinkedList() : head_(NULL), tail_(NULL), size_(0) {}

  // Check if the list is empty
  bool empty() const { return size_ == 0; }

  // Get the number of elements in the list
  std::size_t size() const { return size_; }

  // Get the element at the front of the list
  const T& front() const { return head_->data; }

  // Get the element at the back of the list
  const T& back() const { return tail_->data; }

  // Insert an element at the front of the list
  void insert_front(const T& data) {
    Node* node = new Node(data, head_);
    if (head_ == NULL) {
      head_ = node;
      tail_ = node;
    } else {
      head_ = node;
    }
    ++size_;
  }

  // Insert an element at the back of the list
  void insert_back(const T& data) {
    Node* node = new Node(data);
    if (tail_ == NULL) {
      head_ = node;
      tail_ = node;
    } else {
      tail_->next = node;
      tail_ = node;
    }
    ++size_;
  }

  // Remove the element at the front of the list
  void remove_front() {
    if (head_ == NULL) return;
    Node* temp = head_;
    head_ = head_->next;
    delete temp;
    --size_;
    if (head_ == NULL) tail_ = NULL;
  }

  // Remove the element at the back of the list
  void remove_back() {
    if (tail_ == NULL) return;
    if (head_ == tail_) {
      delete head_;
      head_ = NULL;
      tail_ = NULL;
      return;
    }
    Node* temp = head_;
    while (temp->next != tail_) temp = temp->next;
    delete tail_;
    tail_ = temp;
    tail_->next = NULL;
    --size_;
  }

  // Search for an element in the list
  bool search(const T& data) const {
    Node* temp = head_;
    while (temp != NULL) {
      if (temp->data == data) return true;
      temp = temp->next;
    }
    return false;
  }

  // Clear the list
  void clear() {
    Node* temp = head_;
    while (temp != NULL) {
      Node* next = temp->next;
      delete temp;
      temp = next;
    }
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
  }

 private:
  // Node for the singly linked list
struct Node {
  T data;
  Node* next;
  Node(const T& data) : data(data), next(NULL) {}
  Node(const T& data, Node* next) : data(data), next(next) {}
};

  Node * tail_;
  Node * head_;
  int size_ ;
};
