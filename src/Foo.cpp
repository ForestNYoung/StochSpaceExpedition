#include <cmath>
#include <string>

using namespace std;

class Foo {
  private:
    float cooldown; // Gift cooldown
    bool ready; // If Foo is ready to give a gift
    int type; // 0 is for food, 1 is for fuel
    int amount; // Amount of gift

  public:
    Foo() {
      cooldown = 30; // 30 seconds
      ready = true; // Foo is originally ready
      type = rand() % 2; // Random gift
      amount = rand() % 15 + 5; // Random amount
    }
};