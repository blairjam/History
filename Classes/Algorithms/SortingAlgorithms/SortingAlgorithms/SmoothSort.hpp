#ifndef SMOOTH_SORT_HPP
#define SMOOTH_SORT_HPP

#include <vector>
#include <string>

#include "Timer.hpp"

class SmoothSort
{
public:
    SmoothSort(std::vector<int> dataStorage);
    void sort();
    std::string getElapsedTime();
private:
    std::vector<int> dataStorage;
    Timer timer;

    bool isChildLarger(std::vector<int>::iterator first);

    std::vector<int>::iterator secondChild(std::vector<int>::iterator root);
    std::vector<int>::iterator firstChild(std::vector<int>::iterator root);
    std::vector<int>::iterator largerChild(std::vector<int> root, size_t size);

};

#endif
