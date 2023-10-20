// Emmanuel Loria
// This is my own work
#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

// Item class will provide the hero with the ability to gain health at a cost
class Item {
private:
int price;
double health;
string name;

public:
Item();
Item(string, double, int);
int getPrice()const;
double getHealth()const;
string getName()const;
};

Item::Item() {
  price = 0;
  health = 0;
  name = "";
}

Item::Item(string n, double h, int p) {
  name = n;
  health = h;
  price = p;
}

int Item::getPrice()const {
  return price;
}

double Item::getHealth()const {
  return health;
}

string Item::getName()const {
  return name;
}
#endif