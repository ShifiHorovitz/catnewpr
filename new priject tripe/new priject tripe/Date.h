#pragma once



#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d, int m, int y);

    // Getter
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setter
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // פונקציה להדפסת התאריך
    void printDate() const;

    // פונקציה להשוואת תאריכים
    bool isEqual(const Date& other) const;
};

#endif

