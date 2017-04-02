#include <iostream>
#include <string>
#include "Manager.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {
	Manager::instance()->loadData();


	//TODO: change
	int source, dest;

	cout << "SOURCE: ";
	cin >> source;
	cout << endl;

	cout << "DESTINATION: ";
	cin >> dest;
	cout << endl;

	Node park;
	park = Manager::instance()->parkNear(dest);

	cout << "PARK: " << park.getID() << endl;


	vector <Node> part1;
	vector <Node> part2;
	vector<Node> vec;

	if (park.getID() == source){
		part1= Manager::instance()->getShortestPath(source, dest);
	}
	else if(park.getID()==dest){
		part1= Manager::instance()->getShortestPath(source, dest);
	}
	else{
		part1 = Manager::instance()->getShortestPath(source, park.getID());
		part2 = Manager::instance()->getShortestPath(park.getID(), dest);

		part1.insert(part1.end(), part2.begin(), part2.end());
	}

	cout << "PATH: ";
	for (int i =0; i < part1.size(); i++){
		cout << part1.at(i).getID() << " ";
	}

	//Manager::instance()->printGraph();
	getchar();
	return 0;
}
