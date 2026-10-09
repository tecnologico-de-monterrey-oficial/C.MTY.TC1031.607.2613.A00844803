// Cesar Cardenas - A00844803
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include "NodeD.h"

template <typename T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;

    // Busca el nodo de una posicion.
    NodeD<T>* getNode(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Indice invalido");
        }

        NodeD<T>* aux = head;

        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }

        return aux;
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addFirst(T data) {
        NodeD<T>* node = new NodeD<T>(data);
        node->next = head;

        if (head == nullptr) {
            tail = node;
        } else {
            head->prev = node;
        }

        head = node;
        size++;
    }

    void addLast(T data) {
        NodeD<T>* node = new NodeD<T>(data);
        node->prev = tail;

        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }

        tail = node;
        size++;
    }

    // Inserta a la derecha del indice.
    void insert(int index, T data) {
        NodeD<T>* aux = getNode(index);

        if (aux == tail) {
            addLast(data);
        } else {
            NodeD<T>* node = new NodeD<T>(data);

            node->prev = aux;
            node->next = aux->next;
            aux->next->prev = node;
            aux->next = node;

            size++;
        }
    }

    void clear() {
        while (head != nullptr) {
            NodeD<T>* aux = head;
            head = head->next;
            delete aux;
        }

        tail = nullptr;
        size = 0;
    }

    void print() {
        NodeD<T>* aux = head;
        std::cout << "[";

        while (aux != nullptr) {
            std::cout << aux->data;

            if (aux->next != nullptr) {
                std::cout << ", ";
            }

            aux = aux->next;
        }

        std::cout << "]" << std::endl;
    }

    ~DoublyLinkedList() {
        clear();
    }
};

#endif