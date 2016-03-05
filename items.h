#include <iostream>
#include <string>

using namespace std;

class Item {
	int numItems;
	string itemName;
public:
	Item(int n, string name);
	void setNumItems(int n);
	int getNumItems();
	string getItemName();
};

Item::Item(int n, string name) {
	numItems = n;
	itemName = name;
}

void Item::setNumItems(int n) {
	numItems = n;
}

int Item::getNumItems() {
	return numItems;
}

string Item::getItemName() {
	return itemName;
}

class Coinage : public Item {
	int copper, silver, electrum, gold, platinum, sumCoin, valueInCopper;
public:
	Coinage(int n, string name, int c, int s, int e, int g, int p);
	void setValueInCopper();
	void setCopper(int c);
	void setSilver(int s);
	void setElectrum(int e);
	void setGold(int g);
	void setPlatinum(int p);
	int getValueInCopper();
	int getCopper();
	int getSilver();
	int getElectrum();
	int getGold();
	int getPlatinum();
	void convertCopper();
	void convertSilver();
	void convertElectrum();
	void convertGold();
};

Coinage::Coinage(int n, string name, int c, int s, int e, int g, int p) : Item(n, name) {
	copper = c;
	silver = s;
	electrum = e;
	gold = g;
	platinum = p;
	sumCoin = copper + silver + electrum + gold + platinum;
	valueInCopper = copper + silver*10 + electrum*50 + gold*100 + platinum*1000;
}

void Coinage::setValueInCopper() {
	valueInCopper = copper + silver*10 + electrum*50 + gold*100 + platinum*1000;
}

void Coinage::setCopper(int c) {
	copper = c;
}

void Coinage::setSilver(int s) {
	silver = s;
}

void Coinage::setElectrum(int e) {
	electrum = e;
}

void Coinage::setGold(int g) {
	gold = g;
}

void Coinage::setPlatinum(int p) {
	platinum = p;
}

int Coinage::getValueInCopper() {
	return valueInCopper;
}

int Coinage::getCopper() {
	return copper;
}

int Coinage::getSilver() {
	return silver;
}

int Coinage::getElectrum() {
	return electrum;
}

int Coinage::getGold() {
	return gold;
}

int Coinage::getPlatinum() {
	return platinum;
}

void Coinage::convertCopper() {
	if (copper >= 10) {
		if (copper >= 10 && copper < 50) {
			silver += copper / 10;
			copper = copper % 10;
		}
		if (copper >= 50 && copper < 100) {
			electrum += copper / 50;
			copper = copper % 50;
			if (copper >= 10 && copper < 50) {
				silver += copper / 10;
				copper = copper % 10;
			}
		}
		if (copper >= 100 && copper < 1000) {
			gold += copper / 100;
			copper = copper % 100;
			if (copper >= 50 && copper < 100) {
				electrum += copper / 50;
				copper = copper % 50;
			}
			if (copper >= 10 && copper < 50) {
				silver += copper / 10;
				copper = copper % 10;
			}
		}
		if (copper >= 1000) {
			platinum += copper / 1000;
			copper = copper % 1000;
			if (copper >= 100 && copper < 1000) {
				gold += copper / 100;
				copper = copper % 100;
			}
			if (copper >= 50 && copper < 100) {
				electrum += copper / 50;
				copper = copper % 50;
			}
			if (copper >= 10 && copper < 50) {
				silver += copper / 10;
				copper = copper % 10;
			}
		}
		sumCoin = copper + silver + electrum + gold + platinum;
		setNumItems(sumCoin);
	}
	else {
		cout << "Amount too low to convert" << endl;
	}
}

void Coinage::convertSilver() {
	if (silver >= 5) {
		if (silver >= 5 && silver < 10) {
			electrum += silver / 5;
			silver = silver % 5;
		}
		if (silver >= 10 && silver < 100) {
			gold += silver / 10;
			silver = silver % 10;
			if (silver >= 5 && silver < 10) {
				electrum += silver / 5;
				silver = silver % 5;
			}
		}
		if (silver >= 100) {
			platinum += silver / 100;
			silver = silver % 100;
			if (silver >= 10 && silver < 100) {
				gold += silver / 10;
				silver = silver % 10;
			}
			if (silver >= 5 && silver < 10) {
				electrum += silver / 5;
				silver = silver % 5;
			}
		}
		sumCoin = copper + silver + electrum + gold + platinum;
		setNumItems(sumCoin);
	}
	else {
		cout << "Amount too low to convert" << endl;
	}
}

void Coinage::convertElectrum() {
	if (electrum >= 2) {
		if (electrum >= 2 && electrum < 20) {
			gold += electrum / 2;
			electrum = electrum % 2;
		}
		if (electrum >= 20) {
			platinum += electrum / 20;
			electrum = electrum % 20;
			if (electrum >= 2 && electrum < 20) {
				gold += electrum / 2;
				electrum = electrum % 2;
			}
		}
		sumCoin = copper + silver + electrum + gold + platinum;
		setNumItems(sumCoin);
	}
	else {
		cout << "Amount too low to convert" << endl;
	}
}

void Coinage::convertGold() {
	if (gold >= 10) {
		platinum += gold / 10;
		gold = gold % 10;
		sumCoin = copper + silver + electrum + gold + platinum;
		setNumItems(sumCoin);
	}
	else {
		cout << "Amount too low to convert" << endl;
	}
}

class Armor: public Item {
	int cost, armorClass, weight;
	bool stealth;
public:
	Armor(int n, string name, int c, int AC, bool s, int w);
	int getCost();
	int getArmorClass();
	bool getStealth();
	int getWeight();
};

Armor::Armor(int n, string name, int c, int AC, bool s, int w) : Item(n, name) {
	cost = c;
	armorClass = AC;
	stealth = s;
	weight = w;
}

int Armor::getCost() {
	return cost;
}

int Armor::getArmorClass() {
	return armorClass;
}

bool Armor::getStealth() {
	return stealth;
}

int Armor::getWeight() {
	return weight;
}

class Weapon : public Item {
	int cost, damage, weight;
	bool isRanged;
public:
	Weapon(int n, string name, int c, int d, int w, bool r);
	int getCost();
	int getDamage();
	int getWeight();
	bool getRange();
};

Weapon::Weapon(int n, string name, int c, int d, int w, bool r) : Item(n, name) {
	cost = c;
	damage = d;
	weight = w;
	isRanged = r;
}

int Weapon::getCost() {
	return cost;
}

int Weapon::getDamage() {
	return damage;
}

int Weapon::getWeight() {
	return weight;
}

bool Weapon::getRange() {
	return isRanged;
}