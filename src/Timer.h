#define TIMER_H
#pragma once

#include <chrono>

using namespace std;

class Timer {
  private:
    chrono::steady_clock::time_point start_time; // Start time

  public:
    Timer() {
      start_time = chrono::steady_clock::now(); // Setting the start time to when the Timer got initialized
    }

    void start() {
      start_time = chrono::steady_clock::now(); // Set start time to now
    }

    float elapsed() { // Returns how many seconds have passed since start_time
      return chrono::duration_cast<chrono::duration<float>>(chrono::steady_clock::now() - start_time).count(); // How many seconds have passed since start_time
    }
};