#include <cmath>
#include <string>
#include <fstream>
#include "Timer.h"

using namespace std;

class Groche {
  private:
    float cooldown; // Advice cooldown
    bool ready; // If Groche is ready to give advice
    int line; // Which advice Groche will give
    string advice; // Advice
    ifstream iF; // Input file stream
    Timer timer; // Timer

  public:
    Groche() {
      cooldown = 20; // 20 seconds
      ready = true; // Groche is originally ready
      line = rand() % 15 + 1; // Random line number
      iF.open("Groche'sAdvice.txt", ios::in); // Open iF
      if (iF.is_open()) for (int i = 1; i <= line; i++) getline(iF, advice); // Get advice
      timer = Timer(); // Initialize timer
    }
};