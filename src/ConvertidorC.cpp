#include "ConvertidorC.h"

ConvertidorC::ConvertidorC(){
    C = proj_context_create();
    P = proj_create_crs_to_crs(C,"EPSG:6372","EPSG:4326",NULL);
}


ConvertidorC::~ConvertidorC(){
    proj_destroy(P);
    proj_context_destroy(C); 
}


int ConvertidorC::convierteCoords(){
    int cc=0;

    return cc;
}