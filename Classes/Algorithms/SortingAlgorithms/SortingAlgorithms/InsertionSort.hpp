#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
#include <string>

#include "Timer.hpp"

class InsertionSort
{
public:
    InsertionSort(std::vector<int> dataStorage);
    void sort(bool debug = true);
    std::string getElapsedTime();
    std::vector<int>& getSortedVector();
private:
    std::vector<int> dataStorage;
    Timer timer;
    bool sorted;
};

#endif
