#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
	int id; ///< Node's ID
	string name; //< Node's name
	pair<int, int> coords;  ///< Node's coordinates (x,y)

public:
	/**
	 * Construtor default.
	 */
	Node();

	/**
	 * Destrutor default.
	 */
	~Node();

	/**
	 * Construtor de node.
	 * @param id int que representa o ID do node.
	 * @param x int que representa a coordenada X do node.
	 * @param y int que representa a coordenada Y do node.
	 * @param name string que representa o nome do local do node.
	 */
	Node(int id, int x, int y, string name);

	/**
	 * Função que retorna o ID do node
	 * @return ID do node (int).
	 */
	int getID() const;

	/**
	 * Função que retorna a coordenada X do node.
	 * @return X do node (int).
	 */
	int getX() const;

	/**
	 * Função que retorna a coordenada Y do node.
	 * @return Y do node (int).
	 */
	int getY() const;

	/**
	 * Função que retorna o nome do local do node.
	 * @return name do node (string).
	 */
	string getName() const;

	/**
	 * Função que muda o ID do node.
	 * @param ID int do ID pretendido.
	 */
	void setID(int ID);

	/**
	 * Overload do operador == para nodes. Dois nodes são iguais quando têm o mesmo ID.
	 * @param n2 Noode ao qual queremos comparar a instancia que chama esta função.
	 */
	bool operator==(const Node & n2) const;
};

