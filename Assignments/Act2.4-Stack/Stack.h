// Cesar Cardenas - A00844803
#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T>* head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    ~Stack() {
        while (head != nullptr) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }
};

#endif