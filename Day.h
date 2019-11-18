//
// Created by Benjamin Raiford on 11/4/19.
//

#ifndef PROJECT7_DAY_H
#define PROJECT7_DAY_H

#include <string>

class Day {

    private:
        int year;
        int month;
        int day;

    public:
        //Constructors
        Day(){
            year = 0;
            month = 0;
            day = 0;
        }
        Day(int y, int m, int d){
            year = y;
            month = m;
            day = d;
        }
        explicit Day(std::string &s){

            //Find the location of the slashes
            int daySlash, monthSlash;
            std::string delimiter = "/";
            size_t firstSlash = s.find(delimiter);
            size_t secondSlash = s.find(delimiter, firstSlash + 1);

            //Input parsed data
            month = stoi(s.substr(0, firstSlash));
            day = stoi(s.substr(firstSlash + 1, secondSlash - (firstSlash + 1)));
            year = stoi(s.substr(secondSlash + 1));

        }

        //Functions
        std::string outputDate() const;

        //Overloaded operators
        bool operator < (const Day& rhs);
        bool operator > (const Day& rhs);
        bool operator==(const Day &rhs);

};

#endif //PROJECT7_DAY_H
