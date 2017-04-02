#include "ParkingLot.h"

ParkingLot::ParkingLot()
{
}

ParkingLot::ParkingLot(int id, Vertex<Node> *node, string name, float price, int isGarage)
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

int ParkingLot::getID()
{
	return this->id;
}

Vertex<Node>* ParkingLot::getNode()
{
	return this->node;
}

string ParkingLot::getName()
{
	return this->name;
}

float ParkingLot::getPrice()
{
	return this->price;
}

bool ParkingLot::getIsGarage()
{
	return this->isGarage;
}
