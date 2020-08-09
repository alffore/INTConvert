#ifndef CONVERTIDORC_H
#define CONVERTIDORC_H

#include <vector>
#include <proj.h>

#include "Punto.h"
#include "Poligonal.h"

using namespace std;

class ConvertidorC {

    protected:

        PJ_CONTEXT *C;
        PJ *P;

        vector<Poligonal> &vPol;

    public:

        ConvertidorC(vector<Poligonal> &vPol);

        ~ConvertidorC();

    int convierteCoords();

    int conviertePuntos(Punto* pori,Punto &pdest);
};


#endif
