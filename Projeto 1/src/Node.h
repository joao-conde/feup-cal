#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node
{
private:
	int id;
	pair<int, int> coords;

public:
	Node();
	Node(int id, int x, int y);
	~Node();

	int getID() const;
	int getX() const;
	int getY() const;
	void setID(int ID);
	bool operator==(const Node & n2) const;
};

