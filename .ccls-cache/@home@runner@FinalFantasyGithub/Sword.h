// Emmanuel Loria
// This is my own work
#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"

class Sword:public Weapon {
private:
int price;
double damage;
string name;

public:
Sword();
Sword(int, double, string);
int getPrice()const;
double getDamage()const;
string getName()const;
void setPrice(int);
void setName(string);
void setDamage(double);
};

Sword::Sword():Weapon(){}

Sword::Sword(int p, double d, string n):Weapon(p, d, n) {
  price = p;
  damage = d;
  name = n;
}

int Sword::getPrice()const {
  return price;
}

double Sword::getDamage()const {
  return damage;
}

string Sword::getName()const {
  return name;
}

void Sword::setPrice(int p) {
  price = p;
}

void Sword::setName(string n) {
  name = n;
}

void Sword::setDamage(double d) {
  damage = d;
}

#endif