#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item();
 //Setters
  void setName(char*);
  void setID(int);
 //Getters
  char* getName();
  int getID();
 private:
  char* name;
  int ID;
};
#endif
