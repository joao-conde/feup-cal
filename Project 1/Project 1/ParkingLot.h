#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class ParkingLot
{
private:

	int id;
	int node; //TODO: alterar no
	string name;
	float price;
	bool isGarage;

public:
	ParkingLot();
	ParkingLot(int id, int node, string name, float price, int isGarage);
	~ParkingLot();
};

