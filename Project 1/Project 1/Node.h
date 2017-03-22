#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node
{
private:
	int id;
	float latitude; //x
	float longitude; //y
	friend class Edge;

public:
	Node();
	~Node();
};

