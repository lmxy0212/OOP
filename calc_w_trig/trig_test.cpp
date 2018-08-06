#include <iostream>
#include <string>
#include "trig.h"

using namespace std;

int main()
{
    double d = .5;
    cout << "sin(d) = " << exec_func("sin", d) << '\n';
    cout << "cos(d) = " << exec_func("cos", d) << '\n';
    d = 1.5708;
    cout << "sin(d) = " << exec_func("sin", d) << '\n';
    cout << "cos(d) = " << exec_func("cos", d) << '\n';
    d = 0.0;
    cout << "sin(d) = " << exec_func("sin", d) << '\n';
    cout << "cos(d) = " << exec_func("cos", d) << '\n';
}
