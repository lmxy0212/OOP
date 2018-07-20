//
//  date_test.cpp
//  
//
//  Created by Limanxueying on 7/20/18.
//
#include "std_lib_facilities.h"
#include "date.h"

int main(){
    Date today{2018,Month::jul,20};
//    cout << "today " << today.y << "/"<<today.m << "/"<< today.d <<"\n";
    cout << "year = " <<today.year() << endl;
    cout << "Month = " <<today.month() << endl;
    cout << "Date = " <<today.day() << endl;

    return 0;
}
