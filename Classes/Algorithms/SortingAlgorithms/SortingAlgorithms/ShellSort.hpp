#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <vector>
#include <string>

#include "Timer.hpp"

class ShellSort
{
public:
    ShellSort(std::vector<int> dataStorage);
    void sort();
    std::string getElapsedTime();

private:
    std::vector<int> dataStorage;
    std::vector<unsigned long> gaps;
    Timer timer;

    void calculateGaps();
};

#endif