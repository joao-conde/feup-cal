#include "Street.h"



Street::Street()
{
}

Street::Street(int id, string name, vector<Vertex<Node>*> vertexs, int way)
{
	this->id = id;
	this->name = name;
	this->vertexs = vertexs;

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

vector<Vertex<Node>*> Street::getVertexs()
{
	return this->vertexs;
}

bool Street::isTwoWays()
{
	return this->twoWays;
}
