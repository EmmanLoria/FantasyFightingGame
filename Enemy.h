// Emmanuel Loria
// This is my own work
#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "Weapon.h"
#include "Claw.h"
#include <iostream>
#include <string>

using namespace std;

class Enemy: public Character {
protected:
string name;
double health;
Weapon weapon;

public:
Enemy();
Enemy(string, Weapon, double);
string getName()const;
double getHealth()const;
void setHealth(double);
void loseHealth(Character);
// void hit(Character&);
void showSheet();
};

Enemy::Enemy() {
  name = "Enemy";
  health = 100;
}

Enemy::Enemy(string n, Weapon w, double h) {
  name = n;
  weapon = w;
  health = h;
}

string Enemy::getName()const {
  return name;
}

double Enemy::getHealth()const {
  return health;
}

void Enemy::setHealth(double h) {
  health = h;
}

void Enemy::loseHealth(Character c){
  double dam = c.getWeapon().getDamage();
  double newHealth = health - dam;
  setHealth(newHealth);
}

void Enemy::showSheet() {
  cout << "--ENEMY SHEET--" << "\n\n";
  cout << "Name: " << getName() << endl;
  cout << "Health: " << getHealth() << endl;
  cout << "Weapon: " << weapon.getName() << endl;
  cout << "  Weapon Damage: " << weapon.getDamage() << "\n\n";
}

#endif