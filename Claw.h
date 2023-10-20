// Emmanuel Loria
// This is my own work
#ifndef CLAW_H
#define CLAW_H
#include "Weapon.h"

// The derived Claw class will be exclusive to the enemies
class Claw:public Weapon {
private:
int price;
double damage;
string name;

public:
Claw();
Claw(int, double, string);
int getPrice()const;
double getDamage()const;
string getName()const;
void setPrice(int);
void setName(string);
void setDamage(double);
};

Claw::Claw():Weapon(){}

Claw::Claw(int p, double d, string n):Weapon(p, d, n) {}

int Claw::getPrice()const {
  return price;
}


double Claw::getDamage()const {
  return damage;
}

string Claw::getName()const {
  return name;
}

void Claw::setPrice(int p) {
  price = p;
}

void Claw::setName(string n) {
  name = n;
}

void Claw::setDamage(double d) {
  damage = d;
}
#endif
