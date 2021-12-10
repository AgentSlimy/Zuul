#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room() {

}

char* Room::getDescrip(){
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

