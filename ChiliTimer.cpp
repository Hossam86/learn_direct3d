#include "ChiliTimer.h"
#include <chrono>

ChiliTimer::ChiliTimer()
{
    last = std::chrono::steady_clock::now();
}

float ChiliTimer::Peek()
{
    return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}

float ChiliTimer::Mark()
{
    const auto old = last;
    last = std::chrono::steady_clock::now();
    const std::chrono::duration<float> frameTime = last - old;
    return frameTime.count();
}

ChiliTimer::~ChiliTimer() {}