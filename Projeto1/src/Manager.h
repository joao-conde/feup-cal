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

class Manager {

private:
	static Manager* singleton_instance;

	Graph<Node> myGraph;

	vector<Node> vecNodes;
	vector<ParkingLot> vecParking;
	vector<Street> vecStreets;
	vector<Vertex<Node>*> vecPetrolStations;

	GraphViewer *gv;

public:
	Manager();
	~Manager();

	static Manager* instance() {
		if (!singleton_instance)
			singleton_instance = new Manager;

		return singleton_instance;
	}

	void loadEdges();
	void loadNodes();
	void loadParkingLot();
	void loadStreets();
	void loadPetrolStations();
	void loadMetroStations();
	void loadData();

	void printGraph();
	void paintPath(vector<Node> id);

	Node getNodeByID(int id);
	bool isParkingLot(int idNo);
	bool isPetrolStation(int idNo);

	Node parkNear(int id, int maxDistance);
	Node parkCheap(int id, int maxDistance);
	Node petrolNear(int id);

	vector<Node> insertValues();
	vector<Node> calculatePath(int sourceID, int destID, int maxDistance,char Cheap_Near, char passPetrolStation);
	void addPetrolToPath(vector<Node> &path);
};

