#include "std_lib_facilities.h"

int main(){
	//int to char
	int i = 23333333;
	char c = i; 
	cout << "i = " << i << " c = " << c << "\n" ;
	i = c;
	cout << "i = " << i << " c = " << c << "\n" ;

	//in to bool
	bool b = i;
	cout << "i = " << i << " b = " << b << "\n" ;
	i = b;
	cout << "i = " << i << " b = " << b << "\n" ;

	//char to bool
	c = 'z';
	b = c;
	cout << "c = " << c << " b = " << b << "\n" ;
	c = b;
	cout << "c = " << c << " b = " << b << "\n" ;

	//double to int
	double f = 1234567891234.123;
	i = f;
	cout << "i = " << i << " f = " << f << "\n" ;
	f = i;
	cout << "i = " << i << " f = " << f << "\n" ;

	//double to char
	f = 1234567891234.123;
	c = f;
	cout << "c = " << c << " f = " << f << "\n" ;
	f = c;
	cout << "c = " << c << " f = " << f << "\n" ;

	//double to bool
	f = 1234567891234.123;
	b = f;
	cout << "b = " << b << " f = " << f << "\n" ;
	f = b;
	cout << "b = " << b << " f = " << f << "\n" ;
}