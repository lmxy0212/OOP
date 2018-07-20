//
//  date.cpp
//  
//
//  Created by Limanxueying on 7/20/18.
//
#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd}{
    if(!isValid()) throw Invalid{};
}
void Date::add_day(int n){
    
}
int Date::month(){
    return int(m);
}
int Date::year(){
    return y;
}
int Date::day(){
    return d;
}


bool Date::isValid(){
    if(int(m) < 1 || int(m) > 12)return false;
    if(y < 0)return false;
    if(d < 0 || d > 31) return false;
    else{
        switch(int(m)){
            case 2: case 4: case 6: case 9: case 11:
                if(d > 30) return false;
        }
    }
    return true;
}

//int(Month::jan)


