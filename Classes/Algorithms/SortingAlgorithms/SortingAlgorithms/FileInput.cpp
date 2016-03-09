#include <iostream>
#include <fstream>

#include "FileInput.hpp"
#include "Statistics.hpp"

FileInput::FileInput(std::string path, unsigned long data_points)
        : path(path), DATA_POINTS(data_points)
{
}

// Public wrapper for resizing and populating the vector member of the class.
std::vector<int> FileInput::toVector()
{
    resizeVector(DATA_POINTS);
    populateVector();
    return fileVector;
}

// Resize the vector for input of data. Exits if allocation cannot be completed.
void FileInput::resizeVector(unsigned long spaces)
{
    try
    {
        fileVector.resize(spaces);
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "ERROR: Unable to resize vector for storage of " << spaces << " data points." << std::endl;
        std::exit(9);
    }
}

/* Read from the file at the given path and input the data into the vector member of the class.
   Exits if the file cannot be opened.
 */
void FileInput::populateVector()
{
    // Create a file to be opened based on the path given initially.
    std::ifstream file(path);

    // Exit the program if the file cannot be opened.
    if (file.fail())
    {
        std::cerr << "ERROR: Unable to open file at '" << path << "'." << std::endl;
        std::exit(8);
    }

    std::cout << "Reading from file at '" << path << "'." << std::endl;

    // Take the data given and input it into the vector member.
    for (unsigned long i = 0; i < DATA_POINTS; i++)
    {
        if(file >> fileVector.at(i))
        {
            Statistics::printPercentage(i + 1, DATA_POINTS, "Reading data from file");
        }
        else
        {
            std::cerr << "ERROR: The data file given does not contain enough data points." << std::endl;
            std::cerr << "Stopping file input. Resizing vector to " << i << " data points." << std::endl;
            resizeVector(i);
            break;
        }
    }

    file.close();
}
