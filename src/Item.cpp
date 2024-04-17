#include <cmath>
#include <string>

using namespace std;

class Item {
  private: // Variables
    float cost; // Cost of item
    string name; // Name of item
    bool obtained; // Whether Stoch has obtained the item

  public:
    Item(float cost, string name) {
      this->cost = cost;
      this->name = name;
      obtained = false;
    }
};