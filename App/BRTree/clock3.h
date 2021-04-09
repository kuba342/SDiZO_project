#pragma once

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Clock3{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
public:

    Clock3();
    ~Clock3();

    void startTime();
    void endTime();
    long long executionTime();
};

Clock3::Clock3(){

}

Clock3::~Clock3(){

}

void Clock3::startTime(){
    start = high_resolution_clock::now();
}

void Clock3::endTime(){
    end = high_resolution_clock::now();
}

long long Clock3::executionTime(){
    return duration_cast<nanoseconds>(Clock3::end - Clock3::start).count();
}
