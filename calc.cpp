#include "std_lib_facilities.h"
//Jul 13

class Token{
public:
    char kind;
    double value;
};

void print_token(Token t){
    cout << "Token.kind = " << t.kind << " token.val = " << t.value << "\n";
}

class Token_stream{
public:
    Token get();
    void putback(Token t);
private:
    Token buffer;
    bool full{false};
};


void Token_stream::putback(Token t){ //:: scope resolution operator
    buffer = t;
    full = true;
}

Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }
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
        }
        default:
            return Token{'i', double(ch)};
    }
    return Token{'q'};
}
Token_stream ts;
double primary(){
    Token t = ts.get();
    print_token(t);
    return t.value;
}
double term(){
    double left = primary();
    Token t = ts.get();
    while(true){
        switch (t.kind) {
            case '*':{
                left *= primary();
                t = ts.get();
                break;
            }case '/':{
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }default:
                ts.putback(t);
                return left;
        }
        print_token(t);
    }
}
double expression(){
    double left = term();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '+': {
                left += term();
                t = ts.get();
                break;
            }case '-':{
                left -= term();
                t = ts.get();
                break;
            }default:
                ts.putback(t);
                return left;
        }
    }
    t = ts.get();
}
vector<Token> tokens;
int main(){
    try{
        double val = 0.0;
        while(cin){
            Token t = ts.get();
            if(t.kind == 'q') break;
            if(t.kind == ';')cout << "=" << val << "\n";
            else ts.putback(t);
            val = expression();
        }
    } catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }catch(...) {
        cerr << "exception \n";
        return 2;
    }

}

