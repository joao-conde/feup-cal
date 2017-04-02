#include "Manager.h"

Manager::Manager() {
	gv = new GraphViewer(600, 600, false);
}

Manager::~Manager() {
}

void Manager::loadEdges() {
	string line;
	ifstream file("Edges.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			std::stringstream linestream(line);
			string data;

			int idEdge;
			int idNoInicio;
			int idNoFim;
			char token;

			linestream >> idEdge;

			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> idNoInicio;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> idNoFim;

			/*size_t pos1 = line.find(";"); //posicao 1
			 string str1 = line.substr(pos1 + 1); //no+no
			 size_t pos2 = str1.find(";"); //posicao 2
			 string str2 = str1.substr(pos2 + 1); //no

			 string idString = line.substr(0, pos1);
			 string nodeIString = str1.substr(0, pos2);
			 string nodeFString = str2.substr(0, pos2 + 1);

			 int id = stoi(idString, nullptr, 10);
			 int nodeI = stoi(nodeIString, nullptr, 10);
			 int nodeF = stoi(nodeFString, nullptr, 10);*/

			Node n;
			Node nodeInit;
			Node nodeFinal;

			for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

				if (idNoInicio
						== myGraph.getVertexSet().at(i)->getInfo().getID())
					nodeInit = myGraph.getVertexSet().at(i)->getInfo();

				if (idNoFim
						== myGraph.getVertexSet().at(i)->getInfo().getID()) {
					nodeFinal = myGraph.getVertexSet().at(i)->getInfo();
				}
			}

			double weight;
			weight = sqrt(
					pow(nodeFinal.getX() - nodeInit.getX(), 2)
							+ pow(nodeFinal.getY() - nodeInit.getY(), 2));
			myGraph.addEdge(nodeInit, nodeFinal, weight);

		}

		file.close();
	} else {
		cerr << "e File not found!\n";
	}
	return;
}

void Manager::loadNodes() {
	string line;
	ifstream file("Nodes.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			std::stringstream linestream(line);
			string data;

			char token;
			int id;
			int x;
			int y;

			linestream >> id;

			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> x;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> y;

			/*size_t pos1 = line.find(";"); //posicao 1
			 string str1 = line.substr(pos1 + 1); //x+y
			 size_t pos2 = str1.find(";"); //posicao 2
			 string str2 = str1.substr(pos2 + 1); //y

			 string idString = line.substr(0, pos1);
			 string xString = str1.substr(0, pos2);
			 string yString = str2.substr(0, pos2 + 1);

			 int id = stoi(idString, nullptr, 10);
			 int x = stoi(xString, nullptr, 10);
			 int y = stoi(yString, nullptr, 10);*/

			Node node = Node(id, x, y);

			myGraph.addVertex(node);
		}

		file.close();
	} else {
		cerr << "n File not found!\n";
	}
	return;
}

void Manager::loadParkingLot() {
	string line;
	ifstream file("Parking.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			std::stringstream linestream(line);
			string data;

			int id;
			int nodeID;
			string name;
			float price;
			int garagem;
			char token;

			linestream >> id;

			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> nodeID;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> name;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> price;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> garagem;

			/*size_t pos1 = line.find(";"); //posicao 1
			 string str1 = line.substr(pos1 + 1); //no+nome+preco+garagem
			 size_t pos2 = str1.find(";"); //posicao 2
			 string str2 = str1.substr(pos2 + 1); //nome+preco+garagem
			 size_t pos3 = str2.find(";"); //posicao 3
			 string str3 = str2.substr(pos3 + 1); //preco+garagem
			 size_t pos4 = str3.find(";"); //posicao 4
			 string str4 = str3.substr(pos4 + 1); //garagem

			 string idString = line.substr(0, pos1);
			 string nodeString = str1.substr(0, pos2);
			 string name = str2.substr(0, pos3);
			 string priceString = str3.substr(0, pos4);
			 string garagemString = str4.substr(0, pos4 + 1);

			 int id = stoi(idString, nullptr, 10);
			 int nodeID = stoi(nodeString, nullptr, 10);
			 float price = stof(priceString);
			 int garagem = stoi(garagemString, nullptr, 10);*/

			Vertex<Node> *vert = NULL;

			for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {
				if (nodeID == myGraph.getVertexSet().at(i)->getInfo().getID()) {
					vert = myGraph.getVertexSet().at(i);
					break;
				}
			}

			ParkingLot plot = ParkingLot(id, vert, name, price, garagem);
			vecParking.push_back(plot);
		}

		file.close();
	} else {
		cerr << "p File not found!\n";
	}
	return;
}

void Manager::loadStreets() {
	string line;
	ifstream file("Streets.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			/*size_t pos1 = line.find(";"); //posicao 1
			 string str1 = line.substr(pos1 + 1); //nome+arestas+sentido
			 size_t pos2 = str1.find(";"); //posicao 2
			 string str2 = str1.substr(pos2 + 1); //nos+sentido
			 size_t pos3 = str2.find(";"); //posicao 3
			 string str3 = str2.substr(pos3 + 1); //sentido

			 string idString = line.substr(0, pos1);
			 string name = str1.substr(0, pos2);
			 string nodesString = str2.substr(0, pos3);
			 string wayString = str3.substr(0, pos3 + 1);

			 int id = stoi(idString, nullptr, 10);
			 int way = stoi(wayString, nullptr, 10);*/

			int id;
			string name;
			int way;
			int NoID;
			char token;

			vector<int> idNodes;

			std::stringstream linestream(line);
			string data;

			linestream >> id >> token;
			std::getline(linestream, name, ';');
			linestream >> way >> token;


			do {
				linestream >> NoID >> token;
				idNodes.push_back(NoID);
			} while (token == ',');

			vector<Vertex<Node>*> vrtxs;

			for (unsigned int j = 0; j < idNodes.size(); j++) {

				Vertex<Node> *vertex = NULL;

				for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

					if (idNodes.at(j)== myGraph.getVertexSet().at(i)->getInfo().getID()) {
						vertex = myGraph.getVertexSet().at(i);
						break;
					}
				}

				vrtxs.push_back(vertex);
			}

			/*
			 nodesString.append(",");
			 vector<Vertex<Node>*> vrtxs;

			 while (!nodesString.empty()) {
			 Vertex<Node> *vertex = NULL;

			 int nodeID = stoi(nodesString.substr(0, nodesString.find_first_of(",")), nullptr, 10);

			 for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

			 if (nodeID == myGraph.getVertexSet().at(i)->getInfo().getID()) {
			 vertex = myGraph.getVertexSet().at(i);
			 break;
			 }
			 }

			 vrtxs.push_back(vertex);
			 nodesString.erase(0, nodesString.find_first_of(",") + 1);
			 }
			 */

			if (way == 1) { //rua tem dois sentidos

				for (int i = vrtxs.size() - 1; i > 0; i--) {

					Node nodeInit = vrtxs.at(i)->getInfo();
					Node nodeFinal = vrtxs.at(i - 1)->getInfo();

					double weight = sqrt(
							pow(nodeFinal.getX() - nodeInit.getX(), 2)
									+ pow(nodeFinal.getY() - nodeInit.getY(),
											2));

					vrtxs.at(i)->addEdge(vrtxs.at(i - 1), weight);

				}

			}

			Street st = Street(id, name, vrtxs, way);
			vecStreets.push_back(st);
		}

		file.close();
	} else {
		cerr << "s File not found!\n";
	}
	return;
}

void Manager::loadPetrolStations() {
	string line;
	ifstream file("petrolStations.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			/*string idString = line;

			 int id = stoi(idString, nullptr, 10);*/

			int id;

			std::stringstream linestream(line);

			linestream >> id;

			for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {
				if (myGraph.getVertexSet().at(i)->getInfo().getID() == id) {
					vecPetrolStations.push_back(myGraph.getVertexSet().at(i));
				}
			}
		}

		file.close();
	} else {
		cerr << "n File not found!\n";
	}
	return;
}

void Manager::loadMetroStations() {
	string line;
	ifstream file("metroStations.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			/*string idString = line;

			 int id = stoi(idString, nullptr, 10);*/

			int id;

			std::stringstream linestream(line);

			linestream >> id;

			for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {
				if (myGraph.getVertexSet().at(i)->getInfo().getID() == id) {
					vecMetroStations.push_back(myGraph.getVertexSet().at(i));
				}
			}
		}

		file.close();
	} else {
		cerr << "n File not found!\n";
	}
	return;
}

void Manager::loadData() {
	loadNodes();
	loadEdges();
	loadParkingLot();
	loadStreets();
	loadPetrolStations();
	loadMetroStations();
	return;
}

bool Manager::isParkingLot(int idNo) {
	for (unsigned int i = 0; i < vecParking.size(); i++) {
		if (vecParking.at(i).getNode()->getInfo().getID() == idNo)
			return true;
	}

	return false;
}

bool Manager::isPetrolStation(int idNo) {
	for (unsigned int i = 0; i < vecPetrolStations.size(); i++) {
		if (vecPetrolStations.at(i)->getInfo().getID() == idNo)
			return true;
	}
	return false;
}

bool Manager::isMetroStation(int idNo) {
	for (unsigned int i = 0; i < vecMetroStations.size(); i++) {
		if (vecMetroStations.at(i)->getInfo().getID() == idNo)
			return true;
	}

	return false;
}

void Manager::printGraph() {

	gv->createWindow(800, 800);

	gv->defineEdgeCurved(false);

	gv->defineEdgeColor("black");
	gv->defineVertexColor("white");

	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

		int idNo = myGraph.getVertexSet().at(i)->getInfo().getID();
		int x = myGraph.getVertexSet().at(i)->getInfo().getX();
		int y = myGraph.getVertexSet().at(i)->getInfo().getY();

		gv->addNode(idNo, x * 5 + 50, -(y * 5) + 600);

		if (isParkingLot(idNo))
			gv->setVertexColor(idNo, "blue");

		if (isPetrolStation(idNo))
			gv->setVertexColor(idNo, "black");

		if (isMetroStation(idNo))
			gv->setVertexColor(idNo, "gray");

	}

	int idAresta = 0;

	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

		int idNoOrigem = myGraph.getVertexSet().at(i)->getInfo().getID();

		vector<Edge<Node> > adj = myGraph.getVertexSet().at(i)->getAdj();

		for (unsigned int j = 0; j < adj.size(); j++) {

			int idNoDestino = adj.at(j).getNode()->getInfo().getID();

			gv->addEdge(idAresta, idNoOrigem, idNoDestino, EdgeType::DIRECTED);

			idAresta++;
		}

		idAresta++;
	}

	gv->rearrange();
}

/////////////////////////

vector <Node> Manager::getShortestPath(int source, int dest) {

	Node nodeDest;

	for (int i = 0; i < myGraph.getVertexSet().size(); i++) {
		if (myGraph.getVertexSet().at(i)->getInfo().getID() == dest) {
			nodeDest = myGraph.getVertexSet().at(i)->getInfo();
		}
	}

	Node nodeSource;

	for (int i = 0; i < myGraph.getVertexSet().size(); i++) {
		if (myGraph.getVertexSet().at(i)->getInfo().getID() == source) {
			nodeSource = myGraph.getVertexSet().at(i)->getInfo();
		}
	}

	//myGraph.dijkstraShortestPath(nodeSource);

	vector<Node> path =	myGraph.getPath(nodeSource, nodeDest);

	return path;

}

Node Manager::parkNear(int id){

	Node node;

		for (int i = 0; i < myGraph.getVertexSet().size(); i++) {
			if (myGraph.getVertexSet().at(i)->getInfo().getID() == id) {
				node = myGraph.getVertexSet().at(i)->getInfo();
			}
		}

	myGraph.dijkstraShortestPath(node);

	ParkingLot park = vecParking.at(0);

	for (int i =0; i < vecParking.size(); i++){
		if(vecParking.at(i).getNode()->getDist() < park.getNode()->getDist())
			park = vecParking.at(i);
	}

	return park.getNode()->getInfo();

}
