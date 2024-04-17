#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include "Timer.cpp"

using namespace std;

// FUNCTIONS
void stoch(); // Displays Stoch
void nominee(); // Displays Nominee
void groche(); // Displays Groche
void pluto(); // Displays map of Pluto

void eat(); // Eats food
void decay(); // Decays energy
void text(); // Prints location text
void stats(); // Prints statistics
void move(); // Move to new available location with all necessary updates
void buy(); // Buys item from Groche

int index(string location); // Returns the integer index of a location
void slow(string s); // Prints text slowly
void update(); // Updates available[]
bool check(string input); // Validates input
string purpose(string input); // Tells what the purpose of input is
float round10(float x); // Round to nearest tenth
void wait(); // Waits for enter

// GLOBAL VARIABLES
int location = 0; // 0 for Pluto Complex, 1 for Mini Carrot Farm, 2 for Pluto Vault, 3 for Sun Square, 4 for Fusion Reactor, 5 for Universe Edge, 6 for Dark Energy Harvester.
string names[7]; // Names for locations
string introduction[7]; // Introduction text for locations
bool available[7]; // available[] tells if a location is available to travel to
//bool giveable[]; // giveable[] tells if a command is valid to be given
float food = 20; // Tracks how much food Stoch has
float foodrate = 1; // Rate of Stoch consuming food
float energy = 0; // Tracks how much energy Stoch has
float energyrate = 0.5; // Exponential decay rate of energy
//int money = 0; // Tracks how much money Stoch has

Timer ft; // Food timer for eating
Timer et; // Energy timer for decaying
Timer mt; // Master timer for play time

bool victory; // If Stoch has beat the game

int main() {
  // VARIABLE DECLARATION
  names[0] = "Pluto";
  names[1] = "farm";
  names[2] = "vault";
  names[3] = "Sun";
  names[4] = "reactor";
  names[5] = "edge";
  names[6] = "harvester";
  introduction[0] = "Welcome to Pluto Complex.";
  introduction[1] = "Welcome to Mini Carrot Farm";
  introduction[2] = "Welcome to Pluto Vault.";
  introduction[3] = "Welcome to Sun Square";
  introduction[4] = "Welcome to Fusion Reactor.";
  introduction[5] = "Welcome to Universe Edge.";
  introduction[6] = "Welcome to Dark Energy Harvester.";
  for (int i = 0; i < 4; i++) available[i] = true;
  for (int i = 4; i < 7; i++) available[i] = false;

  ft = Timer();
  et = Timer();
  mt = Timer(); // Will never be stopped

  victory = false;
  
  // LOCAL VARIABLES
  string input; // User input
  // Possible valid inputs: stats, Pluto, Groche, vault, box, cabinet, safe, farm, replant, harvest, Sun, Foo, reactor, activate, collect, edge, Nominee, harvester, operate, harvest
  
  cout << "Welcome to Stoch's Space Expedition! Press enter to begin. If the text ever stops, just press enter! "; // Welcome message
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
  slow("There are three places: Groche's Public Gift Shop, the Mini Carrot Farm, and the Pluto Vault. Groche can sell you some food and a couple of high-tech spaceships. You know that the Mini Carrot Farm produces an abundant supply of delicious and nutritious mini carrots. The Vault contains many documents as well as money. Enter \"Groche\" to talk to Groche, enter \"farm\" to go to the Mini Carrot Farm, or enter \"vault\" to go to the Vault: \n\n\n");

  while (!victory) {
    slow(introduction[location]); // Print intro text
    cin >> input; // Get input
    while (!check(input)) { // Continuously check for invalid
      cout << "Invalid! ";
      cin >> input;
    }
    
  }
}

int index(string location) { // Returns location index (assuming it's real)
  for (int i = 0; i < 7; i++) {
    if (location == names[i]) return i;
  }
  return 12345;
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

bool check(string input) { // Checks if input is valid based on if a location is available
  string c = "stats, Pluto, Groche, vault, box, cabinet, safe, farm, replant, harvest, Sun, Foo, reactor, activate, collect, edge, Nominee, harvester, operate, harvest";
  string l = "Pluto, farm, vault, Sun, reactor, edge, harvester";
  if (names[location] == input) return false; // Stoch can't move to himself
  else if (c.find(input) != string::npos) { // Must be one of the valid commands
    if (l.find(input) != string::npos && available[index(l)]) { // If the input is a location and it's available, it's good
      return true;
    }
    // else if (l.find(input) == string::npos && ) { // If the input is NOT a location (command) and it's available, it's good
      
    // }
  }
}

string purpose(string input) { // Returns the purpose of an input
  string l = "Pluto farm vault Sun reactor edge harvester";
  if (input == "stats") return "stats"; // Stats have top priority
  else if (l.find(input) != string::npos) return "move " + input; // Move to any place
  else return input;
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