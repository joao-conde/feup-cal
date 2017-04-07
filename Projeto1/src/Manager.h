#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "Graph.h"
#include "Local.h"
#include "Node.h"
#include "ParkingLot.h"
#include "Street.h"
#include "graphviewer.h"
#include "UtilFunctions.h"

class Manager {

private:
	static Manager* singleton_instance;

	Graph<Node> myGraph;

	vector<Node> vecNodes;
	vector<ParkingLot> vecParking;
	vector<Street> vecStreets;
	vector<Vertex<Node>*> vecPetrolStations;

	GraphViewer *gv;

public:
	/**
	 * Construtor default.
	 */
	Manager();

	/**
	 * Destrutor default.
	 */
	~Manager();

	static Manager* instance() {
		if (!singleton_instance)
			singleton_instance = new Manager;

		return singleton_instance;
	}

	/**
	 * Função que carrega os dados do ficheiro de arestas para as estruturas em Graph.h.
	 */
	void loadEdges();

	/**
	 * Função que carrega os dados do ficheiro de nodes, criando objetos da classe Node e adicionando também ao respetivo vertex em myGraph.
	 */
	void loadNodes();

	/**
	 * Função que carrega os dados do ficheiro de parques de estacionamento, criando objetos da classe ParkingLot.
	 */
	void loadParkingLot();

	/**
	 * Função que carrega os dados do ficheiro de ruas, criando objetos da classe Street.
	 * Caso as ruas tenham dois sentidos, são adicionadas arestas ao myGraph com sentido contrário ao que está no vetor de Vertexs da rua.
	 */
	void loadStreets();

	/**
	 * Função que carrega os dados do ficheiro de bombas de gasolina.
	 */
	void loadPetrolStations();

	/**
	 * Função que chama todas as funçoes de load.
	 */
	void loadData();

	/**
	 * Função que mostra o grafo gv, com todas as arestas e nos em myGraph.
	 */
	void printGraph();

	/**
	 * Função que destaca as arestas que ligam os nos passados por argumento no grafo gv.
	 * @param id Vetor de ids de nos presentes no caminho que é suposto destacar no grafo gv.
	 */
	void paintPath(vector<Node> id);

	/**
	 * Função que procura o node de id passado por argumento.
	 * @param id int do id a procurar.
	 * @return Node pretendido.
	 */
	Node getNodeByID(int id);

	/**
	 * Função que diz se o Node com id passado por argumento é parque de estacionamento.
	 * @param idNo int do id do Node.
	 * @return true se o Node é um parque de estacionamento, false se não é.
	 */
	bool isParkingLot(int idNo);

	/**
	 * Função que diz se o Node com id passado por argumento é bomba de gasolina.
	 * @param idNo int do id do Node.
	 * @return true se o Node é um parque de estacionamento, false se não é.
	 */
	bool isPetrolStation(int idNo);

	/**
	 * Função que diz qual o parque de estacionamento mais proximo do Node com id passado por argumento dentro de uma determinada distância passada também por argumento.
	 * @param id int do id do Node
	 * @param maxDistance distancia máxima pretendida.
	 * @return Se existir um parque de estacionamento retorna o Node associado, senão retorna um Node com id -1.
	 */
	Node parkNear(int id, int maxDistance);

	/**
	 * Função que diz qual o parque de estacionamento mais barato do Node com id passado por argumento dentro de uma determinada distância passada também por argumento.
	 * @param id int do id do Node
	 * @param maxDistance distancia máxima pretendida.
	 * @return Se existir um parque de estacionamento retorna o Node associado, senão retorna um Node com id -1.
	 */
	Node parkCheap(int id, int maxDistance);

	/**
	 * Função que diz qual a bomba de gasolina mais proximo do Node com id passado por argumento.
	 * @param id int do id do Node.
	 * @return Node associado à bomba de gasolina mais proxima.
	 */
	Node petrolNear(int id);

	/**´
	 * Função que pede os valores ao user e chama as funçoes para calcular o path, retornando esse path.
	 * @return Vetor de Nodes com o path pretendido.
	 */
	string mainMenu(bool source);
	vector<int> getStreets(bool source);
	bool verifyChoice(const vector<int> st, int id);
	vector<Node> insertValues();

	/**
	 * Função que calcula o path final pretendido.
	 * @param sourceID int do id do node onde o user está.
	 * @param destID int do id do no node onde o user quer ir.
	 * @param maxDistance int da distância maxima à qual o user quer o parque de estacionamento do destino.
	 * @param Cheap_Near char que diz se o user quer o parque mais próximo ('n') ou o parque mais barato('c').
	 * @param passPetrolStation char que diz se o user quer abastecer ('y') ou não ('n').
	 * @return Vetor de Nodes do path final pretendido.
	 */
	vector<Node> calculatePath(int sourceID, int destID, int maxDistance,
			int Cheap_Near, char passPetrolStation);

	/**
	 * Função que adiciona uma bomba de abastecimento ao path passado por argumento.
	 * @param path vetor de nodes do caminho mais curto entre a origem e o parque de estacionamento.
	 */
	void addPetrolToPath(vector<Node> &path);
};

