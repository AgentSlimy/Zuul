#include <iostream>

using namespace std;

int main() {
  bool playing = true;
  char commandInput[10];
  
  cout << "Welcome to Zuul" << endl;
  cout << "In this version, you are urgently needed at your computer for a meeting." << endl;
  cout << "You need to find and get your peripherals before you can go to your computer." << endl; //Keyboard, mouse, headphones, webcam, mousepad, wireless adapters
  cout << "Go through your house to find your items. Your commands are: go, get, drop, inventory, quit, and help" << endl

  while (playing == true) {
    cout << "You are currently in the ";
    cin >> commandInput;
    if (strcmp(commandInput, "Go") == 0 || strcmp(commandInput, "go") == 0) {
      //placeholder
    }
    else if (strcmp(commandInput, "Get") == 0 || strcmp(commandInput, "get") == 0) {
      //placeholder
    }
    else if (strcmp(commandInput, "Drop") == 0 || strcmp(commandInput, "drop") == 0) {
      //placeholder
    }
    else if (strcmp(commandInput, "Inventory") == 0 || strcmp(commandInput, "inventory") == 0) {
      //placeholder
    }
    else if (strcmp(commandInput, "Quit") == 0 || strcmp(commandInput, "quit") == 0) {
      playing = false;
      cout << "Quiting";
    }
    else if
  }
