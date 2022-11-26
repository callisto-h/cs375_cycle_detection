#ifndef TIMER_H
#define TIMER_H

#include <chrono>

//function to start timer
std::chrono::time_point<std::chrono::system_clock> start_timer(){
    return std::chrono::system_clock::now();
}

//function to end timer
double end_timer(std::chrono::time_point<std::chrono::system_clock> start){
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count();
}

#endif