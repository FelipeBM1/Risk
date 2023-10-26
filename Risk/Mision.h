#ifndef __MISION_H__
#define __MISION_H__

#include <list>
#include <queue>
#include <string>
#include <vector>
#include <array>

class Mision
{
  public:
    bool completada;
    int cantTerri;
    std::vector<std::string> nomTerris;

  public:
    Mision(std::string);

};

#include "Mision.cxx"

#endif