#pragma once 
#include <chrono>
class ChiliTimer
{
private:
    /* data */
public:
    ChiliTimer(/* args */);
    ~ChiliTimer();
    float Mark();
    float Peek();

private:
    std::chrono::steady_clock::time_point last;
};
