//Cesar Cardenas - A00844803
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <utility>
#include "Node.h"

using namespace std;

// Lista simplemente ligada. Indices desde 0; cada lista es duena de sus nodos.
template <typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int count = 0;

    Node<T>* nodeAt(int index) {
        if (index < 0 || index >= count)
            throw out_of_range("La posicion no existe en la lista");
        Node<T>* node = head;
        for (int i = 0; i < index; ++i) node = node->next;
        return node;
    }

    const Node<T>* nodeAt(int index) const {
        if (index < 0 || index >= count)
            throw out_of_range("La posicion no existe en la lista");
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
        for (const Node<T>* node = other.head; node; node = node->next) {
            copy.addLast(node->data);
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
        swap(head, other.head);
        swap(tail, other.tail);
        swap(count, other.count);
    }

    void clear() noexcept {
        while (head) {
            Node<T>* old = head;
            head = head->next;
            delete old;
        }
        tail = nullptr;
        count = 0;
    }

    int getSize() const noexcept { return count; }
    int size() const noexcept { return count; }
    bool empty() const noexcept { return count == 0; }
    bool isEmpty() const noexcept { return empty(); }
    Node<T>* getHead() const noexcept { return head; }
    Node<T>* getTail() const noexcept { return tail; }

    // O(1)
    void addFirst(const T& data) {
        head = new Node<T>(data, head);
        if (!tail) tail = head;
        ++count;
    }

    // O(1)
    void addLast(const T& data) {
        Node<T>* node = new Node<T>(data);
        if (!head) head = node;
        else tail->next = node;
        tail = node;
        ++count;
    }

    bool removeFirst() {
        if (!head) return false;
        Node<T>* old = head;
        head = head->next;
        delete old;
        --count;
        if (!head) tail = nullptr;
        return true;
    }

    // Inserta DESPUES de un indice existente (enunciado del menu). O(n).
    void insert(int index, const T& data) {
        Node<T>* previous = nodeAt(index);
        previous->next = new Node<T>(data, previous->next);
        if (tail == previous) tail = previous->next;
        ++count;
    }

    // Borra solo la primera coincidencia. O(n).
    bool deleteData(const T& data) {
        Node<T>** link = &head;
        return deleteAt(findData(data));
    }

    // Indice invalido: false; conserva la lista. O(n).
    bool deleteAt(int index) {
        if (index < 0 || index >= count) return false;
        Node<T>** link = &head;
        for (int i = 0; i < index; ++i) link = &((*link)->next);
        Node<T>* old = *link;
        *link = old->next;
        if (old == tail) {
            tail = head;
            while (tail && tail->next) tail = tail->next;
        }
        delete old;
        --count;
        return true;
    }

    T getData(int index) const { return nodeAt(index)->data; }

    // Actualiza solo la primera coincidencia. O(n).
    void updateData(const T& oldData, const T& newData) {
        Node<T>* node = head;
        while (node && !(node->data == oldData)) node = node->next;
        if (!node) throw out_of_range("No se encontro el dato a actualizar");
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

    void print(ostream& out = cout) const {
        out << '[';
        for (const Node<T>* node = head; node; node = node->next) {
            out << node->data;
            if (node->next) out << ", ";
        }
        out << "]\n";
    }
};

#endif
