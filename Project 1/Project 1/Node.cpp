#include "Node.h"

Node::Node(int id, int x, int y)
{
	this->id = id;
	this->coords.first = x;
	this->coords.second = y;
}

Node::~Node()
{
}
