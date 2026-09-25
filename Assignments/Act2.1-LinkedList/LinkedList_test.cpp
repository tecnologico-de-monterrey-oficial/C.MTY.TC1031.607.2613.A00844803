// Cesar Cardenas - A00844803
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList<string> list;
    list.push_front("b");
    list.push_front("a");
    list.push_front("@");
    list.push_front("&");
    list.print();


    return 0;
}