#include <iostream>
#include <memory>
#include <string>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<std::string> list;

    list.push_front("b");
    list.push_front("a");
    list.push_front("@");

    list.print(); // Output: ! World Hello

    return 0;
}