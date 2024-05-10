#include <cmath>
#include <string>
#include "Timer.h"

using namespace std;

class DarkEnergyHarvester { // Note: Stoch must supervise the DarkEnergyHarvester generating energy and can not leave.
  private:
    float energy; // Current detected energy
    float rate; // Linear decay rate of dark energy
    int state; // 0 is for not running, 1 is for running, 2 is for running with detected energy
    Timer timer; // Timer for linear energy decay

  public:
    DarkEnergyHarvester() {
      energy = 0; // Originally empty
      rate = 5; // Dark energy decays 5 joules every second (Dark energy is generated instantaneously)
      state = 0; // Originally not running
      timer = Timer(); // Initialize timer
    }
};