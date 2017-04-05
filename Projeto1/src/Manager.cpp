#include "Manager.h"

Manager::Manager() {
	gv = new GraphViewer(600, 600, false);
}

Manager::~Manager() {
}

void Manager::loadEdges() {
	string line;

	//ifstream file("Edges.txt");
	ifstream file("1a100.txt");
	//ifstream file("2a300.txt");
	//ifstream file("3a500.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			std::stringstream linestream(line);
			string data;

			int idEdge;
			int idNoInicio;
			int idNoFim;

			linestream >> idEdge;

			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> idNoInicio;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> idNoFim;

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

	//ifstream file("Nodes.txt");
	ifstream file("1v200.txt");
	//ifstream file("2v600.txt");
	//ifstream file("3v1000.txt");

	if (file.is_open()) {
		while (getline(file, line)) {

			std::stringstream linestream(line);
			string data;

			int id;
			int x;
			int y;
			string name;

			linestream >> id;

			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> x;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> y;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> name;

			Node node = Node(id, x, y, name);

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

			linestream >> id;

			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> nodeID;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> name;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> price;
			std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
			linestream >> garagem;

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

void Manager::printGraph() {

	gv->createWindow(800, 800);

	gv->defineEdgeCurved(false);

	gv->defineEdgeColor("black");
	gv->defineVertexIcon("res/emptyIcon.png");

	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

		int idNo = myGraph.getVertexSet().at(i)->getInfo().getID();
		string name = myGraph.getVertexSet().at(i)->getInfo().getName();
		int x = myGraph.getVertexSet().at(i)->getInfo().getX();
		int y = myGraph.getVertexSet().at(i)->getInfo().getY();

		gv->addNode(idNo, x * 5 + 50, -(y * 5) + 600);

		if (isParkingLot(idNo)) {
			gv->setVertexIcon(idNo, "res/parkIcon.png");
			continue;
		}

		if (isPetrolStation(idNo)) {
			gv->setVertexIcon(idNo, "res/gasIcon.png");
			continue;
		}

		if (name == "mall") {
			gv->setVertexIcon(idNo, "res/cartIcon.png");
			continue;
		}

		if (name == "food") {
			gv->setVertexIcon(idNo, "res/foodIcon.png");
			continue;
		}

		if (name == "cinema") {
			gv->setVertexIcon(idNo, "res/movieIcon.png");
			continue;
		}

		if (name == "uni") {
			gv->setVertexIcon(idNo, "res/upIcon.png");
			continue;
		}

	}

	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {

		int idNoOrigem = myGraph.getVertexSet().at(i)->getInfo().getID();

		vector<Edge<Node> > adj = myGraph.getVertexSet().at(i)->getAdj();

		for (unsigned int j = 0; j < adj.size(); j++) {

			int idNoDestino = adj.at(j).getNode()->getInfo().getID();

			int idAresta = 1000 * idNoOrigem + idNoDestino;

			gv->addEdge(idAresta, idNoOrigem, idNoDestino, EdgeType::DIRECTED);
		}

	}

	gv->rearrange();
}

void Manager::paintPath(vector<Node> path) {

	for (int i = 0; i < path.size() - 1; i++) {
		int id = path.at(i).getID() * 1000 + path.at(i + 1).getID();

		gv->setEdgeThickness(id, 4);
		gv->setEdgeColor(id, "BLUE");
	}

	gv->setVertexIcon(path.at(0).getID(), "res/personIcon.png");
	gv->rearrange();
}

Node Manager::getNodeByID(int id) {

	Node node;

	for (unsigned int i = 0; i < myGraph.getVertexSet().size(); i++) {
		if (myGraph.getVertexSet().at(i)->getInfo().getID() == id) {
			node = myGraph.getVertexSet().at(i)->getInfo();
		}
	}

	return node;

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

//retorna node com id -1, se nao nenhum parque dentro dos limites impostos pelo user
Node Manager::parkNear(int id, int maxDistance) {

	int distMinima = INT_MAX;
	int pos = -1;
	Node node = getNodeByID(id);

	myGraph.dijkstraShortestPath(node);

	for (unsigned int i = 0; i < vecParking.size(); i++) {

		int distAtual = vecParking.at(i).getNode()->getDist(); //distancia do parque analisado ao node

		if (distAtual < maxDistance) { //se distancia do parque analisado esta dentro dos limites impostos pelo user
			if (distAtual < distMinima) { //se a distancia for menor que a guardada
				pos = i; //atualiza a posi�ao
				distMinima = distAtual; //atualiza distancia guardada
			}
		}
	}

	if (pos == -1) { //se nenhum parque foi encontrado
		Node nullNode;
		nullNode.setID(-1);
		return nullNode;
	} else
		return vecParking.at(pos).getNode()->getInfo();
}

//retorna node com id -1, se nao nenhum parque dentro dos limites impostos pelo user
Node Manager::parkCheap(int id, int maxDistance) {

	int minPrice = INT_MAX;
	int pos = -1;
	Node node = getNodeByID(id);

	myGraph.dijkstraShortestPath(node);

	for (unsigned int i = 0; i < vecParking.size(); i++) {

		int distAtual = vecParking.at(i).getNode()->getDist(); //distancia do parque analisado ao node
		int priceAtual = vecParking.at(i).getPrice(); //pre�o do parque analisado

		if (distAtual < maxDistance) { //se a distancia do parque analisado esta nos limites impostos pelo user
			if (priceAtual < minPrice) { //se o pre�o for menos que o guardado
				pos = i; //atualiza posi�ao
				minPrice = priceAtual; //atualiza pre�o guardado
			}
		}
	}

	if (pos == -1) { //se nenhum parque foi encontrado
		Node nullNode;
		nullNode.setID(-1);
		return nullNode;
	} else
		return vecParking.at(pos).getNode()->getInfo();
}

Node Manager::petrolNear(int id) {

	Node node = getNodeByID(id);
	int distMinima = INT_MAX;
	int pos = -1;

	for (unsigned int i = 0; i < vecPetrolStations.size(); i++) {

		myGraph.dijkstraShortestPath(vecPetrolStations.at(i)->getInfo()); //faz dijkstra para a bomba analisada

		int distAtual = myGraph.getVertex(node)->getDist(); //distancia da bomba analisada ate ao node

		if (distAtual < distMinima) { //se distancia atual menor que a distancia guardada
			pos = i; //atualiza posi��o
			distMinima = distAtual; //atualiza distancia guardada
		}

	}

	return vecPetrolStations.at(pos)->getInfo();

}

vector<Node> Manager::insertValues() {

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

	//------------------------------------------------
	int nTimeStart = GetMilliCount();
	//------------------------------------------------

	vector<Node> path = calculatePath(source, dest, maxDistance, Cheap_Near,
			passPetrolStation);

	if (path.size() != 0) { //se ha de facto um path
		cout << "PATH: ";
		for (unsigned int i = 0; i < path.size(); i++) {
			cout << path.at(i).getID() << " ";
		}
	}

	//------------------------------------------------
	int nTimeElapsed = GetMilliSpan(nTimeStart);
	cout << endl;
	cout << "MILLISECONDS: " << nTimeElapsed << endl;
	//------------------------------------------------

	return path;
}

//retorna vetor vazio se nao encontroou nenhum path
vector<Node> Manager::calculatePath(int sourceID, int destID, int maxDistance,
		char Cheap_Near, char passPetrolStation) {

//ENCONTRAR PARQUES//
	Node park;

	if (Cheap_Near == 'c') { //se user escolheu encontrar o parque mais barato
		park = parkCheap(destID, maxDistance);
	} else { //se user escolheu o user mais perto do destino
		park = parkNear(destID, maxDistance);
	}

	if (park.getID() == -1) { //se nao foi encontardo nenhum parque
		cout << "THERE'S NO PARK WITHIN THAT DISTANCE!" << endl;
		vector<Node> nullVector;
		return nullVector;
	}

	cout << "PARK: " << park.getID() << endl;

//ELABORAR O PATH//

	vector<Node> part1; //path da source ao parque
	vector<Node> part2; //path do parque a dest
	vector<Node> vec; //path da source a dest, passando pelo parque

	if (park.getID() == sourceID && park.getID() == destID) { //se a source, o dest e o parque sao o mesmo ponto

//vec ter� apenas dois elementos, que ser�o iguais, mas um representa a origem e outro o destino
		vec.push_back(getNodeByID(sourceID));
		vec.push_back(getNodeByID(destID));

		if (passPetrolStation == 'y') { //se o user escolheu abastecer
			addPetrolToPath(vec);
		}

	} else if (park.getID() == sourceID || park.getID() == destID) { //se a source ou o destino s�o o parque

//vec ter� o caminho mais perto de source a dest
		vec = myGraph.getPath(getNodeByID(sourceID), getNodeByID(destID));

		if (passPetrolStation == 'y') { //se o user escolheu abastecer
			addPetrolToPath(vec);
		}

	} else {

		part1 = myGraph.getPath(getNodeByID(sourceID),
				getNodeByID(park.getID())); // caminho mais curto da source ao parque
		part2 = myGraph.getPath(getNodeByID(park.getID()), getNodeByID(destID)); //caminho mais cuto do parque ao dest

		if (passPetrolStation == 'y') { //se o user escolheu abastecer
			addPetrolToPath(part1); //adiciona bomba de gasolina ao path source-park visto que o user ja nao ter� o carro em park-dest
		}

		part2.erase(part2.begin()); //apaga o primeiro elemento de part2 porque � igual ao ultimo elemento da part1, ou seja, o parque

		part1.insert(part1.end(), part2.begin(), part2.end()); //concatena as duas partes

		vec = part1;
	}

	return vec;

}

void Manager::addPetrolToPath(vector<Node> &path) {

	Node source = path.at(0);
	Node dest = path.at(path.size() - 1);

//PART 1 - assumindo bomba mais perto da origem

	int partSource1; //distancia source-bomba
	int partSource2; // distancia bomba-dest
	int partSource; //distancia source-bomba-dest

	vector<Node> pathSource1; //path source-bomba
	vector<Node> pathSource2; //path bomba-dest
	vector<Node> pathSource; //path source-bomba-dest

	Node petrolNearSource = petrolNear(source.getID());

	if (petrolNearSource == source && petrolNearSource == dest) { //se a source, a bomba e o parque forem o mesmo

//pathSources tem 3 elementos iguais, mas cada um representa a sua coisa
		pathSource.push_back(source);
		pathSource.push_back(petrolNearSource);
		pathSource.push_back(dest);

		//distancia entre eles 0
		partSource = 0;

	} else if (petrolNearSource == source || petrolNearSource == dest) { //se a bomba mais perto for na origem ou no destino

		pathSource = myGraph.getPath(source, dest); //path entre a origem e o destino
		myGraph.dijkstraShortestPath(source); //dijkstra para a origem
		partSource = myGraph.getVertex(dest)->getDist(); //distancia mais curta da origem ao destino

	} else {
		myGraph.dijkstraShortestPath(source); //disjkstra para a source
		partSource1 = myGraph.getVertex(petrolNearSource)->getDist(); //path mais curto da origem � bomba
		pathSource1 = myGraph.getPath(source, petrolNearSource); //distancia mais curta da origem � bomba

		myGraph.dijkstraShortestPath(petrolNearSource); //disjkstra para a bomba
		partSource2 = myGraph.getVertex(dest)->getDist(); //path mais curto da bomba ao destino
		pathSource2 = myGraph.getPath(petrolNearSource, dest); //distancia mais curta da bomba ao destino

		pathSource2.erase(pathSource2.begin()); //apaga o primeiro elemento de pathSource2 pois vai ser o mesmo que pathSource1, ou seja, a bomba de gasolina
		pathSource1.insert(pathSource1.end(), pathSource2.begin(),
				pathSource2.end()); //concatena os dois vetores
		pathSource = pathSource1; //origem-bomba-destino

		partSource = partSource1 + partSource2; //distancia mais curta entre a origem-bomba-destino
	}

//PART 2 - calcula bomba mais perto do destino, e o caminho origem-bomba-destino

	int partDest1; //distancia source-bomba
	int partDest2; // distancia bomba-dest
	int partDest; //distancia source-bomba-dest

	vector<Node> pathDest1; //path source-bomba
	vector<Node> pathDest2; //path bomba-dest
	vector<Node> pathDest; //path source-bomba-dest

	Node petrolNearDest = petrolNear(dest.getID());

	if (petrolNearDest == source && petrolNearDest == dest) {

		pathDest.push_back(source);
		pathDest.push_back(petrolNearDest);
		pathDest.push_back(dest);

		partSource = 0;

	} else if (petrolNearDest == source || petrolNearDest == dest) {

		pathDest = myGraph.getPath(source, dest);
		myGraph.dijkstraShortestPath(source);
		partDest = myGraph.getVertex(dest)->getDist();

	} else {

		myGraph.dijkstraShortestPath(source);
		partDest1 = myGraph.getVertex(petrolNearSource)->getDist();
		pathDest1 = myGraph.getPath(source, petrolNearDest);

		myGraph.dijkstraShortestPath(petrolNearSource);
		partDest2 = myGraph.getVertex(dest)->getDist();
		pathDest2 = myGraph.getPath(petrolNearDest, dest);

		pathDest2.erase(pathDest2.begin());
		pathDest1.insert(pathDest1.end(), pathDest2.begin(), pathDest2.end());
		pathDest = pathDest1;

		partDest = partDest1 + partDest2;
	}

	if (partSource < partDest) { //verifica qual o caminho mais curto
		cout << "PETROL STATION: " << petrolNearSource.getID() << endl;
		path = pathSource;
	} else {
		cout << "PETROL STATION: " << petrolNearDest.getID() << endl;
		path = pathDest;
	}

	return;

}

void Manager::graphConnection(){

	vector<Node> vec1;
	vector<Node> vec2;

	myGraph.kosarajuAlgorith(vec1, vec2);

	cout << "VEC1:" << vec1.size() <<endl;
	/*for (int i =0; i < vec1.size(); i++)
		cout << vec1.at(i).getID() << " ";*/

	cout << endl;

	cout << "VEC2:" << vec2.size() <<endl;
	/*for (int i =0; i < vec2.size(); i++)
		cout << vec2.at(i).getID() << " ";*/



}
