#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"
#include "trig.h"

const string prompt = "> ";
const string result = "= ";
double statement(Token_stream& ts);
double expression(Token_stream& ts);
double term(Token_stream& ts);
double expon(Token_stream& ts);
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
                next_t = ts.get();
                if (next_t.kind != ')') error("')' expected");
//                cout << "testing trig... " << "t.name: " << t.name << " d : " << d << endl;
                d = exec_func(t.name, d);
                
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
    double left =expon(ts);
    Token t = ts.get();
    while(true) {
        switch (t.kind) {
            case '*':
                left *= expon(ts);
                t = ts.get();
                break;
            case '/':
            {
                double d = expon(ts);
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d = expon(ts);
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

double expon(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();
    if(t.kind == power) {
        double d = primary(ts);
        return pow(left, d);
    }
    else {
        ts.putback(t);
        return left;
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
            cout << setprecision(10) << result << statement(ts) << '\n';
        }catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
    
}

int main()
{
    set_value("pi", 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409);
    set_value("e", 2.7182818284);
    try {
        calculate(ts);
        return 0;
    }
    catch(...) {
        cerr << "unknown exception \n";
        return 2;
    }
}



