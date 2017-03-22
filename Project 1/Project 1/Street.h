#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Edge.h"

using namespace std;

class Street
{
private:
	int id;
	string name;
	vector<Edge> edges;
	bool twoWays;

public:
	Street();
	~Street();
};

