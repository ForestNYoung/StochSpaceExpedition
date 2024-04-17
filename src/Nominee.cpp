#include <cmath>
#include <string>
#include <fstream>
#include "Timer.cpp"

using namespace std;

class Nominee {
  private:
    float cooldown; // Quote cooldown
    bool ready; // If Nominee is ready to say a quote
    int line; // Which quote Nominee will say
    string quote; // Quote
    ifstream iF; // Input file stream
    Timer timer; // Timer

  public:
    Nominee() {
      cooldown = 5; // 5 seconds
      ready = true; // Nominee is originally ready
      line = rand() % 15 + 1; // Random line number
      iF.open("Nominee'sWords.txt", ios::in); // Open iF
      if (iF.is_open()) for (int i = 1; i <= line; i++) getline(iF, quote); // Get quote
      timer = Timer(); // Initialize timer
    }
};