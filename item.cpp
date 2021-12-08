#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

Item::Item() {

}

char* Item::getName() {
  return name;
}

int Item::getID() {
  return ID;
}

void Item::setName(char* newName) {
  name = newName;
}

void Item::setID(int newID) {
  ID = newID;
}
