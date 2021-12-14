/*
Author: Nathan Zou
Map: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
     https://www.cplusplus.com/reference/map/map/map/
*/

#include <iostream>
#include <cstring>
#include <map>

#include "room.h"
#include "item.h"

using namespace std;

void initializeRooms(vector<Room*>* rooms);
//void initializeItems(vector<Item*>* items);
void printRooms(vector<Room*>* rooms, vector<Item*>* items, int currentRoom);
//void printInventory(vector<Item*>* items, vector<int> inventory);
//void getItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
//void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
int move(vector<Room*>* rooms, int currentRoom, char direction[]);

int main() {
  bool playing = true;
  char commandInput[10];
  vector<Room*> roomsList;
  vector<Item*> itemsList;
  vector<int> Inventory;
  initializeRooms(&roomsList);
  //initializeItems(&itemsList);
  int currentRoom = 1;
  
  cout << "Welcome to Zuul" << endl;
  cout << "In this version, you are urgently needed at your computer for a meeting." << endl;
  cout << "You need to find and get your peripherals before you can go to your computer." << endl; //Keyboard, mouse, headphones, webcam, mousepad, wireless adapters
  cout << "Go through your house to find your items." << endl; 
  cout << "Your commands are: go, get, drop, inventory, quit, and help" << endl;

  while (playing == true) {
    cout << "You are currently in the ";
    printRoom(&roomsList, &itemsList, currentRoom);
    cin >> commandInput;
    cin.clear();
    cin.ignore(10000, '\n');
    if (strcmp(commandInput, "Go") == 0 || strcmp(commandInput, "go") == 0) {
      cout << "Direction: ";
      cin >> commandInput;
      cin.clear();
      cin.ignore(10000, '\n');
      if (move(&roomsList, currentRoom, commandInput) == 0) {
	cout << endl << "There is no room there, nowhere to move... unless you can fly through walls." << endl;
      }
      else {
	currentRoom = move(&roomsList, currentRoom, commandInput);
      }
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
      cout << "Quitting Zuul.";
    }
    else if (strcmp(commandInput, "Help") == 0 || strcmp(commandInput, "help") == 0) {
      cout << "The available commands are: go, get, drop, inventory, quit, and help." << endl;
      cout << "Map: https://docs.google.com/drawings/d/1l9XT2UThx76KT7BSAz0aefrQ25VEDIuZUnuKlFQQdGE/edit?usp=sharing" << endl;
    }
    else {
      cout << "Invalid command, try again" << endl;
      playing = true;
    }
  }
}

int move(vector<Room*>* rooms, int currentRoom, char direction[]) {
  vector<Room*>*::iterator move;
  for (move = rooms->begin(); move != rooms->end(); move++) {
    if (currentRoom == (*move)->getID()) {
      map<int, char*>::const_iterator map;
      for (map = exits.begin(); map != exits.end(); ++map) {
	if (strcmp(m -> second, direction) == 0) {
	  return map -> first;
	}
      }
    }
  }
  return 0;
}

void initializeRooms(vector<Room*>* rooms) {
  char* north = (char*)("north");
  char* east = (char*)("east");
  char* south = (char*)("south");
  char* west = (char*)("west");
  map<int, char*> tempMap;
  
}
