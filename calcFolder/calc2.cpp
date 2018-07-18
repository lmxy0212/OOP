#include "std_lib_facilities.h"
#include "token.h"

const string prompt = "> ";
const string result = "= ";

Token_stream ts;

void clean_up_mess()
{
    ts.ignore(print);
}

vector<Token> tokens;

double expression(Token_stream& ts);
double primary(Token_stream& ts){
    Token t = ts.get();
    //print_token(t); to check what value is stored in token
    switch (t.kind){
        case '(':    // handle '(' expression ')'
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;  // return the number's value
        case '-':
            return -primary(ts);
        case '+':
            return primary(ts);
        case invalid:
            error("Received Invalid Token");
        default:
            error("primary expected");
    }
    return t.value;
}
double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();        // get the next token from token stream
    
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
                ts.putback(t);     // put t back into the token stream
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
    t = ts.get();
}

void calculate(Token_stream& ts)
{
    while(cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            //this output is for debugging:
            //cout << "in main(), got token: " << t.kind
            //<< " with val of " << t.value << '\n';
            while(t.kind == print){
                t = ts.get();
            }
            if(t.kind == quit){
                return;
            }
            ts.putback(t);
            cout << result << expression(ts) << '\n';
        }
        catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
    
}

int main()
{
    try {
        calculate(ts);
        // keep_window_open();   // only if needed!
        return 0;
    }
    catch(...) {
        cerr << "unknown exception \n";
        return 2;
    }
}



