#ifndef LOGRECORD_H
#define LOGRECORD_H

#include <string>

struct LogRecord {
    int month, day, year;
    int hour, minute, second;
    int lineNumber;
    std::string ip;
    std::string eventType;
    std::string original;

    bool operator>(const LogRecord& other) const;
};

inline int compareDate(const LogRecord& a, const LogRecord& b) {
    if (a.year != b.year) return a.year < b.year ? -1 : 1;
    if (a.month != b.month) return a.month < b.month ? -1 : 1;
    if (a.day != b.day) return a.day < b.day ? -1 : 1;
    if (a.hour != b.hour) return a.hour < b.hour ? -1 : 1;
    if (a.minute != b.minute) return a.minute < b.minute ? -1 : 1;
    if (a.second != b.second) return a.second < b.second ? -1 : 1;

    return 0;
}

inline bool LogRecord::operator>(const LogRecord& other) const {
    return compareDate(*this, other) > 0;
}

#endif