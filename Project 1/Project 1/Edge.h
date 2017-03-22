#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class Edge
{
private:
	int id;
	Node firstNode;
	Node lastNode;
	int value;

public:
	Edge();
	~Edge();
};

