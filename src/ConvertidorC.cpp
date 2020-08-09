#include "ConvertidorC.h"

/**
*
*/
ConvertidorC::ConvertidorC(vector<Poligonal> &vPol):vPol(vPol){
    C = proj_context_create();
    P = proj_create_crs_to_crs(C,"EPSG:6372","EPSG:4326",NULL);
    P_for_GIS = proj_normalize_for_visualization(C,P);
    proj_destroy(P);
    P = P_for_GIS;

}

/**
*
*/
ConvertidorC::~ConvertidorC(){
    proj_destroy(P);
    proj_context_destroy(C); 
}

/**
*
*/
int ConvertidorC::conviertePoligonos(){
    int cc=0;

    for (auto it = vPol.begin(); it != vPol.end(); ++it){
    	vector<Punto> vpt;

    	for(auto itp = it->vp.begin(); itp != it->vp.end(); ++itp){
    		Punto ptrans;

    		conviertePuntos(*itp,ptrans);

    		vpt.push_back(ptrans);
    	}

    	it->vp=vpt;
    }

    return cc;
}

/**
*
*/
int ConvertidorC::conviertePuntos(Punto &pori, Punto &pdest){
	PJ_COORD a, b;

	a = proj_coord(pori.x,pori.y,0,0);
	b = proj_trans(P,PJ_FWD,a);

	pdest.x=b.lp.lam;
	pdest.y=b.lp.phi;

	//cout <<setprecision(6)<<pori.x<<","<<pori.y<<" => "<<setprecision(6)<<pdest.x<<","<<pdest.y<<endl;

	return 0;
}