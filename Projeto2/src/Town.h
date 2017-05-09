#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Street.h"

using namespace std;

class Town {
private:
	int id;
	string name;
	vector<Street*> streets;

public:
	Town(int id, string name, vector<Street*> streets);
	int getId();
	string getName();
	vector <Street*> getStreets();

};

