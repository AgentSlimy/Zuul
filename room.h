#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public:
  Room();
 //Getters
  char* getDescrip();
  int getID();
  int getItem();
  map<int, char*>* getExits();
 //Setters
  void setDescription(char*);
  void setExit(map<int, char*>);
  void setID(int);
  void setItem(int);
 private:
  char* description;
  map<int, char*> exits;
  int ID;
  int item;
};
#endif
