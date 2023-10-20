// Emmanuel Loria
// This is my own work
#ifndef ARENA_H
#define ARENA_H
#include "Character.h"
#include "Claw.h"
#include "Enemy.h"
#include "Store.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Arena {
private:
  Character hero;
  Enemy enemies[6];

public:
  Arena();
  // Menu function
  void menu();
  void battleBegins();
};

Arena::Arena() {
  // Enemy Weapons
  Claw c;
  c.setName("Claw");
  c.setDamage(5);
  Sword s;
  s.setName("Iron Broadsword");
  s.setDamage(10);
  
  enemies[0] = Enemy("Pash the Tower", c, 30);
  enemies[1] = Enemy("Auzzog the Crimson One", c, 30);
  enemies[2] = Enemy("Orgha the Meat", s, 50);
  enemies[3] = Enemy("Bruz the Chopper", s, 300);
  enemies[4] = Enemy("Ymir the Ugly", s, 100);
  enemies[5] = Enemy("Obi-Juan Kenobi", c, 65);

  hero.setName("The Shadow Lord");
}

// Function definition for Menu
void Arena::menu() {
  // Set variables that contain the hero's data and put them into vector
  string heroName;
  string heroHealth;
  string heroMoney;
  string weaponName;
  string weaponPrice;
  string weaponDamage;
  
  char ans;
  fstream myFile;
  // Read File
  myFile.open("ffsavedata.txt", ios::in);
  if (myFile.is_open()) {
    while(getline(myFile, heroName)) {
      string newName = heroName;
      getline(myFile, heroMoney);
      int newMon = stoi(heroMoney);
      getline(myFile, heroHealth);
      double newHealth = stod(heroHealth);
      getline(myFile, weaponName);
      getline(myFile, weaponPrice);
      int newPrice = stoi(weaponPrice);
      getline(myFile, weaponDamage);
      double newDam = stod(weaponDamage);
      
      hero.setName(newName);
      hero.setMoney(newMon);
      hero.setHealth(newHealth);
      Weapon w(newPrice, newDam, weaponName);
      hero.setWeapon(w);
    }
    
    }
  myFile.close();
cout << endl;
do {
  cout << "[Fight] - 1\n";
  cout << "[Character Sheet] - 2\n";
  cout << "[Store] - 3\n";
  cout << "[Quit] - 4\n";
  cout << "[Save] - 5\n";
  cout << "[Clear Data] - 6\n\n";
  cin >> ans;
  cout << "\n\n";
  if (ans == '1') {
    battleBegins();
    
  } else if (ans == '2') {
    hero.showSheet();
    cout << "Press [Enter] to continue";
    cin.ignore();
    if(cin.get() == '\n') {
      system("clear");
    }
  }else if (ans == '3') {
    Store s;
    s.shopMenu(hero);
    cout << "Press [Enter] to continue";
    cin.ignore();
    if(cin.get() == '\n') {
      system("clear");
    }
    
    // Save data
  } else if (ans == '5') {
    myFile.open("ffsavedata.txt", ios::out);
    if (myFile.is_open()) {
      myFile << hero.getName() << endl;
      myFile << hero.getMoney() << endl;
      myFile << hero.getHealth() << endl;
      myFile << hero.getWeapon().getName() << endl;
      myFile << hero.getWeapon().getPrice() << endl;
      myFile << hero.getWeapon().getDamage() << endl;
      myFile.close();
    }
    cout << "Game has been saved!\n\n";

    // Clear data
  } else if(ans == '6') {
    myFile.open("ffsavedata.txt", ofstream::out | ofstream::trunc);
    myFile.close();
    exit(10);
  }
  
} while (ans != '4');
  // Clear system
  system("clear");
}


void Arena::battleBegins() {
  srand(time(NULL));
  // Another Enemy object is created so the hero has to fight a random enemy
  // from the array that hold enemy objects
  Enemy enemy = enemies[rand() % 6];
  // Create constant variable in order to preserve the enemy's health
  const double health = enemy.getHealth();
  char choice;
  cout << "You are fighting " << enemy.getName() << "!"
       << "\n\n";
  hero.showSheet();
  cout << "\n\n";
  enemy.showSheet();
  do {
    // Random generator for chance to hit
    cout << "f - hit"
         << "\n\n";
    cin >> choice;
    // Hero's turn
    if (choice == 'f') {
      // Switch case acts as a chance generator
      // The break are necessary here because it does not make sense to damage
      // the enemy and for the enemy to block at the same time
      for (int i = 0; i < 1; i++) {
        switch (rand() % 3) {
        case 0:
          cout << "You have damaged the enemy!"
               << "\n\n";
          enemy.loseHealth(hero);
          break;
        case 1:
          cout << "You have damaged the enemy!"
               << "\n\n";
          enemy.loseHealth(hero);
          break;
        case 2:
          cout << enemy.getName() << " blocked your attack!"
               << "\n\n";
        }
      }
    }
    // Enemies turn
    for (int i = 0; i < 1; i++) {
      switch (rand() % 3) {
      case 0:
        cout << enemy.getName() << " has damaged you!"
             << "\n\n";
        hero.loseHealth(enemies[1]);
        break;
      case 1:
        cout << "You have blocked " << enemy.getName() << "'s attack!"
             << "\n\n";
        break;
      case 2:
        cout << "You have blocked " << enemy.getName() << "'s attack!"
             << "\n\n";
      }
    }
    hero.showSheet();
    cout << "\n\n";
    enemy.showSheet();

    
  } while (enemy.getHealth() > 0 && hero.getHealth() > 0);
  // Situation if enemy dies
  if (enemy.getHealth() <= 0) {
    // const variable from earlier is passed, setting the enemy's health back to
    // its original state
    enemy.setHealth(health);
    cout << "You have defeated your foe my lord!"
         << "\n\n";
    // Hero's reward for defeating the enemy
    cout << "Here is your reward: "
         << "\n\n";
    for (int i = 0; i < 1; i++) {
      switch (rand() % 3) {
      case 0:
        cout << "You have gained health!"
             << "\n\n";
        hero.setHealth(hero.getHealth() + 25);
        cout << "And you have gained money!"
             << "\n\n";
        hero.setMoney(hero.getMoney() + 150);
        break;
      case 1:
        cout << "You have gained health!"
             << "\n\n";
        hero.setHealth(hero.getHealth() + 25);
        break;
      case 2:
        cout << "You have gained money!"
             << "\n\n";
        hero.setMoney(hero.getMoney() + 50);
      }
    }

  }
  cout << "Press [Enter] to continue";
    cin.ignore();
    if(cin.get() == '\n') {
      system("clear");
    }
}
#endif