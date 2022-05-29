#include <iostream>
#include "SingleLinkList.h"

int main() {

    auto list = new SingleLinkList<int>();
    list->addAtHead(1);
    list->addAtTail(3);
    list->print();

    list->addAtIndex(3, 2);
    list->print();
}
