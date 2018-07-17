#include "std_lib_facilities.h"
const char number = '8';
const char quit = 'q';
const char print = ';';
const char invalid = 'i';
const string prompt = "> ";
const string result = "= ";

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
    void ignore(char c);
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
        case quit: case print : case '(': case '%' : case '+': case '-': case '*': case '/': case ')': case '=':
            return Token{ch};
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':{
            cin.putback(ch);// read more digit
            double val;
            cin >> val;
            return Token{number,val};
        }default:
            return Token{invalid, double(ch)};
    }
    return Token{quit};
}

void Token_stream::ignore(char c){
    if(full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    char ch = 0;
    while(cin>>ch)
        if(ch == c) return;
}

Token_stream ts;
double expression();

double primary(){
    Token t = ts.get();
    switch (t.kind) {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case '-':
            return -primary();
        case '+':
            return primary();
        case invalid:
            error("invalid token recieved");
        default:
            error("primary expected");
    }
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
            }case '%':{
                double d = primary();
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }default:
                ts.putback(t);
                return left;
        }
//        print_token(t);
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

void clean_up_mess()
{
    ts.ignore(print);
}
void calculate()
{
    while(cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while(t.kind == print) t = ts.get(); //deal with multiple ';'
            if(t.kind == quit) return;
            ts.putback(t);
            cout << result << expression() << '\n';
        }
        catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
    
}

int main(){
    Token_stream ts;
    try{
        calculate();
        return 0;
    } catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }catch(...) {
        cerr << "exception \n";
        return 2;
    }

}

