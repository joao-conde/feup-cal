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
	vector<Vertex<Node>*> vertexs;
	bool twoWays;

public:
	Street();
	Street(int id, string name, vector<Vertex<Node>*> vertexs, int way);
	~Street();

	int getID();
	string getName();
	vector<Vertex<Node>*> getVertexs();
	bool isTwoWays();
};

