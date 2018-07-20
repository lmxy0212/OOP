//
//  date.hpp
//  
//
//  Created by Limanxueying on 7/20/18.
//

#include "std_lib_facilities.h"
enum class Month{
    jan = 1, feb, mar, apr, may, jun, jul, sep, oct, nov, dec
};

class Date{
public:
    class Invalid{};
    Date(int y, Month m, int d);
    void add_day(int n);
    int month();
    int year();
    int day();
private:
    int y,d;
    Month m;
    bool isValid();
};

