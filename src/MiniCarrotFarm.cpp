#include <cmath>
#include <string>
#include "Timer.cpp"

using namespace std;

class MiniCarrotFarm { // Note: MiniCarrotFarm can passively grow without Stoch supervision
  private:
    float carrots; // How many carrots the farm has
    float rate; // Farm growing rate based on time
    float capacity; // Maximum carrot capacity
    int state; // 0 is for empty, 1 for growing, 2 for ready
    Timer timer; // Timer

  public:
    MiniCarrotFarm() {
      carrots = 0; // Originally empty
      rate = 0.2; // 1 carrot every 5 seconds (Food is generated linearly)
      capacity = 20; // Maximum 20 carrots
      state = 0; // Originally empty
      timer = Timer(); // Initialize timer
    }
};