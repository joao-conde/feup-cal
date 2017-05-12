#include <iostream>
#include <string>
#include "Manager.h"
#include "UtilFunctions.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {

	Manager::instance()->loadData();

	//PROJECT 1

	/*vector<Node> path;
	path = Manager::instance()->insertValues();

	if (path.size() != 0) {
		Manager::instance()->printGraph();
		Manager::instance()->paintPath(path);
	} else
		cerr << "Program ended.\n";*/

	//PROJECT 2

	//Manager::instance()->askTownAndStreet();

	Manager::instance()->insertStrings();

	//Manager::instance()->printGraph();

	getchar();
	getchar();

	return 0;
}
