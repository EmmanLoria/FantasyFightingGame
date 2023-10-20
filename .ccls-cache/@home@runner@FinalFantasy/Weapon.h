// Emmanuel Loria
// This is my own work
#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>

using namespace std;

class Weapon {
protected:
int price;
double damage;
string name;

public:
Weapon();
Weapon(int, double, string);
virtual int getPrice()const;
virtual double getDamage()const;
virtual string getName()const;
virtual void setPrice(int);
virtual void setName(string);
virtual void setDamage(double);
};

Weapon::Weapon() {
  price = 0;
  damage = 10;
  name = "Fists";
}

Weapon::Weapon(int p, double d, string n) {
  price = p;
  damage = d;
  name = n;
}

int Weapon::getPrice()const {
  return price;
}

string Weapon::getName()const {
  return name;
}

double Weapon::getDamage()const {
  return damage;
}

void Weapon::setName(string n) {
  name = n;
}

void Weapon::setPrice(int p) {
  price = p;
}

void Weapon::setDamage(double d) {
  damage = d;
}


#endif