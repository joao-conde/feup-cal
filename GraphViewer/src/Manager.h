#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "Graph.h"
#include "Local.h"
#include "Node.h"
#include "ParkingLot.h"
#include "Street.h"
#include "graphviewer.h"

class Manager
{

private:
	static Manager* singleton_instance;

	//vector<Vertex<Node>*> vecNodes;
	//vector<Edge<Node>*> vecEdges;
	vector<ParkingLot> vecParking;
	vector<Street> vecStreets;

	GraphViewer *gv;
	Graph<Node> myGraph;

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

	/*
	* DISPLAY DATA - for testing
	*/

	void displayInfo();
	void printGraphFromVectors();
};

