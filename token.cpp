#include "std_lib_facilities.h"

class Token{
public:
    char kind;
    double value;
};
Token get_token(){
    char ch;
    cin >> ch;
    switch(ch){
        case 'q': case ';': case '(': case '+': case '-': case '*': case '/': case ')':
            return Token{ch};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
            cin.putback(ch);// read more digit
            double val;
            cin >> val;
            return Token{'8',val};
            
    }
};

vector <Token> tokens;
int main(){
    Token t = get_token();
    while( t.kind != 'q'){
        tokens.push_back(t);
        t = get_token();
    }
    for( Token token : tokens){
        if(token.kind == '8') {
            cout << "token kind number" << " with value " << token.value << "\n";
        }
        else{
            cout << "token kind " <<token.kind << "\n";
        }
        
    }
}

