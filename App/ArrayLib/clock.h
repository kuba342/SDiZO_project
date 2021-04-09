#pragma once

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Clock{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
public:

    Clock();
    ~Clock();

    void startTime();
    void endTime();
    long long executionTime();
};

Clock::Clock(){

}

Clock::~Clock(){

}

void Clock::startTime(){
    start = high_resolution_clock::now();
}

void Clock::endTime(){
    end = high_resolution_clock::now();
}

long long Clock::executionTime(){
    return duration_cast<nanoseconds>(Clock::end - Clock::start).count();
}
