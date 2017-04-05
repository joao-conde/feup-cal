#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "Node.h"

using namespace std;

class Street {
private:
	int id;
	string name;
	vector<Vertex<Node>*> vertexs;
	bool twoWays;

public:
	/*
	 * Construtor default.
	 */
	Street();

	/*
	 * Destrutor default.
	 */
	~Street();

	/**
	 * Construtor de street.
	 * @param id int que representa o ID da street.
	 * @param name string que representa o nome da street.
	 * @param vertexs vetor de vertexs que pertencem à street.
	 * @param way int que representa o sentido das ruas. É 0 se a rua tem um sentido e 1 se a rua tem dois sentidos.
	 */
	Street(int id, string name, vector<Vertex<Node>*> vertexs, int way);

	/**
	 * Função que retorna o ID da street.
	 * @return ID da street (int).
	 */
	int getID();

	/**
	 * Função que retorna o nome da street.
	 * @return Nome da street (string).
	 */
	string getName();

	/**
	 * Função que retorna o vetor de vertexs da street.
	 * @return Vetor de vertexs da street.
	 */
	vector<Vertex<Node>*> getVertexs();

	/*
	 * Função que nos diz se a rua tem dois sentidos ou não.
	 * @return true se a rua tem dois sentidos, false se a rua tem um sentido.
	 */
	bool isTwoWays();
};

