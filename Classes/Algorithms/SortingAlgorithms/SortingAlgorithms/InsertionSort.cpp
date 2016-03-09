#include "InsertionSort.hpp"
#include "Statistics.hpp"

#include <iostream>

InsertionSort::InsertionSort(std::vector<int> dataStorage)
        : dataStorage(dataStorage), timer("InsertionSortTimer"), sorted(false)
{
}

// Sorts the vector using the insertion method.
void InsertionSort::sort(bool debug)
{
    timer.start(); // Start the timer for the sort operation.
    sorted = false;

    int tempStorage; // Temporary storage for the data value currently being sorted.

    // Loops from the beginning of the vector to the end. Assumes that the first value, 0, is already sorted.
    for (unsigned long i = 1; i < dataStorage.size(); i++)
    {
        tempStorage = dataStorage[i]; // Assigns the current value to temporary storage.
        unsigned long j; // Create a value to control the second loop.

        // Loops from the end of the sorted values to the beginning of the vector, or until the position of the current value is known.
        for (j = i; j > 0 && dataStorage[j - 1] > tempStorage; j--)
        {
            dataStorage[j] = dataStorage[j - 1]; // Set the current sorted value to the previous value.
        }

        dataStorage[j] = tempStorage; // Set the final index found to the value being sorted.

        if(debug)
        {
            // Print the percentage of the sort completed.
            Statistics::printPercentage(i + 1, dataStorage.size(), "Insertion Sort");
        }
    }

    sorted = true;
    timer.stop(); // Stops the timer for the sort operation.
}

// Returns a human readable time that the sort took.
std::string InsertionSort::getElapsedTime()
{
    return Statistics::convertTime(timer.getElapsedTime());
}

std::vector<int>& InsertionSort::getSortedVector()
{
    if(!sorted)
    {
        std::cout << "WARNING: Vector not sorted before being returned." << std::endl;
    }

    return dataStorage;
}
