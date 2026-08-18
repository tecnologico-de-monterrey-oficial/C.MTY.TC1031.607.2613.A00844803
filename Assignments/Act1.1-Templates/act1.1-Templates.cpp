#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {

    int a = 2;
    int b = 3;
    cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << endl;

    cout << "\n=== Integer List ===" << endl;
    List<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "\nInitial content:" << endl;
    list.print();

    cout << "\nSize: " << list.getSize() << endl;
    cout << "Max: " << list.getMax() << endl;
    cout << "getData(1): " << list.getData(1) << endl;

    cout << "\ninsertAt(2, 25):" << endl;
    list.insertAt(2, 25);
    list.print();

    cout << "\ninsertAt(100, 99) -> Invalid position:" << endl;
    list.insertAt(100, 99);

    cout << "\nremoveAt(0) -> Removes and displays the value:" << endl;
    list.removeAt(0);
    list.print();

    cout << "\nremoveAt(50) -> Invalid position:" << endl;
    list.removeAt(50);

    cout << "\nremoveLast() -> Removes and displays the last value:" << endl;
    list.removeLast();
    list.print();

    cout << "\nFinal size: " << list.getSize() << endl;

    cout << "\n=== Empty List ===" << endl;
    List<int> emptyList;
    emptyList.removeLast();
    emptyList.removeAt(0);

    return 0;
}