#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

class Token
{
    public:
        enum Type {NONE, KEYWORD, IDENTIFIER, SYMBOL};

        Token(std::string _lexemes, Type _token_type) : lexemes(_lexemes), token_type(_token_type) {}
        ~Token(){}
        std::string get_lexemes() const {return lexemes;}
        Type get_type() const {return token_type;}

    private:
        std::string lexemes;
        Type token_type;
};

#endif
