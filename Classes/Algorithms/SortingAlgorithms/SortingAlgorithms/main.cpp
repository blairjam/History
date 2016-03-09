#include <vector>
#include <iostream>
#include <string>

#include "FileInput.hpp"
#include "InsertionSort.hpp"
#include "ShellSort.hpp"
#include "SmoothSort.hpp"

std::string obtainFilePath();

int main()
{
    FileInput file(obtainFilePath(), 500000ul); // Create a new FileInput object to get data from a file.

    /* Store the data found in the dataStorage vector. Use this when calling your sorting algorithms.
       Copy it inside the constructor to a local class member. AKA: Don't modify this one, everyone will need it.
     */
    const std::vector<int> dataStorage = file.toVector();

    std::cout << std::endl; // Formatting for output.

    InsertionSort insertion(dataStorage);
    insertion.sort();
    std::cout << "Insertion Sort took " << insertion.getElapsedTime() << std::endl << std::endl;

    ShellSort shell(dataStorage);
    shell.sort();
    std::cout << "Shell Sort took " << shell.getElapsedTime() << std::endl << std::endl;

    return 0;
}

std::string obtainFilePath()
{
    std::string path;
    std::cout << "Enter the path at which the data file is located:" << std::endl;
    std::getline(std::cin, path);
    return path;
}
