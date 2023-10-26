#include "Mision.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>


Mision::Mision(std::string colorJ) : nomTerris()
{
  std::srand(std::time(0));
  std::vector<int> randTerri;
  std::string confirmacion;
  std::string terris[42] = {"Alaska", "Alberta", "Ameica Central", "Estados Unidos Orientales", "Groenlandia", "Territorio Noroccidental", "Ontario", "Quebec", "Estados Unidos Occidentales",
                            "Argentina", "Brasil", "Peru", "Venezuela",
                            "Afghanistan", "China", "India", "Irkutsk", "Japon", "Kamchatka", "Medio Oriente", "Mongolia", "Siam", "Siberia", "Ural", "Yakutsk",
                            "Congo", "Africa Oriental", "Egipto", "Madagascar", "Africa del Norte", "Africa del Sur",
                            "Gran Bretana", "Islandia", "Europa del Norte", "Escandinavia", "Europa del Sur", "Ucrania", "Europa Occidental",
                            "Australia Oriental", "Indonesia", "Nueva Guinea", "Australia Occidental"};
  
  completada = false;
  cantTerri = std::rand() % 6 + 10; // de 10 a 15

  for (int i = 0; i < 42; i++)
  {
    randTerri.push_back(i);
  }
  std::random_shuffle(randTerri.begin(), randTerri.end());
  for (int i = 0; i < cantTerri; ++i) {
    int cual = randTerri[i];
    nomTerris.push_back(terris[cual]);
  } 

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Al estar en modo de juego por Misiones secretas," << std::endl;
  std::cout << "se tiene que definir su mision para poder ganar el juego." << std::endl;
  std::cout << std::endl;
  std::cout << "Para esto, de forma aleatoria se definen cuantos territorios y cuales debe conquistar para ganar" << std::endl;
  std::cout << "- El jugador (" + colorJ + ") tiene que conquistar: ";
  std::cout << cantTerri;
  std::cout << " territorios." << std::endl;
  std::cout << "- Para ser mas especificos: " << std::endl;
  for(std::vector<std::string>::iterator miIterador = nomTerris.begin(); miIterador != nomTerris.end(); miIterador++){
    std::cout << "  - ";
    std::cout << *miIterador << " "  << std::endl;
  }
  
  std::cout << "Para continuar escriba cualquier cosa: ";
  std::cin >> confirmacion;
  std::cout << std::endl;
  std::cout << std::endl;

}