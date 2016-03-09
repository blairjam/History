/* James Blair
 * 2/27/15
 * Tokenizer
 */
 
#include <iostream>
#include <vector>

#include "FileInput.hpp"
#include "Cleaner.hpp"
#include "Analyzer.hpp"
#include "FileWriter.hpp"

int main()
{
    // Reads in characters from the source file.
    FileInput file_input;
    file_input.read_chars("../src/Main.jack");

    // Removes comments from the source file.
    Cleaner cleaner(file_input.get_chars());
    cleaner.remove_comments();

    // Creates tokens from the remaining words in the source file.
    Analyzer analyzer;
    analyzer.create_tokens(cleaner.get_list());

    // Writes the tokens to a file.
    FileWriter file_writer;
    file_writer.create_xml("../src/MainT.xml", analyzer.get_tokens());
}
