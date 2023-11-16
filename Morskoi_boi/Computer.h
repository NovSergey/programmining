#pragma once
#include "Map.h"
#include "Ship.h"
#include <string>
#include <stdlib.h>
#include "time.h"
using namespace std;
struct Computer {
	Computer(){}
	Computer(char status_) : status{ status_ } {

	}
public:
	vector<pair<char, int>> buffer_points;

	void createShip(Map* m, int sizeShip) {
		srand(time(NULL));
		Ship ship;
		while (m->add_ship(ship, ships) == false) {
			vector<pair<char, int>> data;
			pair<char, int> random_point = { rand() % 10 + 65,rand() % 10 + 1 };
			data.push_back(random_point);
			auto random_path = rand() % 2;
			switch (random_path)
			{
			case 0:
				for (int i = 1; i < sizeShip; i++) {
					data.push_back({ random_point.first, random_point.second+i});
				}
				break;
			case 1:
				for (int i = 1; i < sizeShip; i++) {
					data.push_back({ random_point.first+i, random_point.second});
				}
				break;
			default:
				break;
			}
			
			ship = Ship(status, data);				
		}
		ships.push_back(ship);
	}
	vector<Ship> ships;
	char status;
};