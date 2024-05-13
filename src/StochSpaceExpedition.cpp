#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
class Timer;
#include "Spaceship.cpp"
#include "Compartment.cpp"
#include "MiniCarrotFarm.cpp"
#include "FusionReactor.cpp"
#include "Item.cpp"

using namespace std;

// FUNCTIONS

// Specialized functions
void eat(); // Eats food
void decay(); // Decays energy
string text(); // Prints location text
void stats(); // Prints statistics
void move(int destination); // Move and update
void buy(Item product); // Buys item

// General functions
void manage(string input); // Manages input
int purpose(string input); // Returns input purpose
int index(string location); // Returns integer index of location
void slow(string s); // Prints text slowly
void update(); // Updates available[]
bool valid(string input); // Validates input
float round10(float x); // Round to nearest tenth
void wait(); // Waits for enter
void story(); // Prints story

// Image functions
void stoch(); // Displays Stoch
void foo(); // Displays Foo
void groche(); // Displays Groche
void nominee(); // Displays Nominee
void pluto(); // Displays map of Pluto
void sun(); // Displays map of Sun

// GLOBAL VARIABLES

int location = 0; // 0 - Pluto Complex, 1 - Mini Carrot Farm, 2 - Pluto Vault, 3 - Sun Square, 4 - Fusion Reactor, 5 - Universe Edge, 6 - Dark Energy Harvester
string locations[7] = {"Pluto", "farm", "vault", "Sun", "reactor", "edge", "harvester"}; // All possible locations
string names[7] = {"Pluto Complex", "Mini Carrot Farm", "Pluto Vault", "Sun Square", "Fusion Reactor", "Universe Edge", "Dark Energy Harvester"}; // Formal location names
string commands[12] = {"Groche", "box", "cabinet", "safe", "replant", "gather", "Foo", "activate", "collect", "Nominee", "operate", "harvest"}; // All possible commands
int place[12] = {0, 2, 2, 2, 1, 1, 3, 4, 4, 5, 6, 6}; // Locations where a command can be called
string items[6] = {"FoodSpaceship", "FuelSpaceship", "Carrot", "MiniCarrotFarmRateUpgrader", "MiniCarrotFarmCapacityUpgrader", "FusionReactorRateUpgrader"}; // All possible items
bool available[7] = {false, true, true, true, false, false, false}; // Tells if a location is available to travel to
float food = 20; // Tracks how much food Stoch has
float foodrate = 1; // Rate of Stoch consuming food
float energy = 0; // Tracks how much energy Stoch has
float energyrate = 0.5; // Exponential decay rate of energy
int money = 0; // Tracks how much money Stoch has

Timer ft(); // Food timer for eating
Timer et(); // Energy timer for decaying
Timer mt(); // Master timer for play time

Spaceship FoodS(0); // Food spaceship
Spaceship FuelS(1); // Fuel spaceship

MiniCarrotFarm mcf(); // Mini Carrot Farm

Item FoodSpaceship(100, "Food Spaceship");
Item FuelSpaceship(100, "Fuel Spaceship");
Item Carrot(1, "Carrot");
Item MiniCarrotFarmRateUpgrader(30, "Mini Carrot Farm Rate Upgrader");
Item MiniCarrotFarmCapacityUpgrader(25, "Mini Carrot Farm Capacity Upgrader");
Item FusionReactorRateUpgrader(40, "Fusion Reactor Rate Upgrader");

bool victory = false; // If Stoch has beat the game

int main() {
  // LOCAL VARIABLES
  string input; // User input
  
  cout << "Welcome to Stoch's Space Expedition! Press enter to begin. If the text ever stops, just press enter! "; // Welcome message
  wait(); // Wait for enter

  // Story
  //story();

  // MAIN GAME LOOP
  while (!victory) {
    slow(text()); // Print intro text
    update(); // Update available[]
    cin >> input; // Get input
    while (!valid(input)) { // Continuously check until input is valid
      cout << "Invalid input!\n\n";
      cout << text();
      cin >> input;
    }
    manage(input); // Manage the input
  }
}

// Specific functions

void eat() {
  food -= foodrate;
}

void decay() {
  energy *= energyrate;
}

string text() { // Prints introduction text for a location
  if (location == 0) return "You're at the Pluto Complex. Enter \"Groche\" to talk to Groche, enter \"farm\" to go to the Mini Carrot Farm, enter \"vault\" to go to the Pluto Vault, enter \"Sun\" to travel to Sun, and enter any item name to buy it from Groche's Gift Shop. ";
  else if (location == 1) return "You're at the Mini Carrot Farm. Enter \"replant\" to replant carrots, enter \"gather\" to gather carrots, and enter \"Pluto\" to go to the Pluto Complex. ";
  else if (location == 2) return "You're at the Pluto Vault. Enter \"box\" to search a box, enter \"cabinet\" to search a cabinet, enter \"safe\" to search a safe, and enter \"Pluto\" to go to the Pluto Complex. ";
  else if (location == 3) return "You're at the Sun Square. Enter \"Foo\" to talk to Foo, enter \"reactor\" to go to the Fusion Reactor, enter \"edge\" to travel to the Universe Edge if you have enough resources, and enter \"Pluto\" to go to the Pluto Complex. ";
  else if (location == 4) return "You're at the Fusion Reactor. Enter \"activate\" to activate the reactor, enter \"collect\" to collect energy, and enter \"Sun\" to go to Sun Square. ";
  else if (location == 5) return "You're at Universe Edge. ";
  return "You're at Dark Energy Harvester. ";
}

void stats() { // Prints statistics
  slow("\nHere are your stats!\n");
  cout << "Food: " + to_string(int(food)) + " carrots\n";
  cout << "Energy: " + to_string(int(energy)) + " J\n";
  cout << "Money: $" + to_string(int(money)) + "\n\n";
  //cout << "Time played: " << to_string(int(mt.elapsed()));
}

void move(int destination) { // Moves Stoch to another location
  update(); // Update available[]
  if (available[destination]) { // If the destination is available
    location = destination; // Move
    update(); // Update available[]
  }
  else cout << "You can't go to " + names[destination] + " from " + names[location] + "!";
}

void buy(Item product) {
  
}

// General functions

void manage(string input) {
  if (purpose(input) == 0) stats(); // Stats
  else if (purpose(input) == 1) move(index(input)); // Move
  else if (purpose(input) == 2) { // Interact
    if (location != place[index(input) - 100]) cout << "The command \"" + input + "\" can not be called at " + names[location] + "!\n\n";
    else { // Valid interaction command
      
    }
  }
  else { // Buy
    
  }
}

int purpose(string input) { // Returns an integer, assuming input is valid
  if (input == "stats") return 0; // 0 for stats
  else if (index(input) <= 6) return 1; // 1 for move
  else if (index(input) <= 112) return 2; // 2 for interact
  else return 3; // 3 for buy
}

int index(string input) { // Returns location or command index from respective arrays
  for (int i = 0; i < 7; i++) {
    if (input == locations[i]) return i; // Location is number from 0 to 6
  }
  for (int i = 0; i < 12; i++) {
    if (input == commands[i]) return i + 100; // Command is number from 100 to 112
  }
  return 999;
}

void slow(string s) { // Print text slowly
  for (int i = 0; i < s.length(); i++) {
    cout << s[i] << flush;
    this_thread::sleep_for(chrono::milliseconds(20));
  }
}

void update() { // Makes available[] correct for a given current location
  for (int i = 0; i < 7; i++) available[i] = false; // First set all locations to false
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

  if (!FoodS.bought && !FuelS.bought) { // If none of the spaceships are bought
    available[5] = false; // Universe Edge
    available[6] = false; // Dark Energy Harverster
  }
}

bool valid(string input) { // Checks if input is valid based on if it is a valid location or command
  for (int i = 0; i < 7; i++) if (input == locations[i]) return true;
  for (int i = 0; i < 12; i++) if (input == commands[i]) return true;
  for (int i = 0; i < 6; i++) if (input == items[i]) return true;
  return false;
}

float round10(float x) { // Method for rounding to nearest tenth
  return round(10 * x) / 10.0;
}

void wait() { // Detector for enter key press
  while (cin.get() != '\n');
}

void story() { // Prints story
  string input;
  
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
}

// Image functions

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

void foo() {
  cout << "░░░░░░░░░░░░████████████████░░░░░░░░░░░░" << endl;
  cout << "░░░░░░░██████░░░░░░░░░░░░░░███████░░░░░░" << endl;
  cout << "░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░████░░░" << endl;
  cout << "░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░" << endl;
  cout << "░░██░░░░░░░░░█░░░░░░░░░░█░░░░░██░░░░░██░" << endl;
  cout << "░██░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░██" << endl;
  cout << "███░░░░░░░░░░░░░░░░░░█████████░░█░░░░░░█" << endl;
  cout << "██░░░░░░░░░░░░░░░█████░░░█░░░████░░░░░░█" << endl;
  cout << "██░░░░░░░░░░░░░░░███░█░███████░░░░░░░░░█" << endl;
  cout << "██░██░░░█░░░░░░░░░░█████░░░░░░░░░░██░░░█" << endl;
  cout << "██░██░░█░░░░░░░░░░░░░░░░░░░░░░░█░░██░░██" << endl;
  cout << "██░░░░████░░░░░░░░░░░░░░░░░░░░███░░░░██░" << endl;
  cout << "███░░█░░░██░░░░░░░░░░░░░░░░████░░█░░░█░░" << endl;
  cout << "░███░░░░░░░████████████████░░░░░░░░░██░░" << endl;
  cout << "░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░" << endl;
  cout << "░░░░░░████████████████████████████░░░░░░" << endl;
}

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

void sun() {
  cout << "░░░████████████████████████████████████████████████░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░▒░░░░░░░░░░░░░░░░░░░░░░░██████████░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░█░░█░░░" << endl;
  cout << "░░░█░░░▒░░░░▒░░░░░░░░░░░░░░░░░░░░░░░░░█░░████░░█░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░▒░░░░░░░░░░░░░░░░░░░░█░██░░░█░█░░█░░░" << endl;
  cout << "░░░█░░░░░▒░░░░▒░░░░░░░░░░░░░░░░░░░░░░░█░░█░░░░░█░░█░░░" << endl;
  cout << "░░░█░░░▒░░▒░░▒░░░▒░▒░░░░░░░░░░░░░░░░░░█░░░██░░░█░░█░░░" << endl;
  cout << "░░░█░█████████████████░░░░░░░░░░░░░░░░█░░░░░█░░█░░█░░░" << endl;
  cout << "░░░█░██░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░█░█░░░██░█░░█░░░" << endl;
  cout << "░░░█░░██░░░░░░░░░░░██░░░░░░░▒▒▒▒▒▒▒▒▒░█░░████░░█░░█░░░" << endl;
  cout << "░░░█░░░██░░█████░░██░░░░░░░▒▒░░▒▒░░░░░█░░░░░░░░█░░█░░░" << endl;
  cout << "░░░█░░░░██▒░███░▒██░░░░░▒▒▒▒▒░░▒▒░▒▒░░██████████░░█░░░" << endl;
  cout << "░░░█░░░░██▒▒░█░▒▒██░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░█▒▒███▒▒█░░░░░▒▒▒▒▒▒▒░▒▒▒░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░█▒▒░█░▒▒█░░░░▒▒▒▒░▒▒▒▒▒░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░██▒░███░▒██░░░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░██░░█████░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░███░░░░░░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░█████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░" << endl;
  cout << "░░░████████████████████████████████████████████████░░░" << endl;
}