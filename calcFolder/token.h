const char invalid = 'i';
const char number = '8';
const char quit = 'q';
const char print = ';';

class Token{
public:
    char kind;
    double value;
};

class Token_stream{
public:
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    Token buffer;
    bool full{false};
};
