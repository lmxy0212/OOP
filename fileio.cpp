#include "std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
    double pressure;
};

int main()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error("can't open input file ",iname);
    
    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost {oname};
    if (!ost) error("can't open output file ",oname);
    
    vector<Reading> temps; 
    int hour;
    double temperature;
    char sep1;
    double pressure;
    char sep2;
    while (ist >> hour >> sep1 >>temperature >> sep2 >> pressure) {
        if (hour < 0 || 23 < hour) error("hour out of range");
        temps.push_back(Reading{hour,temperature,pressure});
    }
    for (int i=0; i<temps.size(); ++i)
        ost << '(' << temps[i].hour << '\t'
        << temps[i].temperature << '\t' << temps[i].pressure <<")\n";
}
