#pragma once

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Clock2{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
public:

    Clock2();
    ~Clock2();

    void startTime();
    void endTime();
    long long executionTime();
};

Clock2::Clock2(){

}

Clock2::~Clock2(){

}

void Clock2::startTime(){
    start = high_resolution_clock::now();
}

void Clock2::endTime(){
    end = high_resolution_clock::now();
}

long long Clock2::executionTime(){
    return duration_cast<nanoseconds>(Clock2::end - Clock2::start).count();
}
