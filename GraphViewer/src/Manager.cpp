#include "Manager.h"

Manager::Manager()
{
	gv = new GraphViewer(600, 600, false);
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
			size_t pos2 = str1.find(";"); //posicao 2
			string str2 = str1.substr(pos2 + 1); //no

			string idString = line.substr(0, pos1);
			string nodeIString = str1.substr(0, pos2);
			string nodeFString = str2.substr(0, pos2 + 1);

			int id = stoi(idString, nullptr, 10);
			int nodeI = stoi(nodeIString, nullptr, 10);
			int nodeF = stoi(nodeFString, nullptr, 10);
			Node n;
			Node nodeInit;
			Node nodeFinal;
			//Vertex<Node> *vert = new Vertex<Node>(n);


			for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

				if (nodeI == myGraph.getVertexSet().at(i)->getInfo().getID())
					nodeInit = myGraph.getVertexSet().at(i)->getInfo();

				if (nodeF == myGraph.getVertexSet().at(i)->getInfo().getID()) {
					nodeFinal = myGraph.getVertexSet().at(i)->getInfo();
					//vert = myGraph.getVertexSet().at(i);
				}
			}

			double weight;
			weight = sqrt(pow(nodeFinal.getX() - nodeInit.getX(), 2) + pow(nodeFinal.getY() - nodeInit.getY(), 2));

			//Edge<Node> *edge = new Edge<Node>(id, vert, weight);
			//vecEdges.push_back(edge);
			myGraph.addEdge(id, nodeInit, nodeFinal, weight);


			/*
			for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {
				if (nodeI == myGraph.getVertexSet().at(i)->getInfo().getID())
					myGraph.getVertexSet().at(i)->addEdge(id, vert, weight);
			}*/

		}

		file.close();
	}
	else {
		cerr << "e File not found!\n";
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
			size_t pos2 = str1.find(";"); //posicao 2
			string str2 = str1.substr(pos2 + 1); //y

			string idString = line.substr(0, pos1);
			string xString = str1.substr(0, pos2);
			string yString = str2.substr(0, pos2 + 1);

			int id = stoi(idString, nullptr, 10);
			int x = stoi(xString, nullptr, 10);
			int y = stoi(yString, nullptr, 10);

			Node node = Node(id, x, y);
			//Vertex<Node> *vert = new Vertex<Node>(node);
			myGraph.addVertex(node);
			//vecNodes.push_back(vert);
		}

		file.close();
	}
	else {
		cerr << "n File not found!\n";
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
			int garagem = stoi(garagemString, nullptr, 10);

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
	}
	else {
		cerr << "p File not found!\n";
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
			size_t pos2 = str1.find(";"); //posicao 2
			string str2 = str1.substr(pos2 + 1); //arestas+sentido
			size_t pos3 = str2.find(";"); //posicao 3
			string str3 = str2.substr(pos3 + 1); //sentido

			string idString = line.substr(0, pos1);
			string name = str1.substr(0, pos2);
			string edgesString = str2.substr(0, pos3);
			string wayString = str3.substr(0, pos3 + 1);

			int id = stoi(idString, nullptr, 10);
			int way = stoi(wayString, nullptr, 10);

			edgesString.append(",");
			vector<Edge<Node>*> edges;

			while (!edgesString.empty()) {
				Edge<Node> *edge = NULL;


				int edgeID = stoi(edgesString.substr(0, edgesString.find_first_of(",")), nullptr, 10);

				for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

					vector<Edge<Node>> adj = myGraph.getVertexSet().at(i)->getAdj();

					for (unsigned int  j = 0; j < adj.size(); j++) {
						if (edgeID == adj.at(i).getID()) {
							edge = &(adj.at(i));
							break;
						}
					}

				}


				/*for (unsigned int i = 0; i < vecEdges.size(); i++) {
					if (edgeID == vecEdges.at(i)->getID()) {
						edge = vecEdges.at(i);
						break;
					}
				}*/

				edges.push_back(edge);
				edgesString.erase(0, edgesString.find_first_of(",") + 1);
			}

			Street st = Street(id, name, edges, way);
			vecStreets.push_back(st);
		}

		file.close();
	}
	else {
		cerr << "s File not found!\n";
	}
	return;
}

void Manager::loadData()
{
	loadNodes();
	loadEdges();
	loadParkingLot();
	//loadStreets();
	return;
}

//TODO: esta funcao e so para testar
void Manager::displayInfo()
{
	/*for (unsigned int i = 0; i < vecNodes.size(); i++) {
	cout << vecNodes.at(i)->getInfo().getID() << " - " << vecNodes.at(i)->getInfo().getX() << " - " << vecNodes.at(i)->getInfo().getY() << endl;
	}

	for (unsigned int i = 0; i < vecEdges.size(); i++) {
	cout << vecEdges.at(i)->getID() << " - " << vecEdges.at(i)->getWeight() <<  endl;
	}

	for (unsigned int i = 0; i < vecParking.size(); i++) {
	cout << vecParking.at(i).getID() << " - " << vecParking.at(i).getNode()->getInfo().getID() << " - " << vecParking.at(i).getName() << " - " << vecParking.at(i).getPrice() << " - " << vecParking.at(i).getIsGarage() << endl;
	}

	for (unsigned int i = 0; i < vecStreets.size(); i++) {
	cout << vecStreets.at(i).getID() << " - " << vecStreets.at(i).getName() << " - " << vecStreets.at(i).isTwoWays() << endl;

	for (unsigned int j = 0; j < vecStreets.at(i).getEdges().size(); j++) {
	cout << vecStreets.at(i).getEdges().at(j)->getID() << endl;
	}
	}*/
	return;
}

void Manager::printGraphFromVectors() {

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");
	gv->defineEdgeCurved(true);

	
	for (unsigned int  i = 0; i < myGraph.getVertexSet().size(); i++) {

		int idNo = myGraph.getVertexSet().at(i)->getInfo().getID();
		int x = myGraph.getVertexSet().at(i)->getInfo().getX();
		int y = myGraph.getVertexSet().at(i)->getInfo().getY();

		gv->addNode(idNo,x, -y);
	}

	
	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {
		
		int idNoOrigem = myGraph.getVertexSet().at(i)->getInfo().getID();

		vector<Edge<Node>> adj = myGraph.getVertexSet().at(i)->getAdj();

		for (unsigned int j = 0; j < adj.size(); j++) {
			int idAresta = adj.at(j).getID();
			int idNoDestino = adj.at(j).getNode()->getInfo().getID();

			gv->addEdge(idAresta, idNoOrigem, idNoDestino, EdgeType::UNDIRECTED);
		}
	}

	gv->rearrange();
}