//Jul/23/2018
#include "std_lib_facilities.h"
#include "vars.h"

int main(){
    set_value("var1", 12.2);
    set_value("var2", 16.2);
    set_value("var3", 2.2);
    set_value("var4", 145.3);
    set_value("var1", 2.9);
    
    double d;
    d = get_value("var1");
    cout << "var1 = " << d << endl;
    d = get_value("var2");
    cout << "var2 = " << d << endl;
    d = get_value("var3");
    cout << "var3 = " << d << endl;
    d = get_value("var4");
    cout << "var4 = " << d << endl;
}
