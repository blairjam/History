#include <cctype>
#include <iostream>

#include "Analyzer.hpp"

const std::string Analyzer::KEYWORDS[] = {"boolean", "char", "class", "constructor", "do", "else", "false",
                                          "field", "function", "if", "int", "let", "method", "null",
                                          "return", "static", "this", "true", "var", "void", "while"
                                         };

const char Analyzer::SYMBOLS[] = {'{', '}', '(', ')', '[', ']',
                                  '.', ',', ';',
                                  '+', '-', '*', '/',
                                  '<', '>', '=',
                                  '~', '&', '|'
                                 };

void Analyzer::create_tokens(vchar list)
{
    for (std::vector<char>::iterator it = list.begin(); it != list.end(); ++it)
    {
        // Character isn't a space or a symbol, so it's the beginning of an identifier or keyword.
        if (!std::isspace(*it) && !is_char_symbol(*it))
        {
            // Find the end of the possible token. We might have extra symbols still attached at this point.
            for (std::vector<char>::iterator itr = it + 1; itr != list.end(); ++itr)
            {
                // End of the identifier or keyword is found at the next space or symbol.
                if (std::isspace(*itr) || is_char_symbol(*itr))
                {
                    // Creates a string from the characters found.
                    std::string lexemes(it, itr);

                    // Lexemes form keyword.
                    if (is_string_keyword(lexemes))
                    {
                        Token token(lexemes, Token::Type::KEYWORD);
                        tokens.push_back(token);
                    }
                    // Lexemes form identifier.
                    else
                    {
                        Token token(lexemes, Token::Type::IDENTIFIER);
                        tokens.push_back(token);
                    }

                    it = itr - 1;
                    break;
                }
            }
        }
        // Character is a symbol.
        else if (is_char_symbol(*it))
        {   
            // Create a string from the character found.
            std::string lexemes(1, *it);
            
            Token token(lexemes, Token::Type::SYMBOL);
            tokens.push_back(token);
        }
    }
}

bool Analyzer::is_char_symbol(char c)
{
    for (int i = 0; i < SYMBOLS_LENGTH; i++)
    {
        // The character given is one of the symbols.
        if (SYMBOLS[i] == c)
        {
            return true;
        }
    }

    return false;
}

bool Analyzer::is_string_keyword(std::string str)
{
    for (int i = 0; i < KEYWORDS_LENGTH; i++)
    {
        // The string given is one of the keywords.
        if (KEYWORDS[i] == str)
        {
            return true;
        }
    }

    return false;
}
