#include "Continente.h"
#include "Territorio.h"

// Constructor de Continente
Continente::Continente(std::string _nombreCont) : nombreCont(_nombreCont), territorios()
{
  std::string terrisANOR[9] = {"Alaska", "Alberta", "America Central", "Estados Unidos Orientales", "Groenlandia", "Territorio Noroccidental", "Ontario", "Quebec", "Estados Unidos Occidentales"};
  std::string terrisASUR[4] = {"Argentina", "Brasil", "Peru", "Venezuela"};
  std::string terrisASIA[12] = {"Afghanistan", "China", "India", "Irkutsk", "Japon", "Kamchatka", "Medio Oriente", "Mongolia", "Siam", "Siberia", "Ural", "Yakutsk"};
  std::string terrisAFRC[6] = {"Congo", "Africa Oriental", "Egipto", "Madagascar", "Africa del Norte", "Africa del Sur"};
  std::string terrisEROP[7] = {"Gran Bretana", "Islandia", "Europa del Norte", "Escandinavia", "Europa del Sur", "Ucrania", "Europa Occidental"};
  std::string terrisASTR[4] = {"Australia Oriental", "Indonesia", "Nueva Guinea", "Australia Occidental"};

  if (nombreCont == "America Del Norte")
  {
    for (int i = 0; i < 9; i++)
    {
      territorios.push_back(new Territorio(terrisANOR[i]));
    }
  }
  else if (nombreCont == "America Del Sur")
  {
    for (int i = 0; i < 4; i++)
    {
      Territorio actTerri(terrisASUR[i]);

      territorios.push_back(new Territorio(terrisASUR[i]));
    }
  }
  else if (nombreCont == "Asia")
  {
    for (int i = 0; i < 12; i++)
    {
      territorios.push_back(new Territorio(terrisASIA[i]));
    }
  }
  else if (nombreCont == "Africa")
  {
    for (int i = 0; i < 6; i++)
    {

      territorios.push_back(new Territorio(terrisAFRC[i]));
    }
  }
  else if (nombreCont == "Europa")
  {
    for (int i = 0; i < 7; i++)
    {

      territorios.push_back(new Territorio(terrisEROP[i]));
    }
  }
  else if (nombreCont == "Australia")
  {
    for (int i = 0; i < 4; i++)
    {

      territorios.push_back(new Territorio(terrisASTR[i]));
    }
  }
}

// Constructor de Continente con archivo
Continente::Continente(std::string _nombreCont, int tropasDeArchivo[]) : territorios()
{
  std::string terrisANOR[9] = {"Alaska", "Alberta", "America Central", "Estados Unidos Orientales", "Groenlandia", "Territorio Noroccidental", "Ontario", "Quebec", "Estados Unidos Occidentales"};
  std::string terrisASUR[4] = {"Argentina", "Brasil", "Peru", "Venezuela"};
  std::string terrisASIA[12] = {"Afghanistan", "China", "India", "Irkutsk", "Japon", "Kamchatka", "Medio Oriente", "Mongolia", "Siam", "Siberia", "Ural", "Yakutsk"};
  std::string terrisAFRC[6] = {"Congo", "Africa Oriental", "Egipto", "Madagascar", "Africa del Norte", "Africa del Sur"};
  std::string terrisEROP[7] = {"Gran Bretana", "Islandia", "Europa del Norte", "Escandinavia", "Europa del Sur", "Ucrania", "Europa Occidental"};
  std::string terrisASTR[4] = {"Australia Oriental", "Indonesia", "Nueva Guinea", "Australia Occidental"};

  if (nombreCont == "America Del Norte")
  {
    for (int i = 0; i < 9; i++)
    {
      territorios.push_back(new Territorio(terrisANOR[i], tropasDeArchivo[i]));
    }
  }
  else if (nombreCont == "America Del Sur")
  {
    for (int i = 0; i < 4; i++)
    {
      Territorio actTerri(terrisASUR[i]);

      territorios.push_back(new Territorio(terrisASUR[i], tropasDeArchivo[i]));
    }
  }
  else if (nombreCont == "Asia")
  {
    for (int i = 0; i < 12; i++)
    {
      territorios.push_back(new Territorio(terrisASIA[i], tropasDeArchivo[i]));
    }
  }
  else if (nombreCont == "Africa")
  {
    for (int i = 0; i < 6; i++)
    {

      territorios.push_back(new Territorio(terrisAFRC[i], tropasDeArchivo[i]));
    }
  }
  else if (nombreCont == "Europa")
  {
    for (int i = 0; i < 7; i++)
    {

      territorios.push_back(new Territorio(terrisEROP[i], tropasDeArchivo[i]));
    }
  }
  else if (nombreCont == "Australia")
  {
    for (int i = 0; i < 4; i++)
    {

      territorios.push_back(new Territorio(terrisASTR[i], tropasDeArchivo[i]));
    }
  }
}

Territorio *Continente::buscaT(std::string nombTerri)
{
  for (Territorio *terriObj : territorios)
  {
    if (terriObj && terriObj->nombreTerri == nombTerri)
    {
      return terriObj; // Devuelve el puntero al territorio con el nombre especificado
    }
  }
  return NULL; // Si no se encuentra el territorio
}