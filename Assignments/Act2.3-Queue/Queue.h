// Cesar Cardenas - A00844803
#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>

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
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

        void push(T data) {
        Node<T>* node = new Node<T>(data);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        size++;
    }

    int getSize() {
        return size;
    }

        // Consulta el primer dato sin eliminarlo.
    T front() {
        if (head == nullptr) {
            throw std::out_of_range("La fila esta vacia");
        }

        return head->data;
    }

    // Elimina el primer dato y devuelve su valor.
    T pop() {
        if (head == nullptr) {
            throw std::out_of_range("La fila esta vacia");
        }

        T data = head->data;
        Node<T>* aux = head;

        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete aux;
        size--;

        return data;
    }

    // Libera los nodos al terminar de usar la fila.
    ~Queue() {
        while (head != nullptr) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }
};

#endif