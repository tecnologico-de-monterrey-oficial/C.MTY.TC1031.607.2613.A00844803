// Cesar Cardenas - A00844803
#include <iostream>
#include "Node.h"

int main() {
    Node<int>* node = new Node<int>(10);
    node->data = 20;
    std::cout << node->data << '\n';
    delete node;
    node = nullptr;
}
