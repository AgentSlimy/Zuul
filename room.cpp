#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room() {

}

//Getters
char* Room::getDescrip() {
	return description;
}

map<int, char*>* Room::getExits() {
	return &exits;
}

int Room::getID() {
	return ID;
}

int Room::getItem() {
	return item;
}

//Setters
void Room::setDescription(char* newDescription) {
	description = newDescription;
}

void Room::setExit(map<int, char*> newExit) {
	exits = newExit;
}

void Room::setID(int newID) {
	ID = newID;
}

void Room::setItem(int newItem) {
	item = newItem;
}
