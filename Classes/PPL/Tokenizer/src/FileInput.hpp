#ifndef FILE_INPUT_HPP
#define FILE_INPUT_HPP

#include <string>
#include <vector>

typedef std::vector<char> vchar;

class FileInput
{
    public:
        FileInput(){}
        ~FileInput(){}
        void read_chars(std::string path);
        vchar get_chars() const {return characters;}

    private:
        vchar characters;
};

#endif
