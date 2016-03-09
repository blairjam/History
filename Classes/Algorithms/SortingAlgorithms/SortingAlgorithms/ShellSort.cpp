#include <iostream>

#include "ShellSort.hpp"
#include "Statistics.hpp"
#include "InsertionSort.hpp"

ShellSort::ShellSort(std::vector<int> dataStorage)
        : dataStorage(dataStorage), timer("ShellSortTimer")
{
}

void ShellSort::sort()
{
    timer.start();

    calculateGaps();

    for (unsigned long i = gaps.size(), a = 0; i-- > 0; a++)
    {
        for(unsigned long k = 0; k < gaps[i]; k++)
        {
            std::vector<int> toSort;
            for(unsigned long j = k; j < dataStorage.size(); j += gaps[i])
            {
                toSort.push_back(dataStorage[j]);
            }

            InsertionSort insertion(toSort);
            insertion.sort(false);
            toSort = insertion.getSortedVector();

            for(unsigned long j = k, l = 0; j < dataStorage.size(); j += gaps[i], l++)
            {
                dataStorage[j] = toSort[l];
            }
        }
        // Prints out when sort is 100% done. Minor hack to keep from printing 10% - 110%.
        Statistics::printPercentage((a + 1) * 10 , gaps.size() * 10, "Shell Sort");
    }

    timer.stop();
}

std::string ShellSort::getElapsedTime()
{
    return Statistics::convertTime(timer.getElapsedTime());
}

// Find the beginning gap to start the sort with.
void ShellSort::calculateGaps()
{
    unsigned long nextGap; // The next gap to be calculated.

    /* Loops while the gap doesn't increase above one third of the total storage size.
       Calculates the next gap with the formula x = 3x + 1.
     */
    for (nextGap = 1; nextGap <= dataStorage.size() / 3; nextGap = (nextGap * 3) + 1)
    {
        // Only sets the gap to the next gap once it is known to be less than one third of the storage size.
        gaps.push_back(nextGap);
    }
}
