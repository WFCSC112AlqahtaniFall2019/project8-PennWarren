//
// Created by Benjamin Raiford on 11/13/19.
//

#ifndef PROJECT7_DATA_H
#define PROJECT7_DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include "Day.h"

class Data {
    public:

        //Constructors
        Data();
        Data(std::string, double threeMo, double twoYr, double tenYr);

        //Overloaded Operators
        friend std::ostream& operator<<(std::ostream& os, const Data& d);
        bool operator >(const Data& rhs) const;
        bool operator <(const Data& rhs) const;

        //Functions
        bool checkHoliday();
        void setDerivedData();
        void printDataScreen();

    private:

        //Data pulled from CSV
        Day date; //day
        double threeMonth; //3-month treasury bill constant maturity rate
        double twoYear; //2-year treasury constant maturity rate
        double tenYear; //10-year treasury constant maturity rate

        //Data derived from explicit variables
        bool holiday; //date is a holiday if there is no data for the double variables above
        double TenYr_ThreeMo_Spread; //10-year 3-month spread, leading recession indicator
        double TenYr_TwoYr_Spread; //10-year 2-year spread, leading recession indicator

};



#endif //PROJECT7_DATA_H
