#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "Mision.h"

#include <list>
#include <string>
#include <vector>

class Jugador
{
  public:
    std::string color;
    char modoPartida;
    int ejercito;
    Mision* mision;

  public:
    Jugador(int,char,std::string);
    void miMision(std::string);
    

};

#include "Jugador.cxx"

#endif