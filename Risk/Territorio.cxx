#include "Territorio.h"

// Constructor de Territorio
Territorio::Territorio(std::string _nombreTerri)
{
  nombreTerri = _nombreTerri;
  duenoAct = NULL;
}

// Constructor de Territorio con tropas
Territorio::Territorio(std::string _nombreTerri, int tropasDeArchivo)
{
  nombreTerri = _nombreTerri;
  duenoAct = NULL;
  uniEjercito = tropasDeArchivo;
}
