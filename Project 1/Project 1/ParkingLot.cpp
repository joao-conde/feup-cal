#include "ParkingLot.h"



ParkingLot::ParkingLot()
{
}

ParkingLot::ParkingLot(int id, int node, string name, float price, int isGarage)
{
	this->id = id;
	this->node = node;
	this->name = name;
	this->price = price;

	if (isGarage)
		this->isGarage = true;
	else 
		this->isGarage = false;
}


ParkingLot::~ParkingLot()
{
}
