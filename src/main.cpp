#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

#include "Punto.h"
#include "Poligonal.h"
#include "LectorINT.h"
#include "ConvertidorC.h"
#include "SalidaINT.h"


using namespace std;

vector<Poligonal> vPol;


int main(int argc, char *argv[]){

	if (argc < 3) {
		cout << "Falta lista con archivo a procesar: polígonos-INT-Origen  poligonos-INT-Destino" << endl;
    	cout << "Donde: "<<endl;
    	cout << "polígonos-INT-Origen: archivo en formato INT para convertir"<<endl;
    	cout << "polígonos-INT-Destino: archivo en formato INT convertido"<<endl;
	}

	//leemos el archivo INT
  	cout << "Archivo INT: " << argv[1] << endl;

  	LectorINT lint(vPol,string(argv[1]));

  	cout << "VPol size: "<< vPol.size() << endl;

  	ConvertidorC conv(vPol);


  	cout << "Salida INT: " << argv[2] << endl;

  	SalidaINT sint(string(argv[2]),vPol);

    return 0;
}
