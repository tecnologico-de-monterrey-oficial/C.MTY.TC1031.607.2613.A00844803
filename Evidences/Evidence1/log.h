#ifndef LOG_H
#define LOG_H

#include <string>
using namespace std;

struct log {
    int year;
    string month;
    int day;
    string time;
    string ip;
    string message;
    string key;
    log();
    log(int year, string month, int day, string time, string ip, string message);
    string createKey();
    bool operator>(const log& other) const;
    bool operator<(const log& other) const;
    bool operator==(const log& other) const;
    bool operator!=(const log& other) const;
    bool operator>=(const log& other) const;
    bool operator<=(const log& other) const;
};

#endif