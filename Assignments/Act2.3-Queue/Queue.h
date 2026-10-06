// Cesar Cardenas - A00844803
#ifndef QUEUE_H
#define QUEUE_H

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