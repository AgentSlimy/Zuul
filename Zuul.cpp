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
	cout << endl << "There is no room there, nowhere to move to... unless you can travel through walls." << endl;
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
  Room* entranceHall = new Room();
  entranceHall -> setDescription((char*)("in the entrance hallway."));
  entrancaHall -> setID(1);
  temp.insert(pair<int, char*> (3, north)); //To dining 1 on map
  temp.insert(pair<int, char*> (2, east)); //To office 1 on map, any comments moving forward relating to "temp.insert(...)" will be refering to locations on the provided map
  entranceHall -> setExit(temp);
  entranceHall -> setItem(0);
  rooms -> push_back(entranceHall);
  temp.clear();
  Room* firstOffice = new Room();
  firstOffice -> setDescription((char*)("in the first office."));
  firstOffice -> setID(2);
  temp.insert(pair<int, char*> (1, west)); //To entrance
  firstOffice -> setExit(temp);
  firstOffice -> setItem(1); //Item: Keyboard
  rooms -> push_back(firstOffice);
  temp.clear();
  Room* firstDining = new Room();
  firstDining -> setDescription((char*)("in the front dining room, it's pretty empty here..."));
  firstDining -> setID(3);
  temp.insert(pair<int, char*> (1, south)); //To entrance
  temp.insert(pair<int, char*> (4, north)); //To living room 1
  firstDining -> setExit(temp);
  firstDining -> setItem(0);
  rooms -> push_back(firstDining);
  temp.clear();
  Room* firstLivingR = new Room();
  firstLivingR -> setDescription((char*)("in the main living room, oooooh fireplace."));
  firstLivingR -> setID(4);
  temp.insert(pair<int, char*> (3, south)); //To dining 1
  temp.insert(pair<int, char*> (6, west)); //To kitchen
  firstLivingR -> setExit(temp);
  firstLivingR -> setItem(0);
  rooms -> push_back(firstLivingR);
  temp.clear();
  Room* secDining = new Room();
  secDining -> setDescription((char*)("in the second dining area next to the kitchen. There's a table here, maybe that means something?"));
  secDining -> setID(5);
  temp.insert(pair<int, char*> (6, south)); //To kitchen
  temp.insert(pair<int, char*> (9, east)); //To balconey
  secDining -> setExit(temp);
  secDining -> setItem(0);
  rooms -> push_back(secDining);
  temp.clear();
  Room* kitchen = new Room();
  kitchen -> setDescription((char*)("in the kitchen, is there anything useful in here?"));
  kitchen -> setID(6);
  temp.insert(pair<int, char*> (5, north)); //To dining 2
  temp.insert(pair<int, char*> (4, east)); //To living room 1
  temp.insert(pair<int, char*> (7, west)); //To office 2
  temp.insert(pair<int, char*> (11, south)); //To living room 2/basement floor
  kitchen -> setExit(temp);
  kitchen -> setItem(0);
  rooms -> push_back(kitchen);
  temp.clear();
  Room* secOffice = new Room();
  secOffice -> setDescription((char*)("in the second office. MICE!!!!!!"));
  secOffice -> setID(7);
  temp.insert(pair<int, char*> (6, east)); //To kitchen
  temp.insert(pair<int, char*> (8, south)); //To bathroom (8)
  secOffice -> setExit(temp);
  secOffice -> setItem(2); //Item: Mouse
  rooms -> push_back(secOffice);
  temp.clear();
  Room* firstBathroom = new Room();
  firstBathroom -> setDescription((char*)("in the first bathroom, I shouldn't spend much time here."));
  firstBathroom -> setID(8);
  temp.insert(pair<int, char*> (7, north)); //To office 2
  temp.insert(pair<int, char*> (11, east)); //To living room 2/basement floor
  temp.insert(pair<int, char*> (10, south)); //To garage
  firstBathroom -> setExit(temp);
  firstBathroom -> setItem(0);
  rooms -> push_back(firstBathroom);
  temp.clear();
  //asdfajslfkjasdlfjs
}
