/*
Author: Nathan Zou
Date: 12/26/21
My version of a Zuul game with
Map: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
     https://www.cplusplus.com/reference/map/map/map/
*/

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "room.h"
#include "item.h"

using namespace std;

void initializeRooms(vector<Room*>* rooms);
void initializeItems(vector<Item*>* items);
void printRooms(vector<Room*>* rooms, vector<Item*>* items, int currentRoom);
void printInventory(vector<Item*>* items, vector<int> inventory);
void getItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
int move(vector<Room*>* rooms, int currentRoom, char direction[]);

int main() {
    bool playing = true;
    char commandInput[10];
    char inputResponse[10];
    vector<Room*> roomsList;
    vector<Item*> itemsList;
    vector<int> inventory;
    initializeRooms(&roomsList);
    initializeItems(&itemsList);
    int currentRoom = 1;

    cout << "Welcome to Zuul" << endl;
    cout << "In this version, you are urgently needed at your computer for a meeting." << endl;
    cout << "You need to find and get your peripherals before you can go to your computer." << endl; //Keyboard, mouse, headphones, webcam, mousepad, wireless adapters
    cout << "Go through your house to find your items." << endl;
    cout << "Your commands are: go, get, drop, inventory, quit, and help" << endl;

    while (playing == true) {
        cout << "You are currently ";
        printRooms(&roomsList, &itemsList, currentRoom);
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
            cout << "What item would you like to retrieve: " << endl;
            cin >> inputResponse;
            cin.clear();
            cin.ignore(10000, '\n');
            getItem(&roomsList, &itemsList, &inventory, currentRoom, inputResponse);
        }
        else if (strcmp(commandInput, "Drop") == 0 || strcmp(commandInput, "drop") == 0) {
            cout << "What item would you like to drop?" << endl;
            cin >> inputResponse;
            cin.clear();
            cin.ignore(10000, '\n');
            dropItem(&roomsList, &itemsList, &inventory, currentRoom, inputResponse);
        }
        else if (strcmp(commandInput, "Inventory") == 0 || strcmp(commandInput, "inventory") == 0) {
            if (inventory.size() != 0) {
                cout << endl << "You have: ";
                printInventory(&itemsList, inventory);
            }
            else {
                cout << endl << "You have nothing in your inventory." << endl;
            }
        }
        else if (strcmp(commandInput, "Quit") == 0 || strcmp(commandInput, "quit") == 0) {
            playing = false;
            cout << "Quitting Zuul.";
        }
        else if (strcmp(commandInput, "Help") == 0 || strcmp(commandInput, "help") == 0) {
            cout << "The available commands are: go, get, drop, inventory, quit, and help." << endl;
            cout << "You need to retrieve your items and go back to your computer before your meeting starts!" << endl;
            cout << "Map: https://docs.google.com/drawings/d/1l9XT2UThx76KT7BSAz0aefrQ25VEDIuZUnuKlFQQdGE/edit?usp=sharing" << endl;
            cout << "Some directions provided in the game may not perfectly align with the map. The map was created first and then the code." << endl;
        }
        else {
            cout << "Invalid command, try again" << endl;
            playing = true;
        }

        for (int a = 0; a < inventory.size(); a++) {
            for (int b = 0; b < inventory.size(); b++) {
                for (int c = 0; c < inventory.size(); c++) {
                    for (int d = 0; d < inventory.size(); d++) {
                        for (int e = 0; e < inventory.size(); e++) {
                            if (currentRoom == 2 && inventory[a] == 1 && inventory[b] == 2 && inventory[c] == 3 && inventory[c] == 4 && inventory[c] == 5) {
                                cout << endl << "You have succesfully completed this Zuul." << endl << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }

        for (int a = 0; a < inventory.size(); a++) {
            if (currentRoom == 2 && inventory[a] == 2) {
                cout << endl << "Insufficient items." << endl;
                cout << "You lost. :(" << endl << endl;
                playing = false;
            }
            else if (currentRoom == 2 && inventory[a] == 3) { 
                cout << endl << "Insufficient items." << endl;
                cout << "You lost. :(" << endl << endl;
                playing = false;
            }
            else if (currentRoom == 2 && inventory[a] == 4) {
                cout << endl << "Insufficient items." << endl;
                cout << "You lost. :(" << endl << endl;
                playing = false;
            }
            else if (inventory[a] == 6 && currentRoom == 2) {
                cout << endl << "Too many items." << endl;
                cout << "You lost. :(" << endl << endl;
                playing = false;
            }
        }
        
    }
    return 0;
}

int move(vector<Room*>* rooms, int currentRoom, char direction[]) {
    vector<Room*>::iterator move;
    for (move = rooms->begin(); move != rooms->end(); move++) {
        if (currentRoom == (*move)->getID()) {
            map<int, char*> exits;
            exits = *(*move)->getExits();
            map<int, char*>::const_iterator map;
            for (map = exits.begin(); map != exits.end(); ++map) {
                if (strcmp(map->second, direction) == 0) {
                    return map->first;
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
    entranceHall->setDescription((char*)("in the entrance hallway. What more could you ask for?"));
    entranceHall->setID(1);
    tempMap.insert(pair<int, char*>(3, north)); //To dining 1 on map
    tempMap.insert(pair<int, char*>(2, east)); //To office 1 on map, any comments moving forward relating to "temp.insert(...)" will be refering to locations on the provided map
    entranceHall->setExit(tempMap);
    entranceHall->setItem(0);
    rooms->push_back(entranceHall);
    tempMap.clear();
    Room* firstOffice = new Room();
    firstOffice->setDescription((char*)("in the first office. Clickity clackity there is my property."));
    firstOffice->setID(2);
    tempMap.insert(pair<int, char*>(1, west)); //To entrance
    firstOffice->setExit(tempMap);
    firstOffice->setItem(1); //Item: Keyboard
    rooms->push_back(firstOffice);
    tempMap.clear();
    Room* firstDining = new Room();
    firstDining->setDescription((char*)("in the front dining room, it's pretty empty here..."));
    firstDining->setID(3);
    tempMap.insert(pair<int, char*>(1, south)); //To entrance
    tempMap.insert(pair<int, char*>(4, north)); //To living room 1
    firstDining->setExit(tempMap);
    firstDining->setItem(0);
    rooms->push_back(firstDining);
    tempMap.clear();
    Room* firstLivingR = new Room();
    firstLivingR->setDescription((char*)("in the main living room, oooooh fireplace."));
    firstLivingR->setID(4);
    tempMap.insert(pair<int, char*>(3, south)); //To dining 1
    tempMap.insert(pair<int, char*>(6, west)); //To kitchen
    firstLivingR->setExit(tempMap);
    firstLivingR->setItem(0);
    rooms->push_back(firstLivingR);
    tempMap.clear();
    Room* secDining = new Room();
    secDining->setDescription((char*)("in the second dining area next to the kitchen. There's a table here, maybe that means something?"));
    secDining->setID(5);
    tempMap.insert(pair<int, char*>(6, south)); //To kitchen
    tempMap.insert(pair<int, char*>(9, east)); //To balcony
    secDining->setExit(tempMap);
    secDining->setItem(2); //Item: Wireless recievers
    rooms->push_back(secDining);
    tempMap.clear();
    Room* kitchen = new Room();
    kitchen->setDescription((char*)("in the kitchen, is there anything useful in here?"));
    kitchen->setID(6);
    tempMap.insert(pair<int, char*>(5, north)); //To dining 2
    tempMap.insert(pair<int, char*>(4, east)); //To living room 1
    tempMap.insert(pair<int, char*>(7, west)); //To office 2
    kitchen->setExit(tempMap);
    kitchen->setItem(0);
    rooms->push_back(kitchen);
    tempMap.clear();
    Room* secOffice = new Room();
    secOffice->setDescription((char*)("in the second office. MICE!!!!!!"));
    secOffice->setID(7);
    tempMap.insert(pair<int, char*>(6, east)); //To kitchen
    tempMap.insert(pair<int, char*>(8, south)); //To bathroom (8)
    secOffice->setExit(tempMap);
    secOffice->setItem(3); //Item: Mouse
    rooms->push_back(secOffice);
    tempMap.clear();
    Room* firstBathroom = new Room();
    firstBathroom->setDescription((char*)("in the first bathroom, I shouldn't spend much time here."));
    firstBathroom->setID(8);
    tempMap.insert(pair<int, char*>(7, north)); //To office 2
    tempMap.insert(pair<int, char*>(11, west)); //To living room 2/basement floor
    tempMap.insert(pair<int, char*>(10, south)); //To garage
    firstBathroom->setExit(tempMap);
    firstBathroom->setItem(0);
    rooms->push_back(firstBathroom);
    tempMap.clear();
    Room* balcony = new Room();
    balcony->setDescription((char*)("outside the house on the balcony, its cold out here."));
    balcony->setID(9);
    tempMap.insert(pair<int, char*>(5, west)); //To dining 2
    balcony->setExit(tempMap);
    balcony->setItem(0);
    rooms->push_back(balcony);
    tempMap.clear();
    Room* garage = new Room();
    garage->setDescription((char*)("in the garage. It sure is full of stuff, not sure if any of it is useful... Oh a camera."));
    garage->setID(10);
    tempMap.insert(pair<int, char*>(8, north)); //To bathroom (8)
    garage->setExit(tempMap);
    garage->setItem(4); //Item: Webcam
    rooms->push_back(garage);
    tempMap.clear();
    Room* secLivingR = new Room();
    secLivingR->setDescription((char*)("downstairs in the second living room. My headphones!"));
    secLivingR->setID(11);
    tempMap.insert(pair<int, char*>(8, east)); //To bathroom (8)
    tempMap.insert(pair<int, char*>(12, west)); //To hallway
    secLivingR->setExit(tempMap);
    secLivingR->setItem(5); //Item: Headphones
    rooms->push_back(secLivingR);
    tempMap.clear();
    Room* hallway = new Room();
    hallway->setDescription((char*)("in the basement hallway. So many paths to choose from."));
    hallway->setID(12);
    tempMap.insert(pair<int, char*>(11, east)); //To living room 2
    tempMap.insert(pair<int, char*>(15, south)); //To closet
    tempMap.insert(pair<int, char*>(14, west)); //To bathroom (14)
    tempMap.insert(pair<int, char*>(13, north)); //To guest bedroom
    hallway->setExit(tempMap);
    hallway->setItem(0);
    rooms->push_back(hallway);
    tempMap.clear();
    Room* guestBed = new Room();
    guestBed->setDescription((char*)("in the guest bedroom, not much to see in here."));
    guestBed->setID(13);
    tempMap.insert(pair<int, char*>(12, south)); //To hallway
    guestBed->setExit(tempMap);
    guestBed->setItem(0);
    rooms->push_back(guestBed);
    tempMap.clear();
    Room* secBathroom = new Room();
    secBathroom->setDescription((char*)("in the second bathroom, why am I even here?"));
    secBathroom->setID(14);
    tempMap.insert(pair<int, char*>(12, east)); //To hallway
    secBathroom->setExit(tempMap);
    secBathroom->setItem(0);
    tempMap.clear();
    Room* closet = new Room();
    closet->setDescription((char*)("in the storage closet. There must be a mousepad around here somewhere..."));
    closet->setID(15);
    tempMap.insert(pair<int, char*>(12, north)); //To hallway
    closet->setExit(tempMap);
    closet->setItem(6); //Item: Mousepad
    rooms->push_back(closet);
    tempMap.clear();
}

void initializeItems(vector<Item*>* items) {
    Item* kb = new Item();
    kb->setName((char*)("Keyboard"));
    kb->setID(1);
    items->push_back(kb);
    Item* wr = new Item();
    wr->setName((char*)("Recievers"));
    wr->setID(2);
    items->push_back(wr);
    Item* m = new Item();
    m->setName((char*)("Mouse"));
    m->setID(3);
    items->push_back(m);
    Item* wc = new Item();
    wc->setName((char*)("Webcam"));
    wc->setID(4);
    items->push_back(wc);
    Item* hp = new Item();
    hp->setName((char*)("Headphones"));
    hp->setID(5);
    items->push_back(hp);
    Item* mp = new Item();
    mp->setName((char*)("Mousepad"));
    mp->setID(6);
    items->push_back(mp);
}

void printRooms(vector<Room*>* rooms, vector<Item*>* items, int currentRoom) {
    vector<Room*>::iterator room;
    vector<Item*>::iterator item;
    for (room = rooms->begin(); room != rooms->end(); room++) {
        if (currentRoom == (*room)->getID()) {
            cout << (*room)->getDescrip() << endl;
            cout << " Exits: ";
            for (map<int, char*>::const_iterator r = (*room)->getExits()->begin(); r != (*room)->getExits()->end(); r++) {
                cout << r->second << " ";
            }
            cout << endl;

            cout << " Items in this room: ";
            int itemCount = 0;
            for (item = items->begin(); item != items->end(); item++) {
                if ((*room)->getItem() == (*item)->getID()) {
                    cout << (*item)->getName();
                    itemCount++;
                }
            }
            if (itemCount == 0) {
                cout << "No items in this room." << endl;
            }
            else {
                cout << endl;
            }
        }
    }
}

void printInventory(vector<Item*>* items, vector<int> inventory) {
    vector<Item*>::iterator inven;
    for (inven = items->begin(); inven != items->end(); inven++) {
        for (int a = 0; a < inventory.size(); a++) {
            if (inventory[a] == (*inven)->getID()) {
                cout << (*inven)->getName() << " ";
            }
        }
    }
    cout << endl;
}

void getItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]) {
    vector<Room*>::iterator room;
    vector<Item*>::iterator item;
    for (room = rooms->begin(); room != rooms->end(); room++) {
        if (currentRoom == (*room)->getID()) {
            for (item = items->begin(); item != items->end(); item++) {
                if (((*room)->getItem() == (*item)->getID()) && (strcmp((*item)->getName(), name) == 0)) {
                    inventory->push_back((*item)->getID());
                    (*room)->setItem(0);
                    cout << endl << "Picked up: " << (*item)->getName() << "." << endl;
                    return;
                }
            }
        }
    }
    cout << "That item is not here." << endl;
}

void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]) {
    int count{};
    vector<Room*>::iterator room;
    vector<Item*>::iterator item;
    vector<int>::iterator gI;
    for (room = rooms->begin(); room != rooms->end(); room++) {
        if (currentRoom == (*room)->getID()) {
            if ((*room)->getItem() == 0) {
                for (item = items->begin(); item != items->end(); item++) {
                    if (strcmp((*item)->getName(), name) == 0) {
                        for (gI = inventory->begin(); gI != inventory->end(); gI++) {
                            if ((*gI) == (*item)->getID()) {
                                cout << endl << "Dropped " << (*item)->getName() << "." << endl;
                                (*room)->setItem((*item)->getID());
                                gI = inventory->erase(gI);
                                return;
                            }
                        }
                    }
                    else if (count == items->size() - 1) {
                        cout << endl << "Item not in inventory." << endl;
                    }
                    count++;
                }
            }
            else {
                cout << endl << "There is an item in this room already." << endl;
            }
        }
    }
}
