#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include <string>

class Statistics
{
public:
    static void printPercentage(unsigned long index, unsigned long total, std::string operation);
    static std::string convertTime(double totalSeconds);
};

#endif
