// Cesar Cardenas - A00844803
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <utility>
#include "Node.h"

// Lista simplemente ligada. Indices desde 0; cada lista es duena de sus nodos.
template <typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    int size = 0;

    Node<T>* nodeAt(int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("La posicion no existe en la lista");
        Node<T>* node = head;
        for (int i = 0; i < index; ++i) node = node->next;
        return node;
    }

    const Node<T>* nodeAt(int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("La posicion no existe en la lista");
        const Node<T>* node = head;
        for (int i = 0; i < index; ++i) node = node->next;
        return node;
    }

public:
    LinkedList() = default;
    ~LinkedList() { clear(); }

    // Copia profunda: una lista temporal evita fugas si copiar T falla.
    LinkedList(const LinkedList& other) {
        LinkedList copy;
        Node<T>** link = &copy.head;
        for (const Node<T>* node = other.head; node; node = node->next) {
            *link = new Node<T>(node->data);
            link = &((*link)->next);
            ++copy.size;
        }
        swap(copy);
    }

    LinkedList(LinkedList&& other) noexcept { swap(other); }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            LinkedList copy(other);
            swap(copy);
        }
        return *this;
    }

    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            swap(other);
        }
        return *this;
    }

    void swap(LinkedList& other) noexcept {
        std::swap(head, other.head);
        std::swap(size, other.size);
    }

    void clear() noexcept {
        while (head) {
            Node<T>* old = head;
            head = head->next;
            delete old;
        }
        size = 0;
    }

    int getSize() const noexcept { return size; }
    bool empty() const noexcept { return size == 0; }

    // O(1)
    void addFirst(const T& data) {
        head = new Node<T>(data, head);
        ++size;
    }

    // O(n)
    void addLast(const T& data) {
        Node<T>** link = &head;
        while (*link) link = &((*link)->next);
        *link = new Node<T>(data);
        ++size;
    }

    // Inserta DESPUES de un indice existente (enunciado del menu). O(n).
    void insert(int index, const T& data) {
        Node<T>* previous = nodeAt(index);
        previous->next = new Node<T>(data, previous->next);
        ++size;
    }

    // Borra solo la primera coincidencia. O(n).
    bool deleteData(const T& data) {
        Node<T>** link = &head;
        while (*link && !((*link)->data == data)) link = &((*link)->next);
        if (!*link) return false;
        Node<T>* old = *link;
        *link = old->next;
        delete old;
        --size;
        return true;
    }

    // Indice invalido: false; conserva la lista. O(n).
    bool deleteAt(int index) {
        if (index < 0 || index >= size) return false;
        Node<T>** link = &head;
        for (int i = 0; i < index; ++i) link = &((*link)->next);
        Node<T>* old = *link;
        *link = old->next;
        delete old;
        --size;
        return true;
    }

    T getData(int index) const { return nodeAt(index)->data; }

    // Actualiza solo la primera coincidencia. O(n).
    void updateData(const T& oldData, const T& newData) {
        Node<T>* node = head;
        while (node && !(node->data == oldData)) node = node->next;
        if (!node) throw std::out_of_range("No se encontro el dato a actualizar");
        node->data = newData;
    }

    void updateAt(int index, const T& data) { nodeAt(index)->data = data; }

    int findData(const T& data) const {
        int index = 0;
        for (const Node<T>* node = head; node; node = node->next, ++index)
            if (node->data == data) return index;
        return -1;
    }

    T& operator[](int index) { return nodeAt(index)->data; }
    const T& operator[](int index) const { return nodeAt(index)->data; }

    // Compatibilidad con los ejemplos originales.
    void push_front(const T& data) { addFirst(data); }
    void push_back(const T& data) { addLast(data); }

    void print(std::ostream& out = std::cout) const {
        out << '[';
        for (const Node<T>* node = head; node; node = node->next) {
            out << node->data;
            if (node->next) out << ", ";
        }
        out << "]\n";
    }
};

#endif
