#ifndef LOG_H
#define LOG_H

#include <string>
using namespace std;

struct Log {
    int year;
    string month;
    int day;
    string time;
    string ip;
    string message;
    string key;
    Log();
    Log(int year, string month, int day, string time, string ip, string message);
    string createKey();
    bool operator>(const Log& other) const;
    bool operator<(const Log& other) const;
    bool operator==(const Log& other) const;
    bool operator!=(const Log& other) const;
    bool operator>=(const Log& other) const;
    bool operator<=(const Log& other) const;
};

#endif