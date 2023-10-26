#include "Jugador.h"
#include "Mision.h"
#include <iostream>

Jugador::Jugador(int _cantJugadores, char _modoPartida, std::string _color) : ejercito()
{
  color = _color;
  modoPartida = _modoPartida;

  if (_cantJugadores == 3)
  {
    ejercito = 35;
  }
  else if (_cantJugadores == 4)
  {
    ejercito = 30;
  }
  else if (_cantJugadores == 5)
  {
    ejercito = 25;
  }
  else if (_cantJugadores == 6)
  {
    ejercito = 20;
  }

  modoPartida = _modoPartida;
  if (modoPartida == 'm')
  {
    mision = new Mision(color);
  }
}

void Jugador::miMision(std::string _color)
{
  int cuantosTerri = mision->cantTerri;
  std::vector<std::string> cualesTerri = mision->nomTerris;

  std::cout << "La mision del jugador (" + _color + ") es:" << std::endl;
  std::cout << "- Conquistar: " + cuantosTerri;
  std::cout << " territorios." << std::endl;
  std::cout << "- Los territorios que debe conquistar son:" << std::endl;
  for(std::vector<std::string>::iterator miIterador = cualesTerri.begin(); miIterador != cualesTerri.end(); miIterador++){
    std::cout << "  - ";
    std::cout << *miIterador << " "  << std::endl;
  }
}