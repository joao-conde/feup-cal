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
	vector<Node> vecNodes;
	vector<ParkingLot> vecParking;
	vector<Street> vecStreets;
	vector<Vertex <Node>*> vecPetrolStations;
	vector<Vertex<Node>*> vecMetroStations;

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
	void loadPetrolStations();
	void loadMetroStations();
	void loadData();

	bool isParkingLot(int idNo);
	bool isPetrolStation(int idNo);
	bool isMetroStation(int idNo);
	void printGraph();

	vector<Node> insertValues();
	vector<Node> calculatePath(int sourceID, int destID, int maxDistance,  char Cheap_Near, char passPetrolStation);
	Node getNodeByID(int id);
	vector <Node> getShortestPath(int source, int dest);
	Node parkNear(int id, int maxDistance);
	Node parkCheap(int id, int maxDistance);
	Node petrolNear(int id);
	void addPetrolToPath(vector<Node> &path);
	void paintPath(vector<Node> id);
};

