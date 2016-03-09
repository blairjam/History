#include <iostream>
#include <fstream>

#include "FileInput.hpp"

void FileInput::read_chars(std::string path)
{
    // File to open and read from.
    std::ifstream file(path);

    // Exits if the file could not be opened.
    if (file.fail())
    {
        std::cerr << "ERROR: Unable to open file at '" << path << "'." << std::endl;
        std::exit(0x194);
    }

    char next_character;

    // Loops through the characters of the file one by one.
    while (file.get(next_character))
    {
        characters.push_back(next_character);
    }

    file.close();
}
