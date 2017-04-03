#include <iostream>
#include <string>
#include "Manager.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {
	Manager::instance()->loadData();

	//TODO: change
	int source, dest;
	char passPetrolStation;

	cout << "SOURCE: ";
	cin >> source;

	cout << "DESTINATION: ";
	cin >> dest;

	cout << "PETROL STATION(y/n): ";
	cin >> passPetrolStation;

	Node park;
	park = Manager::instance()->parkNear(dest);

	cout << "PARK: " << park.getID() << endl;

	vector<Node> part1;
	vector<Node> part2;
	vector<Node> vec;

	if (park.getID() == source || park.getID() == dest) {
		vec = Manager::instance()->getShortestPath(source, dest);

		if (passPetrolStation == 'y') {
			Manager::instance()->addPetrolToPath(vec);
		}

	} else {
		part1 = Manager::instance()->getShortestPath(source, park.getID());
		part2 = Manager::instance()->getShortestPath(park.getID(), dest);

		if (passPetrolStation == 'y') {
			Manager::instance()->addPetrolToPath(part1);
		}

		part2.erase(part2.begin());

		part1.insert(part1.end(), part2.begin(), part2.end());

		vec = part1;
	}

	cout << "PATH: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i).getID() << " ";
	}

	//Manager::instance()->printGraph();
	getchar();
	return 0;
}
