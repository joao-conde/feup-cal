#include <iostream>
#include <string>
#include "Manager.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {
	Manager::instance()->loadData();
	//Manager::instance()->displayInfo();
	//Manager::instance()->printGraph();
	getchar();
	return 0;
}