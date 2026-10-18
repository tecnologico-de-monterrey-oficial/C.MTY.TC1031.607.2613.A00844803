#ifndef LOGRECORD_H
#define LOGRECORD_H

#include <string>
#include <sstream>

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

inline int monthNumber(const std::string& month) {
    const std::string names[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    for (int i = 0; i < 12; i++) {
        if (month == names[i]) return i + 1;
    }

    return 0;
}

inline bool leapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

inline int daysInMonth(int month, int year) {
    const int days[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month < 1 || month > 12) return 0;
    if (month == 2 && leapYear(year)) return 29;

    return days[month - 1];
}

inline bool parseLine(const std::string& line, int lineNumber,
                      LogRecord& record, std::string& reason) {
    std::istringstream input(line);
    std::string month, timeText;

    if (!(input >> month >> record.day >> record.year
                >> timeText >> record.ip)) {
        reason = "faltan campos";
        return false;
    }

    record.month = monthNumber(month);

    if (record.month == 0) {
        reason = "mes invalido";
        return false;
    }

    if (record.year < 1 || record.day < 1 ||
        record.day > daysInMonth(record.month, record.year)) {
        reason = "fecha invalida";
        return false;
    }

    char colon1, colon2;
    std::istringstream timeInput(timeText);

    if (!(timeInput >> record.hour >> colon1
                    >> record.minute >> colon2 >> record.second) ||
        colon1 != ':' || colon2 != ':') {
        reason = "hora invalida";
        return false;
    }

    if (record.hour < 0 || record.hour > 23 ||
        record.minute < 0 || record.minute > 59 ||
        record.second < 0 || record.second > 59) {
        reason = "hora fuera de rango";
        return false;
    }

    std::getline(input, record.eventType);

    if (!record.eventType.empty() && record.eventType[0] == ' ') {
        record.eventType.erase(0, 1);
    }

    if (record.eventType.empty()) {
        reason = "falta tipo de evento";
        return false;
    }

    record.lineNumber = lineNumber;
    record.original = line;
    return true;
}

inline bool sameDay(const LogRecord& record, int year, int month, int day) {
    return record.year == year &&
           record.month == month &&
           record.day == day;
}

inline bool afterDay(const LogRecord& record, int year, int month, int day) {
    if (record.year != year) return record.year > year;
    if (record.month != month) return record.month > month;
    return record.day > day;
}

#endif