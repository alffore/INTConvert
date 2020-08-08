#ifndef CONVERTIDORC_H
#define CONVERTIDORC_H

#include <vector>
#include <proj.h>

#include "Poligonal.h"

using namespace std;

class ConvertidorC {

    protected:

        PJ_CONTEXT *C;
        PJ *P;

    public:

        ConvertidorC();

        ~ConvertidorC();

    int convierteCoords(vector<Poligonal> vp);
};


#endif
