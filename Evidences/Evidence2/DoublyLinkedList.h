//Cesar Cardenas - A00844803
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include "NodeD.h"

using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int count;

    // Busca el nodo de una posicion.
    NodeD<T>* getNode(int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Indice invalido");
        }

        NodeD<T>* aux = head;

        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }

        return aux;
    }

    NodeD<T>* mergeParts(NodeD<T>* first, NodeD<T>* second,
                     long long& comparisons) {
    NodeD<T>* result = nullptr;
    NodeD<T>* last = nullptr;

    while (first != nullptr && second != nullptr) {
        NodeD<T>* selected;
        comparisons++;

        // Si las fechas son iguales, conserva primero el nodo izquierdo.
        if (!(first->data > second->data)) {
            selected = first;
            first = first->next;
        } else {
            selected = second;
            second = second->next;
        }

        selected->prev = last;

        if (last == nullptr) {
            result = selected;
        } else {
            last->next = selected;
        }

        last = selected;
    }

    NodeD<T>* remaining = first != nullptr ? first : second;

    while (remaining != nullptr) {
        NodeD<T>* next = remaining->next;
        remaining->prev = last;

        if (last == nullptr) {
            result = remaining;
        } else {
            last->next = remaining;
        }

        last = remaining;
        remaining = next;
    }

    last->next = nullptr;
    return result;
}

NodeD<T>* sortParts(NodeD<T>* first, long long& comparisons,
                    int depth, int& maxDepth) {
    if (first == nullptr || first->next == nullptr) {
        return first;
    }

    if (depth > maxDepth) {
        maxDepth = depth;
    }

    NodeD<T>* slow = first;
    NodeD<T>* fast = first->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    NodeD<T>* second = slow->next;
    slow->next = nullptr;
    second->prev = nullptr;

    NodeD<T>* left = sortParts(first, comparisons, depth + 1, maxDepth);
    NodeD<T>* right = sortParts(second, comparisons, depth + 1, maxDepth);

    return mergeParts(left, right, comparisons);
}

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    int getSize() const {
        return count;
    }

    int size() const { return count; }
    bool isEmpty() const { return count == 0; }

    NodeD<T>* getHead() { return head; }

    const NodeD<T>* getHead() const {
        return head;
    }

    NodeD<T>* getTail() { return tail; }

    const NodeD<T>* getTail() const { return tail; }

    void mergeSort(long long& comparisons, int& maxDepth) {
        if (count < 2) {
            return;
        }

        head = sortParts(head, comparisons, 1, maxDepth);
        head->prev = nullptr;

        NodeD<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        tail = current;
    }

    NodeD<T>* partition(NodeD<T>* first, NodeD<T>* last,
                        long long& comparisons) {
        T pivot = last->data;
        NodeD<T>* boundary = first->prev;
        for (NodeD<T>* current = first; current != last; current = current->next) {
            comparisons++;
            if (!(current->data > pivot)) {
                boundary = boundary == nullptr ? first : boundary->next;
                T temp = boundary->data;
                boundary->data = current->data;
                current->data = temp;
            }
        }
        boundary = boundary == nullptr ? first : boundary->next;
        T temp = boundary->data;
        boundary->data = last->data;
        last->data = temp;
        return boundary;
    }

    void quickSortParts(NodeD<T>* first, NodeD<T>* last,
                        long long& comparisons, int depth, int& maxDepth) {
        if (first == nullptr || last == nullptr || first == last || first == last->next) return;
        if (depth > maxDepth) maxDepth = depth;
        NodeD<T>* pivot = partition(first, last, comparisons);
        if (pivot->prev != nullptr) quickSortParts(first, pivot->prev, comparisons, depth + 1, maxDepth);
        if (pivot->next != nullptr) quickSortParts(pivot->next, last, comparisons, depth + 1, maxDepth);
    }

    void quickSort(long long& comparisons, int& maxDepth) {
        if (count > 1) quickSortParts(head, tail, comparisons, 1, maxDepth);
    }

    bool isSorted() const {
        NodeD<T>* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data > current->next->data) {
                return false;
            }

            current = current->next;
        }

        return true;
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
        count++;
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
        count++;
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

            count++;
        }
    }

    // Inserta el dato despues de un nodo de esta lista.
    void insertAfter(NodeD<T>* target, T data) {
        NodeD<T>* current = head;
        int index = 0;
        while (current != nullptr && current != target) {
            current = current->next;
            index++;
        }
        if (current == nullptr) {
            throw out_of_range("El nodo no pertenece a la lista");
        }
        insert(index, data);
    }

    void clear() {
        while (head != nullptr) {
            NodeD<T>* aux = head;
            head = head->next;
            delete aux;
        }

        tail = nullptr;
        count = 0;
    }

    void print() {
        NodeD<T>* aux = head;
        cout << "[";

        while (aux != nullptr) {
            cout << aux->data;

            if (aux->next != nullptr) {
                cout << ", ";
            }

            aux = aux->next;
        }

        cout << "]" << endl;
    }

    void printReverse() {
        NodeD<T>* current = tail;
        cout << "[";
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) cout << ", ";
            current = current->prev;
        }
        cout << "]" << endl;
    }

    bool deleteNode(NodeD<T>* target) {
        NodeD<T>* current = head;
        while (current != nullptr && current != target) current = current->next;
        if (current == nullptr) return false;

        if (current->prev == nullptr) head = current->next;
        else current->prev->next = current->next;

        if (current->next == nullptr) tail = current->prev;
        else current->next->prev = current->prev;

        delete current;
        count--;
        return true;
    }

        bool deleteAt(int index) {
        if (index < 0 || index >= count) {
            return false;
        }

        NodeD<T>* aux = getNode(index);

        if (aux->prev == nullptr) {
            head = aux->next;
        } else {
            aux->prev->next = aux->next;
        }

        if (aux->next == nullptr) {
            tail = aux->prev;
        } else {
            aux->next->prev = aux->prev;
        }

        delete aux;
        count--;

        return true;
    }

    int findData(T data) {
        NodeD<T>* aux = head;
        int index = 0;

        while (aux != nullptr) {
            if (aux->data == data) {
                return index;
            }

            aux = aux->next;
            index++;
        }

        return -1;
    }

    bool deleteData(T data) {
        return deleteAt(findData(data));
    }

    T getData(int index) {
        return getNode(index)->data;
    }

        void updateAt(int index, T data) {
        getNode(index)->data = data;
    }

    void updateData(T oldData, T newData) {
        int index = findData(oldData);

        if (index == -1) {
            throw out_of_range("El dato no existe");
        }

        updateAt(index, newData);
    }

    T& operator[](int index) {
        return getNode(index)->data;
    }

    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other) {
        if (this != &other) {
            clear();
            NodeD<T>* aux = other.head;

            while (aux != nullptr) {
                addLast(aux->data);
                aux = aux->next;
            }
        }

        return *this;
    }

    // Permite copiar sin compartir los mismos nodos.
    DoublyLinkedList(const DoublyLinkedList<T>& other) {
        head = nullptr;
        tail = nullptr;
        count = 0;

        *this = other;
    }

        // Ordenamiento burbuja.
    void sort() {
        for (int i = 0; i < count - 1; i++) {
            NodeD<T>* aux = head;

            for (int j = 0; j < count - 1 - i; j++) {
                if (aux->data > aux->next->data) {
                    T temp = aux->data;
                    aux->data = aux->next->data;
                    aux->next->data = temp;
                }

                aux = aux->next;
            }
        }
    }

    // Repite cada elemento dos veces.
    void duplicate() {
        NodeD<T>* aux = head;

        while (aux != nullptr) {
            NodeD<T>* copy = new NodeD<T>(aux->data);

            copy->prev = aux;
            copy->next = aux->next;

            if (aux->next == nullptr) {
                tail = copy;
            } else {
                aux->next->prev = copy;
            }

            aux->next = copy;
            count++;

            // Avanza al siguiente nodo original.
            aux = copy->next;
        }
    }

    void removeDuplicates() {
        sort();

        NodeD<T>* aux = head;
        int index = 0;

        while (aux != nullptr && aux->next != nullptr) {
            if (aux->data == aux->next->data) {
                deleteAt(index + 1);
            } else {
                aux = aux->next;
                index++;
            }
        }
    }

    ~DoublyLinkedList() {
        clear();
    }
};

#endif
