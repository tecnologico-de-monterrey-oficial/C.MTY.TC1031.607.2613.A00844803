// Cesar Cardenas - A00844803
#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    explicit Node(const T& value, Node<T>* following = nullptr)
        : data(value), next(following) {}
};

#endif
