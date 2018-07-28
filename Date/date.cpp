#include "std_lib_facilities.h"
#include "date.h"

Date::Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd}{
    if(!isValid()) throw Invalid{};
}

//construct default date
const Date& default_day(){
    static Date dd{1900, Month::jan, 1};
    return dd;
}

Date::Date() //set to default
    :y{default_day().year()},
    m{Month(default_day().month())},
    d{default_day().day()}{}

void Date::add_day(int n){
    d+=n;
    int i = int(m);
    vector<int> days_of_the_month;
    
    if(leapYear(y)){
        days_of_the_month = maxDaysLeap;
    }else days_of_the_month = maxDays;
    
//    cout << i << " i /" << int(m) << " m /" << d << " d\n";

    while(d > days_of_the_month[i]){
        add_month(1);
        d -= days_of_the_month[i];
        i ++;
        
        if(i == 13) i = 1;
        if(leapYear(y)) days_of_the_month = maxDaysLeap;
        else days_of_the_month = maxDays;
        
//        cout << i << " i /" << int(m) << " m /" << d << " d\n";
    }
}


void Date::add_month(int n){
    m = Month(n+ int(m));
    if(int(m) > 12){
        add_year(int(m)/12);
        m = Month(int(m) % 12);
    }
}
void Date::add_year(int n){
    if(int(m) == 2 && d == 29 && !leapYear(y+n)){
        m = Month(3);
        d = 1;
    }
    y += n;
}

//checking valid date
bool Date::isValid(){
    if(int(m) < 1 || int(m) > 12)return false;
    if(y < 0)return false;
    if(d < 1 || d > 31) return false;
    else{
        if(int(m) ==2){
            if (leapYear(y)) {
                if(d > 29) return false;
            }else{
                if(d > 28) return false;
            }
        }
        switch(int(m)){
            case 4: case 6: case 9: case 11:
                if(d > 30) return false;
        }
    }
    return true;
}

ostream& operator << (ostream& os, const Date& d){
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

istream& operator >> (istream& is, Date& dd){
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if(!is) throw Date::Invalid {};
    if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')'){
        is.clear(ios_base::failbit);
        throw Date::Invalid {};
    }
    dd = Date{y, Month(m), d};
    return is;
}

bool operator == (const Date& d1, const Date& d2){
    if(d1.year() == d2.year() && int(d1.month()) == int(d2.month()) && d1.day() == d2.day()) return true;
    else return false;
}

bool operator != (const Date& d1, const Date& d2){
    return !(d1 == d2);
}


bool leapYear(int y){
    if(y < 0) error("Invalid year entered ");
    return ((((y % 4) == 0) && (y % 100) != 0) || (y % 400) == 0);
}

string longForm(Date d){
    string s = month_names[int(d.month())] + " " + to_string(d.day()) + ", " + to_string(d.year());
    return s;
}
