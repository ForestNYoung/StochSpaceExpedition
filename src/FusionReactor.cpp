#include <cmath>
#include <string>

using namespace std;

class FusionReactor { // Note: Stoch must supervise the FusionReactor generating energy and can not leave.
  private:
    float energy; // Current energy stored
    float rate; // Reactor generation rate based on time
    int state; // 0 is for not running, 1 is for running

  public:
    FusionReactor() {
      energy = 0; // Originally empty
      rate = 0.1; // Function: E = 0.1t^2
      state = 0; // Originally not running
    }
};