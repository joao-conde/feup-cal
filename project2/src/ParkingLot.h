#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include "Graph.h"

class ParkingLot {
private:

	int id;
	Vertex<Node> *node;
	string name;
	float price;
	bool isGarage;
	int lotation;

public:

	/**
	 * Destrutor default.
	 */
	~ParkingLot();

	/**
	 * Construtor de ParkingLot
	 * @param id int que represente o id do parque de estacionamento.
	 * @param node aponador para o vertex a que esse parque de estacionamento est� associado.
	 * @param name string do nome do parque de estacionamento.
	 * @param price float do pre�o do parque de estacionamento.
	 * @param isGarage int que representa se o parque � garagem ou parque de rua. Se 0 � parque de rua, se o 1 � garagem.
	 */
	ParkingLot(int id, Vertex<Node>& node, string name, float price,
			int isGarage, int lotation);

	/**
	 * Fun��o que retorna o ID do parking lot.
	 * @return ID do parking lot (int).
	 */
	int getID();

	/**
	 * Fun��o que retorna o apontador para para o vertex a que esse parque de estacionamento est� associado.
	 * @return Vertex a que esse parque de estacionamento est� associado.
	 */
	Vertex<Node> *getNode();

	/**
	 * Fun��o que retorna o nome do parkingLot.
	 * @return nome do parking lot (string).
	 */
	string getName();

	/**
	 * Fun��o que retorna o pre�o do parkingLot.
	 * @return pre�o do parking lot (float).
	 */
	float getPrice();

	/**
	 * Fun��o que nos diz se o parque de estcionamento � garagem ou parque de rua.
	 * @return true se � garagem, false se � parque de rua.
	 */
	bool getIsGarage();

	int getLotation();

	void setLotation(int num);
};

