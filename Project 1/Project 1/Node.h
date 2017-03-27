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
	Node(int id, int x, int y);
	~Node();
};

