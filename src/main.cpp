#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

#include "Punto.h"
#include "Poligonal.h"
#include "LectorINT.h"
#include "ConvertidorC.h"


using namespace std;

vector<Poligonal> vPol;


int main(int argc, char *argv[]){


	ConvertidorC cc(vPol);

	Punto *p = new Punto();
	//2489072.503500,1115771.584500
	p->x=2489072.5035;
	p->y=1115771.5845;

	Punto pdest;

	cc.conviertePuntos(p,pdest);

	cout<< pdest.x <<" "<< pdest.y <<endl;


	delete p;

    return 0;
}
