#include <iostream>
#include <string>
#include "Manager.h"

using namespace std;

Manager* Manager::singleton_instance = 0;

int main() {
	Manager::instance()->loadData();
	//Manager::instance()->displayInfo();

	//TODO load parks e streets
	Manager::instance()->printGraphFromVectors();
	getchar();
	return 0;
}