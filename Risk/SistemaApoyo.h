#ifndef __SISTEMAAPOYO_H__
#define __SISTEMAAPOYO_H__

#include "Partida.h"

class SistemaApoyo
{
  public:
   Partida* partida;

  public:
    SistemaApoyo();
    void crearPartida();
    void escojerTerris(Partida *partidaAct);
    void repartirTropas(Partida *partidaAct);
    void accionesTurno(Partida *partidaAct);
    void fortificar();
};

#include "SistemaApoyo.cxx"

#endif