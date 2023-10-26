#ifndef __TERRITORIO_H__
#define __TERRITORIO_H__

#include <vector>
#include <string>
#include "Jugador.h"

class Territorio
{
  public:
    std::string nombreTerri;
    std::vector<std::string> terriAdy;
    Jugador* duenoAct;
    int uniEjercito;

  public:
    Territorio(std::string);
    Territorio(std::string _nombreTerri, int tropasDeArchivo);
};

#include "Territorio.cxx"

#endif

