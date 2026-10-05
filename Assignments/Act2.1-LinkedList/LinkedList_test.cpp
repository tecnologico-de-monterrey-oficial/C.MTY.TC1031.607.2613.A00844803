// Cesar Cardenas - A00844803
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList<string> list;
    list.insert("b", 0);
    list.insert("a", 1);
    list.insert("@", 2);
    list.insert("&", 3);
    list.print();


    return 0;
}