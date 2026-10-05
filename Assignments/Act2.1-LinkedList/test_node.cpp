// Cesar Cardenas - A00844803
#include <iostream>
#include <memory>
#include "Node.h"

int main() {
    auto node1 = std::make_unique<Node<int>>(20);
    auto node2 = std::make_unique<Node<int>>(10, node1.get());
    // next es no propietario aqui; ambos unique_ptr controlan sus nodos.
    std::cout << "node2 data: " << node2->data << '\n';
    std::cout << "node1 data: " << node2->next->data << '\n';
}
