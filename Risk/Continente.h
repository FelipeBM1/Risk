#ifndef __CONTINENTE_H__
#define __CONTINENTE_H__

#include <vector>
#include <string>
#include <queue>

#include "Territorio.h"

class Continente
{
  public:
    std::string nombreCont;
    std::vector<Territorio*>territorios;
  public:
        Continente(std::string);
        Continente(std::string, int tropasDeArchivo[]);
        Territorio* buscaT (std::string);
};

#include "Continente.cxx"

#endif