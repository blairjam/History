#include <iostream>

#include "Cleaner.hpp"

void Cleaner::remove_comments()
{
    int size = list.size();

    // Loop across all characters looking for beginning of a comment.
    for (int i = 0; i < size; i++)
    {
        // Beginning of a comment is found.
        if (list.at(i) == '/')
        {
            // Comment start isn't last character in list.
            if (i + 1 < size)
            {
                // Comment is single line.
                if (list.at(i + 1) == '/')
                {
                    i = remove_single_line(i);
                }
                // Comment is multi line.
                else if (list.at(i + 1) == '*')
                {
                    i = remove_multi_line(i);
                }
                // Comment is only single '/', which is an error.
                else
                {
                    std::cerr << "Error: Found '/' at character '" << i << "' and expected '//' or '/*'." << std::endl;
                    std::exit(0x3A);
                }
            }
            // Comment start is last character, which is an error.
            else
            {
                std::cerr << "Error: Found '/' at last character and expected '//' or '/*'." << std::endl;
                std::exit(0x3A);
            }
        }
    }
}

// Removes a single line comment starting with the given character location. 
// Returns the location with which to continue iterations.
int Cleaner::remove_single_line(int current_char)
{
    int size = list.size();

    // The end location of the comment. Will be used to continue iterations in the main loop.
    int end_location = 0;

    // Comment will have an end to it.
    if (current_char + 2 < size)
    {
        // We know 'current_char' and 'current_char' + 1 are both '/', so start at 'current_char' + 2.
        // Searching for end of comment.
        for (int i = current_char + 2; i < size; i++)
        {
            // End of a single line comment is found.
            if (list.at(i) == '\n')
            {
                replace_comment(current_char, i + 1);
                end_location = i;
                break;
            }
            // Comment doesn't have an end. The rest of the file is commented out.
            else if (i + 1 == size)
            {
                replace_comment(current_char, size);
                end_location = size - 1;
            }
        }
    }
    // Comment is last two characters of file.
    else
    {
        replace_comment(current_char, current_char + 2);
        end_location = current_char + 1;
    }

    return end_location;
}

// Removes a multi line comment starting with the given character location. 
// Returns the location with which to continue iterations.
int Cleaner::remove_multi_line(int current_char)
{
    int size = list.size();

    // The end location of the comment. Will be used to continue iterations in the main loop.
    int end_location = 0;

    // Comment will have an end to it.
    if (current_char + 2 < size)
    {
        // We know 'current_char' and 'current_char' + 1 are both '/', so start at 'current_char' + 2.
        // Searching for end of comment.
        for (int j = current_char + 2; j < size; j++)
        {
            // Asterisk found. Might be the end of the comment.
            if (list.at(j) == '*')
            {
                // Comment might have an end now.
                if (j + 1 < size)
                {
                    if (list.at(j + 1) == '/')
                    {
                        replace_comment(current_char, j + 2);
                        end_location = j + 1;
                        break;
                    }
                }
                // Last character will be commented out no matter what.
                else
                {
                    replace_comment(current_char, j + 1);
                    end_location = j;
                }
            }
            // Comment doesn't have an end. The rest of the file is commented out.
            else if (j + 1 == size)
            {
                replace_comment(current_char, size);
                end_location = size - 1;
            }
        }
    }
    // Comment is last two characters of line.
    else
    {
        replace_comment(current_char, current_char + 1);
        end_location = current_char;
    }
    
    return end_location;
}

// Replaces the characters within the given range with spaces. Whitespace will be ignored when tokenizing.
void Cleaner::replace_comment(int trim_start, int trim_end)
{
    for (int i = trim_start; i < trim_end; i++)
    {
        list.at(i) = ' ';
    }
}
