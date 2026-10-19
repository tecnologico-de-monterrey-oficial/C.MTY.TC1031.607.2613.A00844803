#ifndef LOGREPORTS_H
#define LOGREPORTS_H

#include <iostream>

#include "LogRecord.h"
#include "Stack.h"
#include "DoublyLinkedList.h"
#include <map>
#include <sstream>

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

inline void showStatistics(const DoublyLinkedList<LogRecord>& logs) {
    if (logs.getSize() == 0) {
        std::cout << "No hay registros.\n";
        return;
    }

    std::map<std::string, int> days;
    std::map<std::string, int> events;
    std::map<std::string, int> ips;

    const NodeD<LogRecord>* current = logs.getHead();

    while (current != nullptr) {
        const LogRecord& record = current->data;

        std::ostringstream date;
        date << record.year << "-" << record.month << "-" << record.day;

        days[date.str()]++;
        events[record.eventType]++;
        ips[record.ip]++;

        current = current->next;
    }

    int maxDays = 0;
    int maxEvents = 0;
    int maxIps = 0;

    for (std::map<std::string, int>::const_iterator it = days.begin();
         it != days.end(); ++it) {
        if (it->second > maxDays) maxDays = it->second;
    }

    for (std::map<std::string, int>::const_iterator it = events.begin();
         it != events.end(); ++it) {
        if (it->second > maxEvents) maxEvents = it->second;
    }

    for (std::map<std::string, int>::const_iterator it = ips.begin();
         it != ips.end(); ++it) {
        if (it->second > maxIps) maxIps = it->second;
    }

    std::cout << "Total de registros: " << logs.getSize()
              << "\nDia(s) mas ocupado(s) (" << maxDays << "): ";

    for (std::map<std::string, int>::const_iterator it = days.begin();
         it != days.end(); ++it) {
        if (it->second == maxDays) std::cout << it->first << " ";
    }

    std::cout << "\nEvento(s) mas frecuente(s) (" << maxEvents << "): ";

    for (std::map<std::string, int>::const_iterator it = events.begin();
         it != events.end(); ++it) {
        if (it->second == maxEvents) std::cout << it->first << " ";
    }

    std::cout << "\nIP(s) mas frecuente(s) (" << maxIps << "): ";

    for (std::map<std::string, int>::const_iterator it = ips.begin();
         it != ips.end(); ++it) {
        if (it->second == maxIps) std::cout << it->first << " ";
    }

    std::cout << "\n";
}

#endif