// Cesar Cardenas - A00844803
#ifndef STACK_H
#define STACK_H
#include <stdexcept>

using namespace std;

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

        void push(T data) {
        Node<T>* node = new Node<T>(data);

        node->next = head;
        head = node;
        size++;
    }

    T pop() {
        if (head == nullptr) {
            throw out_of_range("La pila esta vacia");
        }

        T data = head->data;
        Node<T>* aux = head;

        head = head->next;
        delete aux;
        size--;

        return data;
    }

    T top() {
        if (head == nullptr) {
            throw out_of_range("La pila esta vacia");
        }

        return head->data;
    }

    int getSize() {
        return size;
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