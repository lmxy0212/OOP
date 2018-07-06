//
//  July5.cpp
//  
//
//  Created by Limanxueying on 7/5/18.
//

#include "std_lib_facilities.h"
//input

//int main(){
//    cout << "Please enter your name:\n";
//    string first_name;
//    cin >> first_name;
//    cout << "Hello " << first_name << "\n";
//    return 0;
//}

//int main(){
//    cout << "Please enter your name:\n";
//    string first_name;
//    int age;
//    cin >> first_name;
//    cin >> age;
//
//    cout << "Hello " << first_name << "is" << age << "\n";
//    return 0;
//}

//operator

//int count;
//cin >> count;
//string name;
//cin >> name;
//int c2 = count +2;
//string first_name = name + "Jr";
////string second_name = name - "Jr"; no minus for str

//int main(){
//    string prev = " ";
//    string curr;
//    while(cin >> curr){
//        if(prev == curr)
//            cout << "repeated word " << curr;//if only one line-> no need for {}
//        prev = curr;
//    }
//}


int main(){
    int number_of_words = 0;
    string pre = " ";
    string curr;
    while(cin >> curr){
        ++ number_of_words;
        if(pre == curr)
            cout << "word number" << number_of_words << "repeated: " << curr << "\n";
        pre = curr;
    }
}



