#ifndef LOGLOADER_H
#define LOGLOADER_H

#include <fstream>
#include <iostream>
#include <string>

#include "LogRecord.h"
#include "Queue.h"
#include "DoublyLinkedList.h"

inline bool loadLogs(const std::string& fileName,
                     DoublyLinkedList<LogRecord>& logs,
                     int& omitted) {
    std::ifstream file(fileName.c_str());

    if (!file) {
        return false;
    }

    Queue<std::string> pending;
    std::string line;

    while (std::getline(file, line)) {
        pending.push(line);
    }

    file.close();

    omitted = 0;
    int lineNumber = 0;

    while (pending.getSize() > 0) {
        std::string raw = pending.pop();
        lineNumber++;

        LogRecord record;
        std::string reason;

        if (parseLine(raw, lineNumber, record, reason)) {
            logs.addLast(record);
        } else {
            omitted++;
            std::cout << "Linea " << lineNumber
                      << " omitida: " << reason << "\n";
        }
    }

    std::cout << "Cargados: " << logs.getSize()
              << " | Omitidos: " << omitted << "\n";

    return true;
}

#endif