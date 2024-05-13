#include <cmath>
#include <string>

using namespace std;

class Spaceship {
  private:
    int type; // 0 is for Food Spaceship, 1 is for Fuel Spaceship
    float food; // Food stored in spaceship
    float fuel; // Fuel stored in spaceship
    float foodrate; // Food consumption rate
    float fuelrate; // Fuel consumption rate

  public:
    bool bought; // If Stoch has bought this spaceship

    Spaceship(int type) {
      this->type = type;
      bought = false; // Stoch has not bought the spaceship initially
      food = 0; // Default settings
      fuel = 0;
      foodrate = 1;
      fuelrate = 1;
      
      if (type == 0) {
        food += 10; // Bonus starting food
        foodrate *= 0.5; // Reduced 0.5 carrot per second
      }
      else {
        fuel += 20; // Bonus starting fuel
        fuelrate *= 0.8; // Reduced 0.8 joules per second
      }
    }
};