#include "Manager.h"

Manager::Manager()
{
}


Manager::~Manager()
{
}

void Manager::loadEdges()
{
	string line;
	ifstream file("Edges.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			size_t pos1 = line.find(";"); //posicao 1
			string str1 = line.substr(pos1 + 1); //no+no
			size_t pos2 = line.find(";"); //posicao 2
			string str2 = line.substr(pos1 + 1); //no

			string idString = line.substr(0, pos1);
			string nodeIString = str1.substr(0, pos2);
			string nodeFString = str2.substr(0, pos2 + 1);

			int id = stoi(idString, nullptr, 10);
			int nodeI = stoi(nodeIString, nullptr, 10);
			int nodeF = stoi(nodeFString, nullptr, 10);
			Node n;
			Node nodeInit;
			Node nodeFinal;
			Vertex<Node> *vert = new Vertex<Node>(n);

			for (unsigned int i = 0; i < vecNodes.size(); i++) {

				if (nodeI == vecNodes.at(i)->getInfo().getID())
					nodeInit = vecNodes.at(i)->getInfo();

				if (nodeF == vecNodes.at(i)->getInfo().getID()) {
					nodeFinal = vecNodes.at(i)->getInfo();
					vert = vecNodes.at(i);
				}
			}

			double weight;
			weight = sqrt(pow(nodeFinal.getX() - nodeInit.getX(), 2) + pow(nodeFinal.getY() - nodeInit.getY(), 2));

			Edge<Node> *edge = new Edge<Node>(vert, weight);
			vecEdges.push_back(edge);
		}

		file.close();
	}
	else {
		cerr << "File not found!\n";
	}
	return;
}

void Manager::loadNodes()
{
	string line;
	ifstream file("Nodes.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			size_t pos1 = line.find(";"); //posicao 1
			string str1 = line.substr(pos1 + 1); //x+y
			size_t pos2 = line.find(";"); //posicao 2
			string str2 = line.substr(pos1 + 1); //y

			string idString = line.substr(0, pos1);
			string xString = str1.substr(0, pos2);
			string yString = str2.substr(0, pos2 + 1);

			int id = stoi(idString, nullptr, 10);
			int x = stoi(xString, nullptr, 10);
			int y = stoi(yString, nullptr, 10);

			Node node = Node(id, x, y);
			Vertex<Node> *vert = new Vertex<Node>(node);
			vecNodes.push_back(vert);
		}

		file.close();
	}
	else {
		cerr << "File not found!\n";
	}
	return;
}

void Manager::loadParkingLot()
{
	string line;
	ifstream file("Parking.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			size_t pos1 = line.find(";"); //posicao 1
			string str1 = line.substr(pos1 + 1); //no+nome+preco+garagem
			size_t pos2 = line.find(";"); //posicao 2
			string str2 = line.substr(pos1 + 1); //nome+preco+garagem
			size_t pos3 = line.find(";"); //posicao 3
			string str3 = line.substr(pos1 + 1); //preco+garagem
			size_t pos4 = line.find(";"); //posicao 4
			string str4 = line.substr(pos1 + 1); //garagem

			string idString = line.substr(0, pos1);
			string nodeString = str1.substr(0, pos2);
			string name = str2.substr(0, pos3);
			string priceString = str3.substr(0, pos4);
			string garagemString = str4.substr(0, pos4 + 1);

			int id = stoi(idString, nullptr, 10);
			int nodeID = stoi(nodeString, nullptr, 10);
			float price = stof(priceString);
			int garagem = stoi(garagemString, nullptr, 10);

			Vertex<Node> *vert;

			for (unsigned int i = 0; i < vecNodes.size(); i++) {
				if (nodeID == vecNodes.at(i)->getInfo().getID()) {
					vert = vecNodes.at(i);
					break;
				}
			}

			ParkingLot plot = ParkingLot(id, vert, name, price, garagem);
			vecParking.push_back(plot);
		}

		file.close();
	}
	else {
		cerr << "File not found!\n";
	}
	return;
}

void Manager::loadStreets()
{
	string line;
	ifstream file("Streets.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			size_t pos1 = line.find(";"); //posicao 1
			string str1 = line.substr(pos1 + 1); //nome+arestas+sentido
			size_t pos2 = line.find(";"); //posicao 2
			string str2 = line.substr(pos1 + 1); //arestas+sentido
			size_t pos3 = line.find(";"); //posicao 3
			string str3 = line.substr(pos1 + 1); //sentido

			string idString = line.substr(0, pos1);
			string name = str1.substr(0, pos2);
			string edgesString = str2.substr(0, pos3);
			string wayString = str3.substr(0, pos3 + 1);

			int id = stoi(idString, nullptr, 10);
			int way = stoi(wayString, nullptr, 10);
			
			//TODO: falta analisar arestas e afins
		}

		file.close();
	}
	else {
		cerr << "File not found!\n";
	}
	return;
}

void Manager::loadData()
{
	loadNodes();
	loadEdges();
	loadParkingLot();
	loadStreets();
	return;
}
