#include "ParkingLot.h"

ParkingLot::ParkingLot(int id, Vertex<Node> *node, string name, float price,
		int isGarage, int lotation) {
	this->id = id;
	this->node = &node;
	this->name = name;
	this->price = price;
	this->capacity = lotation;

	if (isGarage)
		this->isGarage = true;
	else
		this->isGarage = false;

	this->capacity = 0; //TODO: change this
}

ParkingLot::~ParkingLot() {
}

int ParkingLot::getID() {
	return this->id;
}

Vertex<Node>* ParkingLot::getNode() {
	return this->node;
}

string ParkingLot::getName() {
	return this->name;
}

float ParkingLot::getPrice() {
	return this->price;
}

bool ParkingLot::getIsGarage() {
	return this->isGarage;
}

int ParkingLot::getCapacity() {
	return this->capacity;
}

void ParkingLot::setCapacity(int num) {
	this->capacity = num;
}
