/* HOW TO USE THE TIMER:
   1. Create a new object of type Timer.                                Ex: Timer timer1;
   2. Start the timer before calling your functions.                    Ex: timer1.start(); runMyFunction();
   3. Stop the timer after your function has completed.                 Ex: runMyFunction(); timer1.stop();
   4. Store or output the time taken. Time taken is given as a double.  Ex: double time = timer1.getElapsedTime();
   5. Timer can now be reused or forgotten.
 */

#include <iostream>

#include "Timer.hpp"

// Create a new timer with the name specified. Defaults to 'Default_Timer'.
Timer::Timer(std::string name)
    :running(false), hasRun(false), name(name)
{
}

// Starts the timer.
void Timer::start()
{
    if(!running) // Check that the timer is stopped.
    {
        timeStart = std::chrono::steady_clock::now(); // Set the start time to the current time.
        hasRun = false;
        running = true;
    }
    else
    {
        std::cerr << "ERROR: Timer '" << name << "' is already running." << std::endl;
    }
}

// Stops the timer.
void Timer::stop()
{
    if(running) // Checks that the timer is running.
    {
        timeStop = std::chrono::steady_clock::now(); // Sets the stop time to the current time.
        hasRun = true;
        running = false;
    }
    else
    {
        std::cerr << "ERROR: Timer '" << name << "' is not running." << std::endl;
    }
}

// Returns the time in seconds as a string.
double Timer::getElapsedTime()
{
    /* Finds the elapsed time by subtracting the start time from the stop time and casting to double.
       Both timeStart and timeStop are type steady_clock::time_point.
       The duration_cast<> to duration<double> converts the difference of the two times.
     */
    if(hasRun) // Calculate the time run only if the timer has run.
    {
        elapsedTime = std::chrono::duration_cast<std::chrono::duration<double>> (timeStop - timeStart);
        return elapsedTime.count(); // Returns the value of time elapsed as a double.
    }
    else // Return 0 if the timer has not run yet.
    {
        return 0.0;
    }
}
