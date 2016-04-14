#ifndef DICEUTILITY_ITEMS_H
#define DICEUTILITY_ITEMS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Item {
	int numItems;
	string itemName;
public:
	Item(int n, string name) {
		numItems = n;
		itemName = name;
	}
	void setNumItems(int n) {
		numItems = n;
	}
	int getNumItems() {
		return numItems;
	}
	string getItemName() {
		return itemName;
	}
	virtual string getValues() = 0;
};

class Coinage : public Item {
	int copper, silver, electrum, gold, platinum, sumCoin, valueInCopper;
public:
	Coinage(int n, string name, int c, int s, int e, int g, int p) : Item(n, name) {
		copper = c;
		silver = s;
		electrum = e;
		gold = g;
		platinum = p;
		sumCoin = copper + silver + electrum + gold + platinum;
		valueInCopper = copper + silver * 10 + electrum * 50 + gold * 100 + platinum * 1000;
	}
	void setValueInCopper() {
		valueInCopper = copper + silver * 10 + electrum * 50 + gold * 100 + platinum * 1000;
	}
	void setCopper(int c) {
		copper = c;
	}
	void setSilver(int s) {
		silver = s;
	}
	void setElectrum(int e) {
		electrum = e;
	}
	void setGold(int g) {
		gold = g;
	}
	void setPlatinum(int p) {
		platinum = p;
	}
	int getValueInCopper() {
		return valueInCopper;
	}
	int getCopper() {
		return copper;
	}
	int getSilver() {
		return silver;
	};
	int getElectrum() {
		return electrum;
	}
	int getGold() {
		return gold;
	}
	int getPlatinum() {
		return platinum;
	}
	string getValues() override {
		stringstream sstr;
		sstr << getItemName() << "\n" << "Copper: " << copper << "\n" << "Silver: " << silver << "\n" <<
			"Electrum: " << electrum << "\n" << "Gold: " << gold << "\n" <<
			"Platinum: " << platinum << "\n" << "Total value in copper: " << getValueInCopper() << "\n" << endl;
		return sstr.str();
	}
	void convertCopper() {
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
	void convertSilver() {
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
	void convertElectrum() {
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
	void convertGold() {
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
};

class Armor : public Item {
	int cost, armorClass, weight;
	bool stealth;
public:
	Armor(int n, string name, int c, int AC, bool s, int w) : Item(n, name) {
		cost = c;
		armorClass = AC;
		stealth = s;
		weight = w;
	}
	int getCost() {
		return cost;
	}
	int getArmorClass() {
		return armorClass;
	}
	bool getStealth() {
		return stealth;
	}
	int getWeight() {
		return weight;
	}
	string getValues() override {
		stringstream sstr;
		sstr << getItemName() << "\n" << "Cost: " << cost << "\n" << "Armor Class: " << armorClass << "\n" <<
			"Stealth: " << stealth << "\n" << "Weight: " << weight << "\n" << endl;
		return sstr.str();
	}
};

class Weapon : public Item {
	int cost, damage, weight;
	bool isRanged;
public:
	Weapon(int n, string name, int c, int d, int w, bool r) : Item(n, name) {
		cost = c;
		damage = d;
		weight = w;
		isRanged = r;
	}
	int getCost() {
		return cost;
	}
	int getDamage() {
		return damage;
	}
	int getWeight() {
		return weight;
	}
	bool getRange() {
		return isRanged;
	}
	string getValues() override {
		stringstream sstr;
		sstr << getItemName() << "\n" << "Cost: " << cost << "\n" << "Damage: " << damage << "\n" <<
			"Weight: " << weight << "\n" << "Ranged: " << isRanged << "\n" << endl;
		return sstr.str();
	}
};

class Gear : public Item {
	int cost, weight;
	string description;
public:
	Gear(int n, string name, int c, int w, string d) : Item(n, name) {
		cost = c;
		weight = w;
		description = d;
	}
	void setDescription(string d) {
		description = d;
	}
	int getCost() {
		return cost;
	}
	int getWeight() {
		return weight;
	}
	string getValues() override {
		stringstream sstr;
		sstr << getItemName() << "\n" << "Cost: " << cost << "\n" << "Weight: " << weight << "\n" <<
			"Description: " << description << "\n" << endl;
		return sstr.str();
	}
};

class ItemList {
	vector<Item*> itemList;
public:
	void addItem(Item* i) {
		itemList.push_back(i);
	}
	void removeItem() {
		if(itemList.size() != 0) {
			itemList.pop_back();
		} else {
			cout << "There are no items in inventory." << endl;
		}
	}
	int getNumItems() {
		return itemList.size();
	}
	void getValues() {
		for (int i = 0; i < itemList.size(); i++) {
			cout << itemList[i]->getValues() << endl;
		}
	}
};

#endif DUNGEONUTILITY_ITEMS_H 