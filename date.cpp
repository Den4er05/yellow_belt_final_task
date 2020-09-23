#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#include "date.h"

bool operator < (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} < 
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator > (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
        vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator == (const Date& lhs, const Date& rhs) {
    return ((lhs.GetYear() == rhs.GetYear()) && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}

ostream& operator << (ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
        "-" << setw(2) << setfill('0') << date.GetMonth() <<
        "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

Date ParseDate(istream& is) {
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    return Date(year, month, day);
}

Date::Date(const int& new_year, const int& new_month, const int& new_day) : year(new_year), month(new_month), day(new_day) {
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
    }
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}
