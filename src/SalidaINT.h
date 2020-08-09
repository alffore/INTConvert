#ifndef SALIDAINT_H
#define SALIDAINT_H

#include <iostream>
#include <iomanip> 
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <vector>


#include "Poligonal.h"

using namespace std;


class SalidaINT {

private:
	string sarchivo;
	vector<Poligonal> &vPol;	
	ofstream fssal;

	int escribeArchivo();

public:

	SalidaINT(string sarchivo, vector<Poligonal> &vPol);

};

#endif 