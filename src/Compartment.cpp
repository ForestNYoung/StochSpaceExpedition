#include <cmath>
#include <string>

using namespace std;

class Compartment {
  private: // Variables
    float money; // Amount of money in the compartment
    int type; // 0 is for Box, 1 is for Cabinet, 2 is for Safe
    float time; // Time to search a compartment

  public:
    Compartment() {
      type = rand() % 3; // Random type

      money = rand() % 10;
      time = 3;
      for (int i = 0; i < type; i++) {
        money *= 2;
        time *= 1.5;
      }
    }
};