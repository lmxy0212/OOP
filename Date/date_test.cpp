#include "std_lib_facilities.h"
#include "date.h"
//int(Month::jan)will convert enum to int

int main(){
    //overloading cin
    Date date_one;
    cout << "Please enter a date in format (YYYY,MM,DD): " ;
    cout << ">> ";
    while(cin){
        try{
            cin >> date_one;
            break;
        }catch(exception e){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter again: \n";
        }catch(Date::Invalid){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter again: \n";
        }
    }
    cout << "Long form: date one you enter is: " << longForm(date_one) << endl;
    cout << "cout: date one: " << date_one << endl;
    
    Date date_two;
    cout << "Please enter another date in format (YYYY,MM,DD): " ;
    cout << ">> ";
    while(cin){
        try{
            cin >> date_two;
            break;
        }catch(exception e){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter again: \n";
        }catch(Date::Invalid){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter again: \n";
        }
    }
    cout << "Long form: date you enter is: " << longForm(date_one) << endl;
    cout << "cout: date two: " << date_two << endl;
    
    
    //overloading == and !=
    cout << "testing " << date_one <<" == "<<date_two << ": "<< (date_one == date_two) << endl;
    cout << "testing " << date_one <<" == "<<date_two << ": "<< (date_two != date_one) << endl;
    
    //adding
    int y;
    cout << "enter years to add to day one: ";
    cin >> y;
    date_one.add_year(y);
    cout << "date after adding years: " << date_one << endl;
    int m;
    cout << "enter months to add to day one: ";
    cin >> m;
    date_one.add_month(m);
    cout << "date after adding months: " << date_one << endl;
    int d;
    cout << "enter days to add to day one: ";
    cin >> d;
    date_one.add_day(d);
    cout << "date after adding days: " << date_one << endl;
    
    //test leap year
    cout << "enter a year to test leap year: ";
    int year;
    cin >> year;
    cout << "testing leap year: " << leapYear(year) << endl;
    
    return 0;
}
