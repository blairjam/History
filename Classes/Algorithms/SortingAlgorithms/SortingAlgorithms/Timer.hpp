#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>
#include <chrono>
#include <string>

class Timer
{
public:
    Timer(std::string name = "Default_Timer");
    void start();
    void stop();
    double getElapsedTime();

private:
    bool running;
    bool hasRun;
    std::string name;
    std::chrono::steady_clock::time_point timeStart;
    std::chrono::steady_clock::time_point timeStop;
    std::chrono::duration<double> elapsedTime;
};

#endif
