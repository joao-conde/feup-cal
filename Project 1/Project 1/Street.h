#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "Node.h"

using namespace std;

class Street
{
private:
	int id;
	string name;
	vector<Edge<Node>*> edges;
	bool twoWays;

public:
	Street();
	Street(int id, string name, vector<Edge<Node>*> edges, int way);
	~Street();

	int getID();
	string getName();
	vector<Edge<Node>*> getEdges();
	bool isTwoWays();
};

