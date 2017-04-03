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

void Node::setID(int id)
{
	this->id=id;
}

int Node::getID() const
{
	return this->id;
}

int Node::getX() const
{
	return this->coords.first;
}

int Node::getY() const
{
	return this->coords.second;
}

bool Node::operator == (const Node &n2) const {
	return (id == n2.id);
}
