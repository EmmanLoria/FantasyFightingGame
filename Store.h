// Emmanuel Loria
// This is my own work
#ifndef STORE_H
#define STORE_H
#include "Weapon.h"
#include "Sword.h"
#include "Axe.h"
#include "Character.h"
#include "Item.h"

using namespace std;

class Store {
private:
// Polymorphic variable
// Although Weapon is not an abstract class, a polymorphic variable (which is a variable that hold objects of different types) can still be made. Why? This is because polymorphism requires inheritance, and the Sword and Axe class are inherited from the Weapon class
Weapon* weapon[6];
Item items[6];

public:
Store();
~Store();
void shopMenu(Character&);
void buyItems(Character&);
void buyWeapons(Character&);
};

Store::Store() {
  weapon[0] = new Sword(100, 11, "Honor's Call (Sword)");
  weapon[1] = new Sword(500, 25, "Devourer of Light (Sword)");
  weapon[2] = new Sword(1000, 50, "Blade of the Shadow Lord (Sword)");
  weapon[3] = new Axe(50, 12, "Claimer of Skulls (Axe)");
  weapon[4] = new Axe(150, 18, "Conquerer of Cont (Axe)");
  weapon[5] = new Axe(700, 40, "Wrathgiver (Axe)");

  items[0] = Item("Venison", 10, 5);
  items[1] = Item("Healing Tea", 20, 10);
  items[2] = Item("Blessing of Petra", 25, 12);
  items[3] = Item("Dark Armor", 50, 20);
  items[4] = Item("Armor of Retribution", 250, 50);
  items[5] = Item("Armor of the Shadow Lord", 10000, 2500);
}

// Destructor so Weapons can be deleted
Store::~Store() {
  for(int i = 0; i < 6; i++) {
    delete weapon[i];
  }
}

void Store::shopMenu(Character& c) {
  char ans1;
  cout << "Welcome to the Store! \n\n";
  do {
  cout << "Options:\n[What's in stock?] - 1\n[Buy Weapons] - 2\n[Buy Items] - 3\n\n";
  cin >> ans1;
  cout << "\n\n";
    
    // Allow the hero to gain background on the Store
  if(ans1 == '1') {
    cout << "Yes my Lord! We have swords and axes that bare a significant history. We also have armor that will increase your max health and items that will allow you to gain health.\n\n";
  }
}while(ans1 == '1');

  if(ans1 == '2') {
    buyWeapons(c);
  } else if(ans1 == '3') {
    buyItems(c);
  }
}

// Function if user wishes to buy weapons
void Store::buyWeapons(Character& c) {
    char ans2;
  for(int i = 0; i < 6; i++) {
      cout << i << "-Name: " << weapon[i]->getName() << " | Damage: " << weapon[i]->getDamage() << " | Price: " << weapon[i]->getPrice() << "\n\n";
    }
    
    cout << "Press the corresponding number in order to buy the item you want.\n\n";
    cin >> ans2;
cout << "\n\n";
    cout << "Money: " << c.getMoney() << "\n\n";
    // This section of the code is the purchase algorithm
    if(ans2 == '0' && c.getMoney() >= weapon[0]->getPrice()) {
      // Here, I have created variables that will hold the parameters from the Weapon*, and then assign then to the plain object Sword
      int p = weapon[0]->getPrice();
      double d = weapon[0]->getDamage();
      string n = weapon[0]->getName();
      Sword s1(p, d, n);
      c.setWeapon(s1);
      cout << "You have bought " << s1.getName() << "!\n\n";
      int newMoney = c.getMoney() - s1.getPrice();
      c.setMoney(newMoney);
      cout << "Money: " << c.getMoney() << "\n\n";
    }
    else if (ans2 == '0' && c.getMoney() < weapon[0]->getPrice()) {
      cout << "You cannot afford this item.\n\n";
    }

    // ---------------------------------------------------------
    
    else if(ans2 == '1' && c.getMoney() >= weapon[1]->getPrice()) {
      int p = weapon[1]->getPrice();
      double d = weapon[1]->getDamage();
      string n = weapon[1]->getName();
      Sword s1(p, d, n);
      c.setWeapon(s1);
      cout << "You have bought " << s1.getName() << "!\n\n";
      int newMoney = c.getMoney() - s1.getPrice();
      c.setMoney(newMoney);
      cout << "Money: " << c.getMoney() << "\n\n";
    } else if(ans2 == '1' && c.getMoney() < weapon[1]->getPrice()) {
      cout << "You cannot afford this item.\n\n";
    }

    // ---------------------------------------------------------

    else if(ans2 == '2' && c.getMoney() >= weapon[2]->getPrice()) {
      int p = weapon[2]->getPrice();
      double d = weapon[2]->getDamage();
      string n = weapon[2]->getName();
      Sword s1(p, d, n);
      c.setWeapon(s1);
      cout << "You have bought " << s1.getName() << "!\n\n";
      int newMoney = c.getMoney() - s1.getPrice();
      c.setMoney(newMoney);
      cout << "Money: " << c.getMoney() << "\n\n";
    } else if(ans2 == '2' && c.getMoney() < weapon[2]->getPrice()) {
      cout << "You cannot afford this item.\n\n";
    }

    // ---------------------------------------------------------

    else if(ans2 == '3' && c.getMoney() >= weapon[3]->getPrice()) {
      int p = weapon[3]->getPrice();
      double d = weapon[3]->getDamage();
      string n = weapon[3]->getName();
      Axe a1(p, d, n);
      c.setWeapon(a1);
      cout << "You have bought " << a1.getName() << "!\n\n";
      int newMoney = c.getMoney() - a1.getPrice();
      c.setMoney(newMoney);
      cout << "Money: " << c.getMoney() << "\n\n";
    } else if(ans2 == '3' && c.getMoney() < weapon[3]->getPrice()) {
      cout << "You cannot afford this item.\n\n";
    }

    // ---------------------------------------------------------

    else if(ans2 == '4' && c.getMoney() >= weapon[4]->getPrice()) {
      int p = weapon[4]->getPrice();
      double d = weapon[4]->getDamage();
      string n = weapon[4]->getName();
      Axe a1(p, d, n);
      c.setWeapon(a1);
      cout << "You have bought " << a1.getName() << "!\n\n";
      int newMoney = c.getMoney() - a1.getPrice();
      c.setMoney(newMoney);
      cout << "Money: " << c.getMoney() << "\n\n";
    } else if(ans2 == '4' && c.getMoney() < weapon[4]->getPrice()) {
      cout << "You cannot afford this item.\n\n";
    }

      // -------------------------------------------------------

    else if(ans2 == '5' && c.getMoney() >= weapon[5]->getPrice()) {
      int p = weapon[5]->getPrice();
      double d = weapon[5]->getDamage();
      string n = weapon[5]->getName();
      Axe a1(p, d, n);
      c.setWeapon(a1);
      cout << "You have bought " << a1.getName() << "!\n\n";
      int newMoney = c.getMoney() - a1.getPrice();
      c.setMoney(newMoney);
      cout << "Money: " << c.getMoney() << "\n\n";
    } else if (ans2 == '5' && c.getMoney() < weapon[5]->getPrice()) {
      cout << "You cannot afford this item.\n\n";
    }
}

// Function if user wishes to buy items
void Store::buyItems(Character& c) {
  char ans3;
  for(int i = 0; i < 6; i++) {
    cout << i << "-Name: " << items[i].getName() << " | Health: " << items[i].getHealth() << " | Price: " << items[i].getPrice() << "\n\n";
  }
 cout << "Press the corresponding number in order to buy the item you want.\n\n";
    cin >> ans3;
cout << "\n\n";
    cout << "Money: " << c.getMoney() << "\n\n";
if(ans3 == '0' && c.getMoney() >= items[0].getPrice()) {
  double newHealth = c.getHealth() + items[0].getHealth();
  c.setHealth(newHealth);
  int newMoney = c.getMoney() - items[0].getPrice();
  c.setMoney(newMoney);
  cout << "You have bought " << items[0].getName() << "!\n\n";
  cout << "Money: " << c.getMoney() << "\n\n";
} else if(ans3 == '0' && c.getMoney() < items[0].getPrice()) {
  cout << "You cannot afford this item.\n\n";
  
} else if(ans3 == '1' && c.getMoney() >= items[1].getPrice()) {
  double newHealth = c.getHealth() + items[1].getHealth();
  c.setHealth(newHealth);
  int newMoney = c.getMoney() - items[1].getPrice();
  c.setMoney(newMoney);
  cout << "You have bought " << items[1].getName() << "!\n\n";
  cout << "Money: " << c.getMoney() << "\n\n";
} else if(ans3 == '1' && c.getMoney() < items[1].getPrice()) {
  cout << "You cannot afford this item.\n\n";
  
  }  else if(ans3 == '2' && c.getMoney() >= items[2].getPrice()) {
  double newHealth = c.getHealth() + items[2].getHealth();
  c.setHealth(newHealth);
  int newMoney = c.getMoney() - items[2].getPrice();
  c.setMoney(newMoney);
  cout << "You have bought " << items[2].getName() << "!\n\n";
  cout << "Money: " << c.getMoney() << "\n\n";
} else if(ans3 == '2' && c.getMoney() < items[2].getPrice()) {
  cout << "You cannot afford this item.\n\n";
  
  }  else if(ans3 == '3' && c.getMoney() >= items[3].getPrice()) {
  double newHealth = c.getHealth() + items[3].getHealth();
  c.setHealth(newHealth);
  int newMoney = c.getMoney() - items[3].getPrice();
  c.setMoney(newMoney);
  cout << "You have bought " << items[3].getName() << "!\n\n";
  cout << "Money: " << c.getMoney() << "\n\n";
} else if(ans3 == '3' && c.getMoney() < items[3].getPrice()) {
  cout << "You cannot afford this item.\n\n";
  
  }  else if(ans3 == '4' && c.getMoney() >= items[4].getPrice()) {
  double newHealth = c.getHealth() + items[4].getHealth();
  c.setHealth(newHealth);
  int newMoney = c.getMoney() - items[4].getPrice();
  c.setMoney(newMoney);
  cout << "You have bought " << items[4].getName() << "!\n\n";
  cout << "Money: " << c.getMoney() << "\n\n";
} else if(ans3 == '4' && c.getMoney() < items[4].getPrice()) {
  cout << "You cannot afford this item.\n\n";
  
  }  else if(ans3 == '5' && c.getMoney() >= items[5].getPrice()) {
  double newHealth = c.getHealth() + items[5].getHealth();
  c.setHealth(newHealth);
  int newMoney = c.getMoney() - items[5].getPrice();
  c.setMoney(newMoney);
  cout << "You have bought " << items[5].getName() << "!\n\n";
  cout << "Money: " << c.getMoney() << "\n\n";
} else if(ans3 == '5' && c.getMoney() < items[5].getPrice()) {
  cout << "You cannot afford this item.\n\n";
  }

}
#endif