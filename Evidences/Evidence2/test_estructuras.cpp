// Cesar Cardenas - A00844803
#include <cassert>
#include <iostream>
#include <stdexcept>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    LinkedList<int> list;
    assert(list.isEmpty());
    assert(list.size() == 0);
    assert(!list.removeFirst());
    list.addFirst(2);
    assert(list.getHead() == list.getTail());
    list.addFirst(1);
    list.addLast(3);
    assert(list.size() == 3);
    list.print();
    assert(list.removeFirst());
    assert(list.getHead()->data == 2);
    assert(list.deleteAt(1));
    assert(list.getTail()->data == 2);
    assert(list.removeFirst());
    assert(list.isEmpty());

    Stack<int> stack;
    assert(stack.isEmpty());
    assert(stack.size() == 0);
    try {
        stack.pop();
        assert(false);
    } catch (const out_of_range&) {
        cout << "Pila vacia: mensaje de error correcto.\n";
    }
    stack.push(7);
    assert(stack.size() == 1);
    assert(stack.peek() == 7);
    stack.push(8);
    assert(stack.pop() == 8);
    assert(stack.pop() == 7);
    assert(stack.isEmpty());

    Queue<int> queue;
    assert(queue.isEmpty());
    assert(queue.size() == 0);
    try {
        queue.dequeue();
        assert(false);
    } catch (const out_of_range&) {
        cout << "Fila vacia: mensaje de error correcto.\n";
    }
    queue.enqueue(7);
    assert(queue.front() == 7);
    assert(queue.size() == 1);
    queue.enqueue(8);
    assert(queue.dequeue() == 7);
    assert(queue.dequeue() == 8);
    assert(queue.isEmpty());

    DoublyLinkedList<int> doubleList;
    assert(doubleList.isEmpty());
    doubleList.addLast(2);
    doubleList.insertAfter(doubleList.getHead(), 3);
    doubleList.addFirst(1);
    doubleList.addLast(4);
    assert(doubleList.size() == 4);
    doubleList.print();
    doubleList.printReverse();
    assert(doubleList.deleteNode(doubleList.getHead()));
    assert(doubleList.deleteNode(doubleList.getTail()));
    assert(doubleList.size() == 2);
    assert(doubleList.deleteNode(doubleList.getHead()->next));
    assert(doubleList.size() == 1);
    assert(doubleList.getHead()->data == 2);
    assert(doubleList.deleteNode(doubleList.getHead()));
    assert(doubleList.isEmpty());

    cout << "Pruebas de listas, pila y fila completadas.\n";
    return 0;
}
