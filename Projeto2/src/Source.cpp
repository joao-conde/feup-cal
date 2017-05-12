#include <iostream>
#include <string>
#include "Manager.h"
#include "UtilFunctions.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {

	Manager::instance()->loadData();

	vector<Node> path;
	path = Manager::instance()->producePath();

	if (path.size() != 0) {
		Manager::instance()->printGraph();
		Manager::instance()->paintPath(path);
	} else
		cerr << "Program ended.\n";

	getchar();
	getchar();

	return 0;
}
