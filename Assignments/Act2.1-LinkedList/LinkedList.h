// Cesar Cardenas A00844803
#ifndef LinkedList_h
#define LinkedList_h

#include "node.h"
#include <iostream>
#include <memory>

template <typename T>
class LinkedList {
private:
    std::unique_ptr<Node<T>> head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void push_front(T data);
    void push_back(T data);
    void print();
};

template <typename T>
void LinkedList<T>::push_front(T data) {
    auto node = std::make_unique<Node<T>>(data);
    node->next = std::move(head);
    head = std::move(node);
    ++size;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
    if (!head) {
        push_front(data);
        return;
    }

    auto node = std::make_unique<Node<T>>(data);
    Node<T>* current = head.get();

    while (current->next != nullptr) {
        current = current->next.get();
    }

    current->next = std::move(node);
    ++size;
}

template <typename T>
void LinkedList<T>::print() {
    Node<T>* current = head.get();
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next.get();
    }
    std::cout << std::endl;
}

#endif /* LinkedList_h */