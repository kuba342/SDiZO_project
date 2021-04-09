#pragma once

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Clock1{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
public:

    Clock1();
    ~Clock1();

    void startTime();
    void endTime();
    long long executionTime();
};

Clock1::Clock1(){

}

Clock1::~Clock1(){

}

void Clock1::startTime(){
    start = high_resolution_clock::now();
}

void Clock1::endTime(){
    end = high_resolution_clock::now();
}

long long Clock1::executionTime(){
    return duration_cast<nanoseconds>(Clock1::end - Clock1::start).count();
}
