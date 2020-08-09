#include "ConvertidorC.h"

ConvertidorC::ConvertidorC(vector<Poligonal> &vPol):vPol(vPol){
    C = proj_context_create();
    P = proj_create_crs_to_crs(C,"EPSG:6372","EPSG:4326",NULL);
}


ConvertidorC::~ConvertidorC(){
    proj_destroy(P);
    proj_context_destroy(C); 
}


int ConvertidorC::convierteCoords(){
    int cc=0;

    for (auto it = vPol.begin(); it != vPol.end(); ++it){

    	for(auto itp = it->vp.begin();itp != it->vp.end();++itp){

    		cout << itp->x << " "<< itp->y <<endl;
    	}
    }

    return cc;
}


int ConvertidorC::conviertePuntos(Punto* pori, Punto &pdest){
	PJ_COORD a, b;

	a= proj_coords(pori->x,pori->y,0,0);
	b= proj_trans(P,PJ_FWD,a);

	pdest.x=b.lp.lam;
	pdest.y=b.lp.phi;

	return 0;
}