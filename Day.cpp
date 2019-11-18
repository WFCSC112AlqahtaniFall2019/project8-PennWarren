//
// Created by Benjamin Raiford on 11/4/19.
//

#include "Day.h"
using namespace std;

//Overloaded operators
bool Day::operator<(const Day &rhs) {
    if(this->year != rhs.year){
        return this->year < rhs.year;
    }
    else{
        if(this->month != rhs.month){
            return this->month < rhs.month;
        }
        else {
            return this->day < rhs.day;
        }
    }
}
bool Day::operator>(const Day &rhs) {
    if(this->year != rhs.year){
        return this->year > rhs.year;
    }
    else{
        if(this->month != rhs.month){
            return this->month > rhs.month;
        }
        else {
            return this->day > rhs.day;
        }
    }
}
bool Day::operator==(const Day &rhs) {
    return (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day);
}

//Output date as string
string Day::outputDate() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

