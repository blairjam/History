#ifndef FILE_WRITER_HPP
#define FILE_WRITER_HPP

#include <string>
#include <vector>

#include "Token.hpp"

typedef std::vector<Token> vtoken;

class FileWriter
{
    public:
        static const std::string XML_ELEMENTS[];

        FileWriter(){}
        ~FileWriter(){}
        void create_xml(std::string path, vtoken tokens);
};  

#endif
