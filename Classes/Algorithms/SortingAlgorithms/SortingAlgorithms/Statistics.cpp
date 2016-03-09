#include <iostream>
#include <cmath>

#include "Statistics.hpp"

// Calculates and prints the percentage complete of an operation.
void Statistics::printPercentage(unsigned long index, unsigned long total, std::string operation)
{
    const unsigned long tenPercentTotal = total / 10; // Finds ten percent of the total available.

    // Tests if the index has completed a multiple of ten percent of the total.
    if(index % tenPercentTotal == 0)
    {
        /* Calculate the percentage completed so far.
        Multiply by 10 to achieve a nice number to report. Index diveded by ten percent will return 1 - 10.
        */
        unsigned long percentage = (index / tenPercentTotal) * 10;
        std::cout << operation << " " << percentage << "% complete." << std::endl;
    }
}

// Converts the time given in seconds into a string form more easily read.
std::string Statistics::convertTime(double totalSeconds)
{
    std::string time = ""; // String to hold the final values returned.
    int hours = (int)totalSeconds / 60 / 60; // Calculates the hours taken using integer division. 1 hour = 60 * 60 seconds.
    int minutes = (int)totalSeconds / 60; // Calculates the minutes taken using integer division. 1 minute = 60 seconds.
    double seconds = std::fmod(totalSeconds, 60); // Calculates the remaining seconds not reported by the hours and minutes.

    // Only sets the hours to be returned if it is 1 or greater.
    if(hours > 0)
    {
        time = std::to_string(hours); // Convert hours to a string and adds it to the current string.
        if(hours > 1) // Adds plural version if hours is greater than 1.
        {
            time += " hours, ";
        }
        else // Adds singular version if hours is only 1.
        {
            time += " hour, ";
        }
    }

    // Only sets the minutes to be rerturned if it is 1 or greater.
    if(minutes > 0)
    {
        time += std::to_string(minutes); // Convert minutes to a string and adds it to the current string.
        if(minutes > 1) // Adds plural version if minutes is greater than 1.
        {
            time += " minutes, ";
        }
        else // Adds singular version if minutes is only 1.
        {
            time += " minute, ";
        }
    }

    // Always report the number of seconds taken, even if it is 0.
    time += std::to_string(seconds);
    if(seconds == 1.0) // If exactly 1 second is taken, add the singular version to the current string.
    {
        time += " second";
    }
    else // Add the plural version whenever the seconds aren't exactly 1.
    {
        time += " seconds";
    }

    return time;
}
