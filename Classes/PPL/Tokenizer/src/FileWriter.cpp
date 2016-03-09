#include <fstream>
#include <iostream>

#include "FileWriter.hpp"

const std::string FileWriter::XML_ELEMENTS[] = {"<tokens>", "</tokens>",
                                                "<keyword>", "</keyword>",
                                                "<identifier>", "</identifier>",
                                                "<symbol>", "</symbol>"
                                               };

void FileWriter::create_xml(std::string path, vtoken tokens)
{
    std::ofstream file(path);

    // Exits if the file could not be opened.
    if (file.fail())
    {
        std::cerr << "ERROR: Unable to open file at '" << path << "'." << std::endl;
        std::exit(0x194);
    }

    // Writes "<tokens>" to file.
    file << XML_ELEMENTS[0] << std::endl;

    // Writes each token to file.
    for (vtoken::iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        if (it->get_type() == Token::Type::KEYWORD)
        {
            file << "\t" << XML_ELEMENTS[2] << " " << it->get_lexemes() << " " << XML_ELEMENTS[3] << std::endl;
        }
        else if (it->get_type() == Token::Type::IDENTIFIER)
        {
            file << "\t" << XML_ELEMENTS[4] << " " << it->get_lexemes() << " " << XML_ELEMENTS[5] << std::endl;
        }
        else if (it->get_type() == Token::Type::SYMBOL)
        {
            file << "\t" << XML_ELEMENTS[6] << " " << it->get_lexemes() << " " << XML_ELEMENTS[7] << std::endl;
        }
    }

    // Writes "</tokens>" to file.
    file << XML_ELEMENTS[1] << std::endl;

    file.close();
}
