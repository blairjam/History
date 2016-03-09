#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <string>
#include <vector>

#include "Token.hpp"

typedef std::vector<Token> vtoken;
typedef std::vector<char> vchar;

class Analyzer
{
    public:
        static const int KEYWORDS_LENGTH = 21;
        static const int SYMBOLS_LENGTH = 19;
        static const std::string KEYWORDS[];
        static const char SYMBOLS[];
        
        Analyzer(){}
        ~Analyzer(){}
        void create_tokens(vchar list);
        vtoken get_tokens() const {return tokens;}

    private:
        vtoken tokens;

        bool is_char_symbol(char c);
        bool is_string_keyword(std::string str);
};  

#endif
