#ifndef LOGREPORTS_H
#define LOGREPORTS_H

#include <iostream>

#include "LogRecord.h"
#include "Stack.h"
#include "DoublyLinkedList.h"

inline int searchDay(const DoublyLinkedList<LogRecord>& logs,
                     int year, int month, int day) {
    int found = 0;
    const NodeD<LogRecord>* current = logs.getHead();

    while (current != nullptr) {
        if (sameDay(current->data, year, month, day)) {
            std::cout << current->data.original << "\n";
            found++;
        } else if (afterDay(current->data, year, month, day)) {
            break;
        }

        current = current->next;
    }

    return found;
}

#endif