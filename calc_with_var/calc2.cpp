#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"

const string prompt = "> ";
const string result = "= ";
double statement(Token_stream& ts);
double expression(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);

Token_stream ts;

void clean_up_mess()
{
    ts.ignore(print);
}

vector<Token> tokens;

double statement(Token_stream& ts){
    Token t = ts.get();
    if(t.kind == name) {
        Token var = t;
        t = ts.get();
        if(t.kind == '=') {
            double d = expression(ts);
            set_value(var.name, d);
            return d;
        }
        else if(t.kind == print) {
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression(ts);
    }
    ts.putback(t);
    return expression(ts);
}

double primary(Token_stream& ts){
    Token t = ts.get();
    switch (t.kind){
        case '(':
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case name:{
            Token next_t = ts.get();
            if(next_t.kind == '(') {
                double d = expression(ts);
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
            }
            else {
                ts.putback(next_t);
                return get_value(t.name);
            }
        }
        case '-':
            return -primary(ts);
        case '+':
            return primary(ts);
        case invalid:
            error("Received Invalid Token");
        default:
            error("primary expected");
    }
    return 0.0;
}
double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();
    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary(ts);
                t = ts.get();
                break;
            case '/':
            {
                double d = primary(ts);
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d = primary(ts);
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
    
}
double expression(Token_stream& ts){
    double left = term(ts);
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '+': {
                left += term(ts);
                t = ts.get();
                break;
            }
            case '-':{
                left -= term(ts);
                t = ts.get();
                break;
            }default:
                ts.putback(t);
                return left;
        }
    }
//    t = ts.get();
}

void calculate(Token_stream& ts)
{
    while(cin) {
        try {
            cout << prompt;
            Token t = ts.get();
        
            while(t.kind == print){
                t = ts.get();
            }
            if(t.kind == quit){
                return;
            }
            ts.putback(t);
            cout << result << statement(ts) << '\n';
        }catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
    
}

int main()
{
    try {
        calculate(ts);
        return 0;
    }
    catch(...) {
        cerr << "unknown exception \n";
        return 2;
    }
}



