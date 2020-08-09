#ifndef LECTORINT_H
#define LECTORINT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>


#include "Poligonal.h"

#define DELIMITER       "|"


using namespace std;


class LectorINT {

public:

  

  LectorINT(vector<Poligonal>& vPol,string sarchivo);

  static void split(vector<string>& theStringVector, const string& theString, const string& theDelimiter);

private:

  vector<Poligonal>& vPol;
  string sarchivo;

  void inicializador(void);

  void parser(string scad);

  void parserSPunto(vector<Punto>& vP, const string & scad);

  static bool ordenadorP(const Poligonal& p1, const Poligonal& p2);

};

#endif
