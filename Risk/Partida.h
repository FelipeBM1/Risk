#ifndef __PARTIDA_H__
#define __PARTIDA_H__

#include <queue>
#include "Jugador.h"
#include "Continente.h"

class Partida
{
  public:
    std::string estado;
    std::queue<Jugador*> jugadores;
    Continente* continentes[6];
    char modoJuego;
    Jugador* jugadorActual;

  public:
    Partida(char, int);
    Partida(int cantJugadores, std::queue<std::string> terrisArchivo, std::queue<int> tropasDeArchivo);
    Jugador* buscaJ (std::string);
    Continente* buscaC (std::string);
    Territorio *buscaT(std::string nombreT);
    void fortificar();
    void atacar();
    void gestorDados(Jugador* jugadorAtacante, Jugador* jugadorDefensor, Territorio* terriAtacoDesde, Territorio* terriAtaco);
    void guardarPartida(std::string);
    void guardarCompimido(std::string);
    //void iniciarPartidaConArchivo(std::string);
};

#include "Partida.cxx"

#endif