#include <iostream>
#include "node.h"

using namespace std;

int main(){
    auto node1 = std::make_unique<Node<int>>(20);
    cout<<"node1 data: "<<node1->data<<endl;

    auto node2 = std::make_unique<Node<int>>(20, std::move(node1));
    cout<<"node2 data: "<<node2->data<<endl;



    return 0;
}