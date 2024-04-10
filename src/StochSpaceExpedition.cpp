#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;

// FUNCTIONS
void slow(string s);
void stoch();
void nominee();
void groche();
void pluto();

void eat();
void decay();

bool check();
float round10(float x);
void wait();

// GLOBAL VARIABLES
int location = 0; // 0 for Pluto Complex, 1 for Mini Carrot Farm, 2 for Pluto Vault, 3 for Sun Square, 4 for Fusion Reactor, 5 for Universe Edge, 6 for Dark Energy Harvester.
string names[7]; // Names for locations
bool available[7]; // available[] tells if a location is available to travel to
float food = 20; // Tracks how much food Stoch has
float foodrate = 1; // Rate of Stoch consuming food
float energy = 0; // Tracks how much energy Stoch has
float energyrate = 0.5; // Exponential decay rate of energy
//int money = 0; // Tracks how much money Stoch has

int main() {
  // VARIABLE DECLARATION
  names[0] = "Pluto";
  names[1] = "farm";
  names[2] = "vault";
  names[3] = "Sun";
  names[4] = "Reactor";
  names[5] = "edge";
  names[6] = "harvester";
  for (int i = 0; i < 7; i++) available[i] = false;

  // LOCAL VARIABLES
  string input; // User input
  
  cout << "Welcome to Stoch's Space Expedition! Press enter to begin."; // Welcome message
  wait(); // Wait for enter

  // Story
  slow("\nHello! Your name is Stoch, and you're a little snowball currently living on Pluto.\n"); // Start message
  stoch(); // Print Stoch
  wait();

  slow("\nThere are many others like you and Pluto is a thriving planet with the universe's best technology. The Plutons live happily and peacefully together with the Sunns. The Sunns live on Sun and they also are happy. You, Stoch, are a math teacher at the well-known university Big Wheats! You're specialzed in calculus and carry a big metal integral around all day.\n");
  slow("However, your good friend Nominee (a Sunn) has snuck up and stole your integral! Nominee is a Sunn but he doesn't live on Sunn. He's actually infinitely big and he comprises of everything but the observable universe. You want your integral back but you can't find Nominee anywhere, so you decide to travel to the edge of the universe to find him. It's going to be a hard journey and you need to buy a spaceship prepared with enough food and energy to make it.\n\n");
  nominee();
  wait();
  
  slow("You're currently located at your home on Pluto in the luxurious Pluto Complex. Luckliy, your great friend Groche is here with you on Pluto. Groche is a HUGE snowball, and he's also a calculus master like you. Groche is the biggest Pluton and he has an integral just like yours but MUCH bigger. Groche can give you good advice and will always be available here in the Pluto Complex. Groche encourages you to visit him for tips and he might just sell some goodies in his gift shop.\n");
  groche();
  wait();
  
  slow("There's a map on the wall showing the major locations on Pluto. Enter \"map\" to pick up the map: ");
  cin >> input;
  while (input != "map") {
    cout << "Enter \"map\" to pick up the map: ";
    cin >> input;
  }
  pluto();
  slow("There are three places: Groche's Public Gift Shop, the Mini Carrot Farm, and the Pluto Vault. Groche can sell you some food and a couple of high-tech spaceships. You know that the Mini Carrot Farm produces an abundant supply of delicious and nutritious mini carrots. The Vault contains many documents as well as money. Enter \"Groche\" to talk to Groche, enter \"farm\" to go to the Mini Carrot Farm, or enter \"vault\" to go to the Vault: ");
}

void slow(string s) { // Print text slowly
  for (int i = 0; i < s.length(); i++) {
    cout << s[i] << flush;
    this_thread::sleep_for(chrono::milliseconds(20));
  }
};

void update() { // Makes available[] correct for a given current location
  if (location == 0) { // Pluto Complex
    available[1] = true; // Mini Carrot Farm
    available[2] = true; // Pluto Vault
    available[3] = true; // Sun Square
  }
  else if (location == 1 || location == 2) // Mini Carrot Farm or Pluto Vault
    available[0] = true; // Pluto Complex
  else if (location == 3) { // Sun Square
    available[0] = true; // Pluto Complex
    available[4] = true; // Fusion Reactor
    available[5] = true; // Universe Edge
  }
  else if (location == 4) // Fusion Reactor
    available[3] = true; // Sun Square
  else if (location == 5) { // Universe Edge
    available[3] = true; // Sun Square
    available[6] = true; // Dark Energy Harvester
  }
  else if (location == 6) // Dark Energy Harvester
    available[5] = true; // Universe Edge
};

void eat() {
  food -= foodrate;
}

void decay() {
  energy *= energyrate;
}

// GENERAL USEFUL FUNCTIONS

bool check() { // Checks if input is valid based on if a location is available
  string s = "Pluto farm vault Sun reactor edge harvester";
  return true;
}

float round10(float x) { // Method for rounding to nearest tenth
  return round(10 * x) / 10.0;
}

void wait() { // Detector for enter key press
  while (cin.get() != '\n');
}

// FUNCTIONS FOR MAPS AND IMAGES

void stoch() {
  cout << "░░░░░░░░░░░░░░██████████████░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░████████░░░░░░░░░░░░██████░░░░░░░" << endl;
  cout << "░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░█████░░░" << endl;
  cout << "░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░" << endl;
  cout << "░░███░░░░░░░░█░░░░░░░░░░█░░░░░░░░░░░░█░░" << endl;
  cout << "░░██░░░░░░░░░░░░░░░░░░░░░░███████░░░░░█░" << endl;
  cout << "░██░░░░░░░░░░░░░░░░░██████░░░░██░░░░░░██" << endl;
  cout << "░█░░░░░░░░░░░░░░░░███░░░░░████░░░░░░░░░█" << endl;
  cout << "░█░░░░░░░░░░░░░░░░████████░░░░░██░░░░░░█" << endl;
  cout << "░█░░░██░░░█░░░░░░░░░░░░░░░░██░░██░░░░░░█" << endl;
  cout << "░██░░██░░██░░░░░░░░░░░░░░░░░██░░░░░░░███" << endl;
  cout << "░░█░░░░░███░░░░░░░░░░░░░░░██████░░░░███░" << endl;
  cout << "░░██░░░██░█████░░░░░░░░░██░░░░░█░░░░██░░" << endl;
  cout << "░░░█░░░░░░░░░░███████████░░░░░░░░░░██░░░" << endl;
  cout << "░░░░█████░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░" << endl;
  cout << "░░░░░░░░██████████████████████████░░░░░░" << endl;
};

void nominee() {
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░██░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░█████░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░██░░███░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░█░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░██████░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░█████░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░██░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░███░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░██░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░█░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░███░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░███░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░" << endl;
};

void groche() {
  cout << "░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░██░░█░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░█░░░███░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░█░░░░░░░███░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░█░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░█░░░█░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░█░░░░███████░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░█░░░░░░░░░░███░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░█░░░░███░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░██░░░░░█████░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░██░░░███░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░█░░░░░░██████░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░" << endl;
};

void pluto() {
  cout << "░░░████████████████████████████████████████████████░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░█░█░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░█░█░░░░██░░░█░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░█░░███░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒█░░░░░█░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒░██░░█░░██░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒░░█░░░░░█░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒░░░█░░░█░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░█████░░▒▒▒▒░░░░░░░░░░░█░█░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░██░░░░░██░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░█░░░░██░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░█░░░░█░░█░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░██░░░░███░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░█░░░░█░░░░░░█░░░░░░░░░████████████░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░█░░░█░░░░░█░░░░░░░░░█░░░░░░░░░░░░█░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░██░░░░░██░░░░░░░░░░░░██████████░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░█████░░░░░░░░░░░░█░█░░░░░░░░█░█░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░▒▒▒▒▒░░░░░░░░░░░░█░░░░░░░░█░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░▒▒▒▒▒░░░░░░░░░░░░░█░█░░░░░░░░█░█░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░▒▒▒░░░░░░░░░░░░░░░░░░░█░░░░░██░█░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░▒▒▒▒░░░░░░░░░░▒▒▒▒▒█░█░░░░░░░░█░█░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░▒▒▒▒▒▒▒▒▒▒░░▒▒░▒▒░░░█░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒░░█░█░░░░░░░░█░█░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░▒▒▒▒▒░░░░░██████████░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░████████████████████████████████████████████████░░░" << endl;
};