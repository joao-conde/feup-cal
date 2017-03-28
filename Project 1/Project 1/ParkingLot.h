#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include "Graph.h"

using namespace std;

class ParkingLot
{
private:

	int id;
	Vertex<Node> *node;
	string name;
	float price;
	bool isGarage;

public:
	ParkingLot();
	ParkingLot(int id, Vertex<Node> *node, string name, float price, int isGarage);
	~ParkingLot();

	int getID();
	Vertex<Node> *getNode();
	string getName();
	float getPrice();
	bool isGarage();
};

