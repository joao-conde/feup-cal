#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class ParkingLot
{
private:

	int id;
	string name;
	Node node;
	float price;

public:
	ParkingLot();
	~ParkingLot();
};

