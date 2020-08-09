#include "SalidaINT.h"


SalidaINT::SalidaINT(string sarchivo,vector<Poligonal> &vPol):vPol(vPol){

	this->sarchivo=sarchivo;
	escribeArchivo();

}


int SalidaINT::escribeArchivo(){

	fssal.open(sarchivo.c_str());
	
	for (auto it = vPol.begin(); it != vPol.end(); ++it){
		int cantipuntos=atoi((it->vcad[1]).c_str());
		fssal << it->vcad[0] << '|' <<it->vcad[1]<< '|';

		fssal.precision(9);

		for (auto itp = it->vp.begin(); itp != it->vp.end(); ++itp){
			fssal << itp->x << "," << itp->y;
			if(cantipuntos>1){
				fssal<<",";
				cantipuntos--;
			}
		}


		fssal << '|' << it->vcad[3] << '|' << it->vcad[4]<< '|' << it->vcad[5];

		if(it->vcad.size()>=7){
			fssal<<'|' <<it->vcad[6];
		}

		
		fssal<<endl;
	} 
	
	fssal.close();

	return 0;
}