#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
	int id; ///< Node's ID
	pair<int, int> coords;  ///< Node's coordinates (x,y)

public:
	/**
	 * Default constructor.
	 */
	Node();

	/**
	 * Default destructor.
	 */
	~Node();

	/**
	 * Node constructor.
	 * @param id int that represents the ID of the node
	 * @param x int that represents the coordinate X of the node
	 * @param y int that represents the coordinate Y of the node
	 */
	Node(int id, int x, int y);


	/**
	 * Function to get the ID of the node.
	 * @return ID of the node (int).
	 */
	int getID() const;

	/**
	 * Function to get the coodinate X of the node.
	 * @return X of the node (int).
	 */
	int getX() const;

	/**
	 * Function to get the coodinate Y of the node.
	 * @return Y of the node (int).
	 */
	int getY() const;

	/**
	 * Function that sets the ID of the node.
	 * @param ID int of the ID to be setted.
	 */
	void setID(int ID);

	/**
	 * Overload of the == operator for nodes. Two nodes are equals when they have the same ID.
	 * @param n2 Second node to be compared.
	 */
	bool operator==(const Node & n2) const;
};

