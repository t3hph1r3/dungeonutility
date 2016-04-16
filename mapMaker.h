#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include <vector>

struct map
{
	int size;
	int mapArray[26][26];
	int terrainChoice;

	void viewer(int userSize, int choice)
	{
		size = userSize;
		terrainChoice = choice;
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; i < 26; j++)
				mapArray[i][j] = -1;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				mapArray[i][j] = terrainChoice - 1;
		}
	}
};

void mapMaker::mainMenu()
{
	int choice;
	std::cout << "Map Menu:" << std::endl;
	std::cout << "1. Create New Map" << std::endl;
	std::cout << "2. View Map" << std::endl;
	std::cout << "3. Edit Tiles" << std::endl;
	std::cout << "4. Check Distance" << std::endl;
	std::cout << "5. Return to Main Menu" << std::endl;
	//Make sure to include error checking later

	std::cin >> choice;

	switch (choice)
	{
	case 1:
		mapMaker::newMapMenu();
		break;
	case 2:
		viewMap();
		break;
	case 3:
		editMap();
		break;
	case 4:
		distance();
		break;
	case 5:
		mapMaker::quit = true;
		break;
	default:
		std::cout << "Invalid option, please try again" << std::endl;
		mainMenu();
		break;

	}
}

void mapMaker::distance()
{
	std::cout << "Enter coordinates of two tiles separated by enter (ex. A 5 or H 26)" << std::endl;
	int coordCount = 0;
	while (coordCount < 2)
	{
		std::string temp;
		std::cin >> temp;
		bool noGood = false;
		while (!noGood)
		{
			if (temp.length() == 3 || temp.length() == 4)
			{
				noGood = true;
				std::vector<std::string> coord;
				std::string coords;
				//while (std::getline(temp, coords, ' '))
				//{
				//	coord.push_back(coords);
				//}
			}
			else
			{
				std::cout << "Invalid input, please enter a two-perameter coordinate separated by a space (ex. 'A 5' or 'H 25)" << std::endl;
				std::cin >> temp;
			}
		}

		coordCount++;
	}
}

void mapMaker::newMapMenu()
{
	std::cout << "New Map Terrain Options:" << std::endl;
	std::cout << "1. Clear" << std::endl;
	std::cout << "2. Forest" << std::endl;
	std::cout << "3. Desert" << std::endl;
	std::cout << "4. Back To Map Menu" << std::endl;
	int choice;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		mapMaker::newMap(choice);
		break;
	case 2:
		mapMaker::newMap(choice);
		break;
	case 3:
		mapMaker::newMap(choice);
		break;
	case 4:
		mapMaker::mainMenu();
		break;
	default:
		std::cout << "invalid option, please try again" << std::endl;
		mapMaker::newMapMenu();
		break;
	}
}

void mapMaker::newMap(int terrain)
{
	struct map *userMap = new map;
	userMap->size = 5;
}


//Map editor
void mapMaker::editMap()
{
	std::cout << "Enter coordinates of tile(s) separated by enter then followed by 'stop'" << std::endl;
	std::cout << "                                  OR                                   " << std::endl;
	std::cout << "            Type 'square' for a square select, then enter " << std::endl;

	bool letsStop = false;
	int arrayCount = 0;
	std::string editCoords[676];
	std::string temp;

	//Check if program should stop taking data
	while (!letsStop)
	{
		std::cin >> temp;
		bool noGood = false;
		//Make sure data is valid
		while (!noGood)
		{
			if (temp == "stop")
			{
				letsStop = true;
				noGood = true;
			}
			else if (temp.length() == 3 || temp.length() == 4)
			{
				noGood = true;
				std::vector<std::string> coord;
				std::string coords;
				//while (std::getline(temp, coords, ' '))
				//{
				//	coord.push_back(coords);
				//}
			}
			else if (temp == "square")
			{
				noGood = true;
				std::vector<std::string> coord;
				std::string coords;
				//while (std::getline(temp, coords, ' '))
				//{
				//	coord.push_back(coords);
				//}
			}
			else
			{
				std::cout << "Invalid input, please enter a two-perameter coordinate separated by a space (ex. 'A 5' or 'H 25)" << std::endl;
				std::cin >> temp;
			}
		}
		arrayCount++;
	}

	std::cout << "Terrain Options:" << std::endl;
	std::cout << "1.  Open" << std::endl;
	std::cout << "2.  Forest" << std::endl;
	std::cout << "3.  Mountain" << std::endl;
	std::cout << "4.  River" << std::endl;
	std::cout << "5.  Swamp" << std::endl;
	std::cout << "6.  Ford" << std::endl;
	std::cout << "7.  Catch-Basin" << std::endl;
	std::cout << "8.  Base" << std::endl;
	std::cout << "9.  Food Source" << std::endl;
	std::cout << "10. Trail" << std::endl;
	std::cout << "11. Back To Map Menu" << std::endl;

	int choice;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		//mapMaker::newMap(choice);
		break;
	case 2:
		//mapMaker::newMap(choice);
		break;
	case 3:
		//mapMaker::newMap(choice);
		break;
	case 4:
		//mapMaker::mainMenu();
		break;
	case 5:
		//mapMaker::mainMenu();
		break;
	case 6:
		//mapMaker::mainMenu();
		break;
	case 7:
		//mapMaker::mainMenu();
		break;
	case 8:
		//mapMaker::mainMenu();
		break;
	case 9:
		//mapMaker::mainMenu();
		break;
	case 10:
		//mapMaker::mainMenu();
		break;
	default:
		std::cout << "invalid option, please try again" << std::endl;
		mapMaker::newMapMenu();
		break;
	}
}

void mapMaker::viewMap()
{
	if (mapMaker::hasMap = -1)
	{

	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{

		}
	}
}



class mapMaker
{
private:
	int playerCoord;
	int terrainMod;
	int coordinates[676];
	bool hasMap;
	bool quit;

public:
	//int getCoord();
	//void setCoord(int x, int y);
	void mainMenu();
	void newMapMenu();
	void newMap(int terrain);
	void viewMap();
	void editMap();
	void distance();
	//bool getQuit();
	//void setQuit(bool quit);
	//void findDist(int x, int y);
	const int feetPerUnit = 5;

	//corresponding arrays for movement coordinates
	std::string alphaCoords[26] = { "A", "B", "C", "D", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
	int numCoords[26] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	std::string strCoords[26] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26" };

	//corresponding arrays for terrains and their movement effects
	std::string terrain[11] = { "Clear", "Forest", "Desert", "Mountain", "River", "Swamp", "Ford", "Catch-Basin", "Base", "Food Source", "Trail" };
	int movValue[11] = { 1, 2, 2, 3, 3, 4, 1, -1, -1, -1, 1 };

	//cycles through the main menu while
	//isFalse = getQuit();
	//mapMaker::hasMap = false;
	//while (!isFalse)

	void mapMaker::mainMenu();

};
