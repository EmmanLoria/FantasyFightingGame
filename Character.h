// Emmanuel Loria
// This is my own work
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Sword.h"
#include "Axe.h"

using namespace std;

class Character {
protected:
Weapon weapon;
string name;
double health;
int money;

public:
Character();
Character(string , Weapon, double, int); 
string getName()const;
double getHealth()const;
int getMoney()const;
Weapon getWeapon()const;
void setWeapon(Weapon&);
void setName(string n);
void setHealth(double h);
void setMoney(int m);
// virtual void hit(Character&);
// virtual (NOT PURE VIRTUAL) function
virtual void loseHealth(Character);
void showSheet();
};

Character::Character(){
  name = "The Shadow Lord";
  money = 100;
  health = 100;
}

Character::Character(string n, Weapon w, double h, int m) {
  name = n;
  weapon = w;
  health = h;
  money = m;
}

string Character::getName()const {
  return name;
}

double Character::getHealth()const {
  return health;
}

int Character::getMoney()const {
  return money;
}

Weapon Character::getWeapon()const {
  return weapon;
}

void Character::setName(string n) {
  name = n;
}

void Character::setHealth(double h) {
  health = h;
}

void Character::setMoney(int m) {
  money = m;
}

void Character::setWeapon(Weapon& w) {
  weapon = w;
}


void Character::loseHealth(Character c){
  double dam = c.getWeapon().getDamage();
  double newHealth = health - dam;
  setHealth(newHealth);
}


void Character::showSheet() {
  cout << "--CHARACTER SHEET--" << "\n\n";
  cout << "Name: " << getName() << endl;
  cout << "Health: " << getHealth() << endl;
  cout << "Money: " << getMoney() << endl;
  cout << "Weapon: " << weapon.getName() << endl;
  cout << "  Weapon Damage: " << weapon.getDamage() << "\n\n";
  }

#endif