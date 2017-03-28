#include "Node.h"

Node::Node()
{
}

Node::Node(int id, int x, int y)
{
	this->id = id;
	this->coords.first = x;
	this->coords.second = y;
}

Node::~Node()
{
}

int Node::getID()
{
	return this->id;
}

int Node::getX()
{
	return this->coords.first;
}

int Node::getY()
{
	return this->coords.second;
}
