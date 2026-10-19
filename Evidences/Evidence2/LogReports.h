//Cesar Cardenas - A00844803
#ifndef LOGREPORTS_H
#define LOGREPORTS_H

#include <iostream>

#include "LogRecord.h"
#include "Stack.h"
#include "DoublyLinkedList.h"
#include <map>
#include <sstream>

using namespace std;

inline int searchDay(const DoublyLinkedList<LogRecord>& logs,
                     int year, int month, int day) {
    int found = 0;
    const NodeD<LogRecord>* current = logs.getHead();

    while (current != nullptr) {
        if (sameDay(current->data, year, month, day)) {
            cout << current->data.original << "\n";
            found++;
        } else if (afterDay(current->data, year, month, day)) {
            break;
        }

        current = current->next;
    }

    return found;
}

// Vuelve a recorrer el dia y usa una pila para imprimirlo al reves.
inline int showDayReverse(const DoublyLinkedList<LogRecord>& logs,
                          int year, int month, int day) {
    Stack<LogRecord> results;
    const NodeD<LogRecord>* current = logs.getHead();

    while (current != nullptr) {
        if (sameDay(current->data, year, month, day)) {
            results.push(current->data);
        } else if (afterDay(current->data, year, month, day)) {
            break;
        }

        current = current->next;
    }

    int found = results.getSize();
    while (results.getSize() > 0) {
        cout << results.pop().original << "\n";
    }

    return found;
}

inline void showStatistics(const DoublyLinkedList<LogRecord>& logs) {
    if (logs.getSize() == 0) {
        cout << "No hay registros.\n";
        return;
    }

    map<string, int> days;
    map<string, int> events;
    map<string, int> ips;

    const NodeD<LogRecord>* current = logs.getHead();

    while (current != nullptr) {
        const LogRecord& record = current->data;

        ostringstream date;
        date << record.year << "-" << record.month << "-" << record.day;

        days[date.str()]++;
        events[record.eventType]++;
        ips[record.ip]++;

        current = current->next;
    }

    int maxDays = 0;
    int maxEvents = 0;
    int maxIps = 0;

    for (map<string, int>::const_iterator it = days.begin();
         it != days.end(); ++it) {
        if (it->second > maxDays) maxDays = it->second;
    }

    for (map<string, int>::const_iterator it = events.begin();
         it != events.end(); ++it) {
        if (it->second > maxEvents) maxEvents = it->second;
    }

    for (map<string, int>::const_iterator it = ips.begin();
         it != ips.end(); ++it) {
        if (it->second > maxIps) maxIps = it->second;
    }

    cout << "Total de registros: " << logs.getSize()
              << "\nDia(s) mas ocupado(s) (" << maxDays << "): ";

    for (map<string, int>::const_iterator it = days.begin();
         it != days.end(); ++it) {
        if (it->second == maxDays) cout << it->first << " ";
    }

    cout << "\nEvento(s) mas frecuente(s) (" << maxEvents << "): ";

    for (map<string, int>::const_iterator it = events.begin();
         it != events.end(); ++it) {
        if (it->second == maxEvents) cout << it->first << " ";
    }

    cout << "\nIP(s) mas frecuente(s) (" << maxIps << "): ";

    for (map<string, int>::const_iterator it = ips.begin();
         it != ips.end(); ++it) {
        if (it->second == maxIps) cout << it->first << " ";
    }

    cout << "\n";
}

#endif
