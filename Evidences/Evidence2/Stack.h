// Cesar Cardenas - A00844803
#ifndef STACK_H
#define STACK_H
#include <stdexcept>

using namespace std;

template <typename T>
struct StackNode {
    T data;
    StackNode<T>* next;

    StackNode(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    StackNode<T>* head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }

        void push(T data) {
        StackNode<T>* node = new StackNode<T>(data);

        node->next = head;
        head = node;
        size++;
    }

    T pop() {
        if (head == nullptr) {
            throw out_of_range("La pila esta vacia");
        }

        T data = head->data;
        StackNode<T>* aux = head;

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
            StackNode<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }
};

#endif