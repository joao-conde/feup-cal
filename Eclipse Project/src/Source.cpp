#include <iostream>
#include <string>
#include "Manager.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {
	Manager::instance()->loadData();

	vector<Node> path;

	path= Manager::instance()->insertValues();
	getchar();

	//Manager::instance()->printGraph();
	Manager::instance()->paintPath(path);

	getchar();
	return 0;
}
