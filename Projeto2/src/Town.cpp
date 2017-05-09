/*
 * Town.cpp
 *
 *  Created on: 09/05/2017
 *      Author: FF
 */

#include "Town.h"

Town::Town(int id, string name, vector<Street*> streets){
	this->id=id;
	this->name=name;
	this->streets =streets;

}

int Town::getId(){
	return this->id;
}
string Town::getName(){
	return this->name;
}
vector <Street*> Town::getStreets(){
	return this-> streets;
}
