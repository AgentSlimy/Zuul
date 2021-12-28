#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

Item::Item() {

}

//Getters
char* Item::getName() {
  return name;
}

int Item::getID() {
  return ID;
}

//Setters 
void Item::setName(char* newName) {
  name = newName;
}

void Item::setID(int newID) {
  ID = newID;
}
