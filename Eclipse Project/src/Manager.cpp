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

				for (unsigned int i = 0; i < myGraph.getVertexSet().size();
						i++) {

					if (idNodes.at(j)
							== myGraph.getVertexSet().at(i)->getInfo().getID()) {
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

void Manager::loadData() {
	loadNodes();
	loadEdges();
	loadParkingLot();
	loadStreets();
	loadPetrolStations();
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

void Manager::printGraph() {

	gv->createWindow(800, 800);

	gv->defineEdgeCurved(false);

	gv->defineEdgeColor("black");
	gv->defineVertexColor("gray");

	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

		int idNo = myGraph.getVertexSet().at(i)->getInfo().getID();
		int x = myGraph.getVertexSet().at(i)->getInfo().getX();
		int y = myGraph.getVertexSet().at(i)->getInfo().getY();

		gv->addNode(idNo, x * 5 + 50, -(y * 5) + 600);

		if (isParkingLot(idNo))
			gv->setVertexColor(idNo, "blue");

		if (isPetrolStation(idNo))
			gv->setVertexColor(idNo, "black");

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

Node Manager::getNodeByID(int id) {

	Node node;

	for (int i = 0; i < myGraph.getVertexSet().size(); i++) {
		if (myGraph.getVertexSet().at(i)->getInfo().getID() == id) {
			node = myGraph.getVertexSet().at(i)->getInfo();
		}
	}

	return node;

}

vector<Node> Manager::getShortestPath(int source, int dest) {

	Node nodeDest = getNodeByID(dest);

	Node nodeSource = getNodeByID(source);

	vector<Node> path = myGraph.getPath(nodeSource, nodeDest);

	return path;

}

Node Manager::parkNear(int id, int maxDistance) {

	Node node = getNodeByID(id);

	myGraph.dijkstraShortestPath(node);

	int distMinima = INT_MAX;
	int pos = 0;

	for (int i = 0; i < vecParking.size(); i++) { //corre o vetor de parques para encontrar o que é mais perto do no com id passado por argumento

		int distAtual = vecParking.at(i).getNode()->getDist();

		if (distAtual < distMinima) {
			pos = i;
			distMinima = distAtual;
		}

	}

	if (distMinima > maxDistance) {
		Node nullNode;
		nullNode.setID(-1);
		return nullNode;
	} else
		return vecParking.at(pos).getNode()->getInfo();
}

Node Manager::parkCheap(int id, int maxDistance) {

	Node node = getNodeByID(id);

	myGraph.dijkstraShortestPath(node);

	int minPrice = INT_MAX;
	int pos;

	bool flag = false;

	for (int i = 0; i < vecParking.size(); i++) { //corre o vetor de parques para encontrar o que é mais perto do no com id passado por argumento

		int distAtual = vecParking.at(i).getNode()->getDist();
		int priceAtual = vecParking.at(i).getPrice();

		//cout << vecParking.at(i).getPrice() << " ";
		if (distAtual < maxDistance) {
			if (priceAtual < minPrice) {
				pos = i;
				minPrice = priceAtual;
				flag = true;
			}
		}
	}

	if (!flag) {
		Node nullNode;
		nullNode.setID(-1);
		return nullNode;
	} else
		return vecParking.at(pos).getNode()->getInfo();
}

Node Manager::petrolNear(int id) {

	Node node = getNodeByID(id);

	Vertex<Node>* petrol = vecPetrolStations.at(0);
	int distMinima = INT_MAX;

	int pos = 0;

	for (int i = 0; i < vecPetrolStations.size(); i++) { //corre o vetor de bombas de gasolina

		myGraph.dijkstraShortestPath(vecPetrolStations.at(i)->getInfo()); //faz dijkstra para todas as bombas

		int distAtual = myGraph.getVertex(node)->getDist(); //distancia da bomba analisada ate ao no
		if (distAtual < distMinima) { //se distAtual menor que a distancia guardada, entao distMinima é atualizada
			pos = i;
			distMinima = distAtual;
		}

	}

	return vecPetrolStations.at(pos)->getInfo();

}

vector <Node> Manager::insertValues() {

	int source, dest, maxDistance;
	char passPetrolStation, Cheap_Near;

	cout << "SOURCE: ";
	cin >> source;

	cout << "DESTINATION: ";
	cin >> dest;

	cout << "MAX DISTANCE: ";
	cin >> maxDistance;

	cout << "CHEAP OR NEAR (c/n): ";
	cin >> Cheap_Near;

	cout << "PETROL STATION (y/n): ";
	cin >> passPetrolStation;

	vector<Node> path = calculatePath(source, dest, maxDistance, Cheap_Near,
			passPetrolStation);

	if (path.size() == 0){
		return path;
	}

	cout << "PATH: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path.at(i).getID() << " ";
	}


	printGraph();

	return path;
}

void Manager::paintPath(vector <Node> path){

	for (int i =0; i < path.size()-1; i++ ){
		int id= 200+i;
		gv->addEdge(id, path.at(i).getID(), path.at(i+1).getID(), EdgeType::DIRECTED);
		gv->setEdgeThickness(id, 4);
		gv->setEdgeColor(id, "orange");
	}

	gv->rearrange();
}

vector<Node> Manager::calculatePath(int sourceID, int destID, int maxDistance,
		char Cheap_Near, char passPetrolStation) {
	Node park;

	if (Cheap_Near == 'c') {
		park = Manager::instance()->parkCheap(destID, maxDistance);
	} else {
		park = Manager::instance()->parkNear(destID, maxDistance);
	}

	vector<Node> nullVector;

	if (park.getID() == -1) {
		cout << "THERE'S NO PARK WITHIN THAT DISTANCE!" << endl;
		return nullVector;
	}

	cout << "PARK: " << park.getID() << endl;

	//TESTE
	ParkingLot parkLot;

	for (int i = 0; i < vecParking.size(); i++) {

		if (vecParking.at(i).getNode() == myGraph.getVertex(park)) {
			parkLot = vecParking.at(i);
		}
	}

	cout << "PRICE: " << parkLot.getPrice() << endl;




	vector<Node> part1;
	vector<Node> part2;
	vector<Node> vec;

	if (park.getID() == sourceID && park.getID() == destID) { //se a source, o dest e o parque sao o mesmo ponto

		vec.push_back(getNodeByID(sourceID));
		vec.push_back(getNodeByID(sourceID));

		if (passPetrolStation == 'y') {
			Manager::instance()->addPetrolToPath(vec);
		}

	} else if (park.getID() == sourceID || park.getID() == destID) { //se a source é parque ou o destino é parque
		vec = Manager::instance()->getShortestPath(sourceID, destID);

		if (passPetrolStation == 'y') {
			Manager::instance()->addPetrolToPath(vec);
		}

	} else {
		part1 = Manager::instance()->getShortestPath(sourceID, park.getID()); // caminho mais curto da source ao parque
		part2 = Manager::instance()->getShortestPath(park.getID(), destID); //caminho mais cuto do parque ao dest

		if (passPetrolStation == 'y') {
			Manager::instance()->addPetrolToPath(part1);
		}

		part2.erase(part2.begin()); //apaga o primeiro elemento da segunda parte porque é igual ao ultimo elemento da primeira parte

		part1.insert(part1.end(), part2.begin(), part2.end()); //concatena as duas partes

		vec = part1;
	}

	return vec;

}

void Manager::addPetrolToPath(vector<Node> &path) {

	Node source = path.at(0);

	Node dest = path.at(path.size() - 1);

	//PART 1 - calcula bomba mais perto da origem, e o caminho origem-bomba-destino

	int partSourceA, partSourceB;
	int partSource;
	vector<Node> pathSourceA, pathSourceB;

	Node petrolNearSource = petrolNear(source.getID());

	if (!(petrolNearSource == source)) {

		myGraph.dijkstraShortestPath(source);
		partSourceA = myGraph.getVertex(petrolNearSource)->getDist();
		pathSourceA = myGraph.getPath(source, petrolNearSource);
	} else {
		partSourceA = 0;
		pathSourceA.push_back(source);
	}

	myGraph.dijkstraShortestPath(petrolNearSource);
	partSourceB = myGraph.getVertex(dest)->getDist();
	pathSourceB = myGraph.getPath(petrolNearSource, dest);

	partSource = partSourceA + partSourceB;

	pathSourceB.erase(pathSourceB.begin());
	pathSourceA.insert(pathSourceA.end(), pathSourceB.begin(),
			pathSourceB.end());

	//PART 2 - calcula bomba mais perto do destino, e o caminho origem-bomba-destino

	int partDestA, partDestB;
	int partDest;
	vector<Node> pathDestA, pathDestB;

	Node petrolNearDest = petrolNear(dest.getID());

	myGraph.dijkstraShortestPath(source);
	partDestA = myGraph.getVertex(petrolNearDest)->getDist();
	pathDestA = myGraph.getPath(source, petrolNearDest);

	myGraph.dijkstraShortestPath(petrolNearDest);
	partDestB = myGraph.getVertex(dest)->getDist();
	pathDestB = myGraph.getPath(petrolNearDest, dest);

	partDest = partDestA + partDestB;

	pathDestB.erase(pathDestB.begin());

	pathDestA.insert(pathDestA.end(), pathDestB.begin(), pathDestB.end());

	//verifica qual o caminho mais curto
	if (partSource < partDest) {
		cout << "PETROL STATION: " << petrolNearSource.getID() << endl;
		path = pathSourceA;
	} else {
		cout << "PETROL STATION: " << petrolNearDest.getID() << endl;
		path = pathDestA;
	}

}


