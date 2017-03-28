#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Graph.h"
#include "Local.h"
#include "Node.h"
#include "ParkingLot.h"
#include "Street.h"

class Manager
{

private:
	static Manager* singleton_instance;

	vector<Vertex<Node>*> vecNodes;
	vector<Edge<Node>*> vecEdges;
	vector<ParkingLot> vecParking;
	vector<Street> vecStreets;

public:
	Manager();
	~Manager();

	static Manager* instance()
	{
		if (!singleton_instance)
			singleton_instance = new Manager;

		return singleton_instance;
	}

	/*
	* LOAD DATA
	*/

	void loadEdges();
	void loadNodes();
	void loadParkingLot();
	void loadStreets();
	void loadData();
};

