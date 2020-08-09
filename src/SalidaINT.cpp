#include "SalidaINT.h"


SalidaINT::SalidaINT(string sarchivo,vector<Poligonal> &vPol):sarchivo(sarchivo),vPol(vPol){

	//escribeArchivo();

}


int SalidaINT::escribeArchivo(){

	fssal.open(sarchivo.c_str());
	
	for (auto it = vPol.begin(); it != vPol.end(); ++it){


		for (auto itp = it->vp.begin(); itp != it->vp.end(); ++itp){

		}

		fssal<<endl;
	} 
	
	fssal.close();

	return 0;
}