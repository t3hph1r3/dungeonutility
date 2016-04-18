#include <iostream>
#include <string>
#include "items.h"
#include "dice.h"
#include "Characters.h"


using namespace std;



int main() {
	Character *characterArray[5];
	int numOfCharacter = 0;
	while (true){

		int choice = 0;
		cout << "\nWhat would you like to do?" << endl;
		cout << "\n(1) Environment Generation" << endl;
		cout << "(2) Random Encounter Generation" << endl;
		cout << "(3) Character Generaton" << endl;
		cout << "(4) Display Character Information" << endl;
		cout << "(5) Load/Save Game" << endl;
		cout << "(6) Dice Roller" << endl;
		cout << "(7) Exit." << endl;
		cout << "\nChoice: ";
		cin >> choice;

		if(cin.fail() || choice > 7 || choice < 1 || !cin){
			while (!cin || choice > 7 || choice < 1 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid input!" << endl;
				cout << "What would you like to do?" << endl;
				cin >> choice;
			}
		}
		if (choice == 1) {
			//mapMaker::mainMenu();
		}
		if (choice == 2) {

		}
		if (choice == 3) {
			if (numOfCharacter == 0){
				cout << "\nHow many characters would you like to create? (1 to 5 characters are allowed)" << endl;
				cout << "\nChoice: ";
				cin >> numOfCharacter;
				while (!cin || numOfCharacter > 5 || numOfCharacter < 1 || cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nInvalid Input!" << endl;
					cout << "How many characters would you like to create? (1 to 5 characters are allowed)" << endl;
					cout << "\nChoice: ";
					cin >> numOfCharacter;
				}
				for (int i = 0; i < numOfCharacter; i++) {
					characterArray[i] = new Character();
				}
			}
			else if (numOfCharacter < 5) {
				int x;
				cout << "\nWould you like to add an additional character?" << endl;
				cout << "(1) Yes\n(2) No" << endl;
				cout << "\nChoice: ";
				cin >> x;
				if (x == 1) {
					characterArray[numOfCharacter] = new Character();
					numOfCharacter += 1;
				}
			}
			else {
				cout << "You already have the maximum amount of characters! (5 characters)" << endl;
			}
		}
		if (choice == 4) {
			if (numOfCharacter > 0){
				for (int i = 0; i < numOfCharacter; i++) {
					cout<< "(" << i+1 << ") " << characterArray[i]->getName() << "\n";
				}
				cout << "Which charcater would you like to see info for?" << endl;
				int charChoice;
				cout << "Choice: ";
				cin >> charChoice;
				while (!cin || charChoice < 1 || charChoice > numOfCharacter || cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nInvalid Input!" << endl;
					cout << "What charcater would you like to see info for?" << endl;
					cout << "\nChoice: ";
					cin >> charChoice;
				}
				characterArray[charChoice - 1]->charInfo();
				characterArray[charChoice - 1]->displayStats();
			}
			else {
				cout << "You haven't made your characters yet!" << endl;
			}
		}
		if (choice == 5) {
			int x;
			cout << "What would you like to do?\n(1) Load\n(2) Save \n\nChoice: ";
			cin >> x;
			while (!cin || x > 2 || x < 1 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid input!" << endl;
				cout << "What would you like to do?" << endl;
				cin >> x;
			}
			if (x == 1) {
				string charName;
				cout << "To load a character, type its name. (Case Sensitive)" << endl;
				cout << "Name : ";
				cin >> charName;
				if (numOfCharacter == 0) {
					numOfCharacter++;
					characterArray[numOfCharacter-1]->loadCharacter(charName);
				}
				else if (numOfCharacter >= 1 && numOfCharacter < 5) {
					numOfCharacter++;
					characterArray[numOfCharacter-1]->loadCharacter(charName);
				}
				else {
					cout << "You have already reached the maximum amount of characters." << endl;
				}
			}
			if (x == 2) {
				if (numOfCharacter > 0) {
					for (int i = 0; i < numOfCharacter; i++) {
						cout << "(" << i + 1 << ") " << characterArray[i]->getName() << "\n";
						characterArray[i]->saveCharacter();
					}
					cout << "The characters listed above were saved to individual text files." << endl;
				}
				if (numOfCharacter == 0) {
					cout << "You have no characters to save!" << endl;
					cout << "Nothing will be saved." << endl;
				}
			}
		}
		if (choice == 6) {
			int sides;
			int times;
			int modifiers;
			int roll = 0;
			cout << "\nHow many sides would you like your dice to have? (1 to 100)" << endl;
			cout << "\nChoice: ";
			cin >> sides;
			while (!cin || sides < 1 || sides > 100 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid Input!" << endl;
				cout << "How many sides would you like your dice to have? (1 to 100)" << endl;
				cout << "\nChoice: ";
				cin >> sides;
			}
			cout << "\nHow many times would you like to roll the dice? (1 to 30)" << endl;
			cout << "\nChoice: ";
			cin >> times;
			while (!cin || times < 1 || times > 30 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid Input!" << endl;
				cout << "\nHow many times would you like to roll the dice?" << endl;
				cout << "\nChoice: ";
				cin >> times;
			}
			cout << "\nWould you like to include any of the following modifiers?" << endl;
			cout << "(1) Add 2 points to the total." << endl;
			cout << "(2) Add 2 points to each roll." << endl;
			cout << "(3) No modifiers." << endl;
			cout << "\nChoice: ";
			cin >> modifiers;
			while (!cin || modifiers < 1 || modifiers > 3 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid Input!" << endl;
				cout << "Which modifier option will you choose?" << endl;
				cout << "\nChoice: ";
				cin >> modifiers;
			}
			int* yourRoll = Dice::rollMore(times, sides);
			for (int i = 0; i < times; i++) {
				roll += yourRoll[i];
			}
			if (modifiers == 1) {
				roll += 2;
			}
			if (modifiers == 2) {
				roll += (2 * times);
			}
			cout << "\nYou rolled d(" << sides << ") " << times << " times. Your total roll was " << roll << "." << endl;
		}
		if (choice == 7) {
			cout << "Goodbye." << endl;
			break;
		}
	}
}

