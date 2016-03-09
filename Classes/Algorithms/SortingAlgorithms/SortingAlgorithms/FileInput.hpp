#ifndef FILE_INPUT_HPP
#define FILE_INPUT_HPP

#include <string>
#include <vector>

class FileInput
{
private:
    std::string path; // The path where the data file is located.
    const unsigned long DATA_POINTS; // The total amount of numbers to be sorted.
    std::vector<int> fileVector; // Vector to hold the data found at 'path'.

    void resizeVector(unsigned long spaces);
    void populateVector();
public:
    FileInput(std::string path, unsigned long data_points);
    std::vector<int> toVector();
};

#endif
