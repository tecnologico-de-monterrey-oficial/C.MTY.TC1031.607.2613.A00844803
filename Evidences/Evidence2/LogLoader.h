//Cesar Cardenas - A00844803
#ifndef LOGLOADER_H
#define LOGLOADER_H

#include <fstream>
#include <iostream>
#include <string>

#include "LogRecord.h"
#include "Queue.h"
#include "DoublyLinkedList.h"

using namespace std;

inline bool loadLogs(const string& fileName,
                     DoublyLinkedList<LogRecord>& logs,
                     int& omitted) {
    ifstream file(fileName.c_str());

    if (!file) {
        return false;
    }

    Queue<string> pending;
    string line;

    while (getline(file, line)) {
        pending.push(line);
    }

    file.close();

    omitted = 0;
    int lineNumber = 0;

    while (pending.getSize() > 0) {
        string raw = pending.pop();
        lineNumber++;

        LogRecord record;
        string reason;

        if (parseLine(raw, lineNumber, record, reason)) {
            logs.addLast(record);
        } else {
            omitted++;
            cout << "Linea " << lineNumber
                      << " omitida: " << reason << "\n";
        }
    }

    cout << "Cargados: " << logs.getSize()
              << " | Omitidos: " << omitted << "\n";

    return true;
}

#endif