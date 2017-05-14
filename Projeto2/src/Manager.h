#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "Graph.h"
#include "Node.h"
#include "ParkingLot.h"
#include "Street.h"
#include "graphviewer.h"
#include "UtilFunctions.h"
#include "Town.h"
#include <iomanip>

class Manager {

private:
	static Manager* singleton_instance;

	Graph<Node> myGraph;

	vector<Node> vecNodes;
	vector<ParkingLot> vecParking;
	vector<Street> vecStreets;
	vector<Town> vecTowns;
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
	 * Funcao que carrega os dados do ficheiro de arestas para as estruturas em Graph.h.
	 */
	void loadEdges();

	/**
	 * Funcao que carrega os dados do ficheiro de nodes, criando objetos da classe Node e adicionando também ao respetivo vertex em myGraph.
	 */
	void loadNodes();

	/**
	 * Funcao que carrega os dados do ficheiro de parques de estacionamento, criando objetos da classe ParkingLot.
	 */
	void loadParkingLot();

	/**
	 * Funcao que carrega os dados do ficheiro de ruas, criando objetos da classe Street.
	 * Caso as ruas tenham dois sentidos, são adicionadas arestas ao myGraph com sentido contrário ao que está no vetor de Vertexs da rua.
	 */
	void loadStreets();

	/**
	 * Funcao que carrega os dados do ficheiro de bombas de gasolina.
	 */
	void loadPetrolStations();

	/**
	 * Funcao que chama todas as funçoes de load.
	 */

	void loadTowns();

	void loadData();

	/**
	 * Funcao que mostra o grafo gv, com todas as arestas e nos em myGraph.
	 */
	void printGraph();

	/**
	 * Funcao que destaca as arestas que ligam os nos passados por argumento no grafo gv.
	 * @param id Vetor de ids de nos presentes no caminho que é suposto destacar no grafo gv.
	 */
	void paintPath(vector<Node> id);

	/**
	 * Funcao que procura o node de id passado por argumento.
	 * @param id int do id a procurar.
	 * @return Node pretendido.
	 */
	Node getNodeByID(int id);

	/**
	 * Funcao que diz se o Node com id passado por argumento é parque de estacionamento.
	 * @param idNo int do id do Node.
	 * @return true se o Node é um parque de estacionamento, false se não é.
	 */
	bool isParkingLot(int idNo);

	/**
	 * Funcao que diz se o Node com id passado por argumento é bomba de gasolina.
	 * @param idNo int do id do Node.
	 * @return true se o Node é um parque de estacionamento, false se não é.
	 */
	bool isPetrolStation(int idNo);

	/**
	 * Funcao que diz qual o parque de estacionamento mais proximo do Node com id passado por argumento dentro de uma determinada distância passada também por argumento.
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
	 * Funcao que diz qual a bomba de gasolina mais proximo do Node com id passado por argumento.
	 * @param id int do id do Node.
	 * @return Node associado à bomba de gasolina mais proxima.
	 */
	Node petrolNear(int id);

	/**
	 * Funcao que pede os valores ao user e chama as funçoes para calcular o path, retornando esse path.
	 * Se o retorno for um vetor vazio, algum valor inserido nao foi valido.
	 * @return Vetor de Nodes com o path pretendido.
	 */
	//TODO: alterar documentacao disto
	vector<Node> producePath();

	/**
	 * Funcao que calcula o path final pretendido.
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
	 * Funcao que adiciona uma bomba de abastecimento ao path passado por argumento.
	 * @param path vetor de nodes do caminho mais curto entre a origem e o parque de estacionamento.
	 */
	void addPetrolToPath(vector<Node> &path);

	int searchMenu();

	vector<int> getInformation();
	void displayTowns();
	Town chooseTown(bool source, bool approx);
	void displayStreets(Town town);
	Street* chooseStreet(Town town, bool source, bool approx);
	int getNodeID(Street& st, string town);

	vector<Town> stringMatchingTown(string name);
	vector<Street*> stringMatchingStreet(string name,  Town town);
	void prekpm(string pattern, int f[]);
	bool kpm(string pattern, string target);


	vector<Town> approximateStringMatchingTown(string name);
	vector<Street*> approximateStringMatchingStreet(string name, Town town);
	int wordDistance(string pattern, string text);

};

