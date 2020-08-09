#ifndef CONVERTIDORC_H
#define CONVERTIDORC_H

#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <vector>

#include <proj.h>


#include "Poligonal.h"

using namespace std;


class ConvertidorC {

private:

		int conviertePuntos(Punto &pori,Punto &pdest);

protected:

        PJ_CONTEXT *C;
        PJ *P;
        PJ *P_for_GIS;

        vector<Poligonal> &vPol;

public:

        ConvertidorC(vector<Poligonal> &vPol);

        ~ConvertidorC();

    int conviertePoligonos();

    

};


#endif
