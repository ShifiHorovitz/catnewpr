

#include "Date.h"
#include <iostream>
using namespace std;

// Constructor
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

// Getter
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

// Setter
void Date::setDay(int d) {
    if (d > 5 || d < 1)
        cout << "the day not good";
        
    else
      day = d;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setYear(int y) {
    year = y;
}

// פונקציה להדפסת התאריך
void Date::printDate() const {
    cout << day << "/" << month << "/" << year << endl;
}

// פונקציה להשוואת תאריכים
bool Date::isEqual(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}



