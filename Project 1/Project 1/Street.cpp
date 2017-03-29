#include "Street.h"



Street::Street()
{
}

Street::Street(int id, string name, vector<Edge<Node>*> edges, int way)
{
	this->id = id;
	this->name = name;
	this->edges = edges;

	if (way == 1)
		this->twoWays = true;
	else
		this->twoWays = false;
}


Street::~Street()
{
}

int Street::getID()
{
	return this->id;
}

string Street::getName()
{
	return this->name;
}

vector<Edge<Node>*> Street::getEdges()
{
	return this->edges;
}

bool Street::isTwoWays()
{
	return this->twoWays;
}
