// Emmanuel Loria
// This is my own work
#ifndef AXE_H
#define AXE_H
#include "Weapon.h"

class Axe:public Weapon {
private:
int price;
double damage;
string name;

public:
Axe();
Axe(int, double, string);
int getPrice()const;
double getDamage()const;
string getName()const;
void setPrice(int);
void setName(string);
void setDamage(double);
};

Axe::Axe():Weapon(){}

Axe::Axe(int p, double d, string n):Weapon(p, d, n) {
  price = p;
  damage = d;
  name = n;
}

int Axe::getPrice()const {
  return price;
}

double Axe::getDamage()const {
  return damage;
}

string Axe::getName()const {
  return name;
}

void Axe::setPrice(int p) {
  price = p;
}

void Axe::setName(string n) {
  name = n;
}

void Axe::setDamage(double d) {
  damage = d;
}

#endif