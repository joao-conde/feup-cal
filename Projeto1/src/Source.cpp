#include <iostream>
#include <string>
#include "Manager.h"
#include "UtilFunctions.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {

	int nTimeStart = GetMilliCount();
	//cout << nTimeStart << endl;

	//------------------------------------------------

	Manager::instance()->loadData();

	vector<Node> path;
	path = Manager::instance()->insertValues();

	Manager::instance()->printGraph();

	if (path.size() != 0)
		Manager::instance()->paintPath(path);


	getchar();
	getchar();

	//------------------------------------------------

	int nTimeElapsed = GetMilliSpan( nTimeStart );
	cout << endl;
	cout << nTimeElapsed << endl;

	return 0;
}
