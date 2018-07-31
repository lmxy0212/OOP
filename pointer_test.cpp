#include "std_lib_facilities.h"


int main()
{
    char c = 'a';
    int i = 4092;
    double d = 3.14;
    char* cp = &c;
    int* ip = &i;
    double* dp = &d;
    cout << "cp = " << cp << " and its value is " << *cp << " ,size of c is " << sizeof(c) << endl;
    //cp = a and its value is a ,size of c is 1

    cout << "ip = " << ip << " and its value is " << *ip << " ,size of i is " << sizeof(i)<< endl;
    //ip = 0x7ffeebbd6ab8 and its value is 4092 ,size of i is 4

    cout << "dp = " << dp << " and its value is " << *dp << " ,size of d is " << sizeof(d)<< endl;
    //dp = 0x7ffeebbd6ab0 and its value is 3.14 ,womenshisize of d is 8

}
