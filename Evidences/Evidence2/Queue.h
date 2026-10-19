//Cesar Cardenas - A00844803
#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>

using namespace std;

template <typename T>
struct QueueNode {
    T data;
    QueueNode<T>* next;

    QueueNode(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Queue {
private:
    QueueNode<T>* head;
    QueueNode<T>* tail;
    int count;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

        void push(T data) {
        QueueNode<T>* node = new QueueNode<T>(data);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        count++;
    }

    int getSize() {
        return count;
    }

    int size() const { return count; }
    bool isEmpty() const { return head == nullptr; }
    void enqueue(T data) { push(data); }

        // Consulta el primer dato sin eliminarlo.
    T front() {
        if (head == nullptr) {
            throw out_of_range("La fila esta vacia");
        }

        return head->data;
    }

    // Elimina el primer dato y devuelve su valor.
    T pop() {
        if (head == nullptr) {
            throw out_of_range("La fila esta vacia");
        }

        T data = head->data;
        QueueNode<T>* aux = head;

        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete aux;
        count--;

        return data;
    }

    T dequeue() { return pop(); }

    // Libera los nodos al terminar de usar la fila.
    ~Queue() {
        while (head != nullptr) {
            QueueNode<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }
};

#endif
