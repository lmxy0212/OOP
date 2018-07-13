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
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':{
            cin.putback(ch);// read more digit
            double val;
            cin >> val;
            return Token{'8',val};
        }default:
            return Token{'e',double(ch)};
    }
};

vector <Token> tokens;
int main(){
    for(Token t = get_token();t.kind != 'q';t = get_token()){
        tokens.push_back(t);
    }
    for( Token token : tokens){
        if(token.kind == '8') {
            cout << "A number token with value = " << token.value << "\n";
        }
        else{
            if(token.kind == 'e'){
                cout << "We received an invalid token of value " << char(token.value) << "\n";
            }else{
                cout << "A token of kind " <<token.kind << "\n";
            }
        }
        
    }
}
