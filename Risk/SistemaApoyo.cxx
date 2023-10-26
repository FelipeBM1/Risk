#include "SistemaApoyo.h"

#include <iostream>

#define red "\033[31m"
#define blue "\033[34m"
#define yellow "\033[33m"
#define orange "\033[38;5;208m"
#define green "\033[32m"
#define magenta "\033[35m"
#define reset "\033[0m"

bool tieneTerriDisp(const std::vector<std::string> &continente);

SistemaApoyo::SistemaApoyo()
{
  partida = NULL;
}

void SistemaApoyo::crearPartida()
{

  int cantJugadores;
  char modoJuego;

  do
  {
    std::cout<<std::endl;
    std::cout << "Cuantas personas van a jugar? (min 3 - max 6): ";
    std::cin >> cantJugadores;
  } while (cantJugadores < 3 || cantJugadores > 6);

  std::cout<<std::endl;
  std::cout << "Risk, tiene dos formas de jugar: " << std::endl;
  std::cout << "Para el modo por Misiones, ingrese la tecla 'm' " << std::endl;
  std::cout << "Para el modo Normal, ingrese la tecla 'n' " << std::endl;

  do
  {
    std::cout << "Ingrese un modo de juego valido: ";
    std::cin >> modoJuego;
  } while (modoJuego != 'm' && modoJuego != 'n');

  this->partida = new Partida(modoJuego, cantJugadores);

  std::cout << std::endl;

  std::cout << "Presione Enter para continuar..." << std::endl;
  std::cin.ignore();
  std::cin.get();
  system("clear");
}

void SistemaApoyo::escojerTerris(Partida *partidaAct)
{
  // partidas
  std::vector<std::string> AmericaNorte = {"Alaska", "Alberta", "America Central", "Estados Unidos Orientales", "Groenlandia", "Territorio Noroccidental", "Ontario", "Quebec", "Estados Unidos Occidentales"};
  std::vector<std::string> AmericaSur = {"Argentina", "Brasil", "Peru", "Venezuela"};
  std::vector<std::string> Europa = {"Gran Bretana", "Islandia", "Europa del Norte", "Escandinavia", "Europa del Sur", "Ucrania", "Europa Occidental"};
  std::vector<std::string> Africa = {"Congo", "Africa Oriental", "Egipto", "Madagascar", "Africa del Norte", "Africa del Sur"};
  std::vector<std::string> Asia = {"Afghanistan", "China", "India", "Irkutsk", "Japon", "Kamchatka", "Medio Oriente", "Mongolia", "Siam", "Siberia", "Ural", "Yakutsk"};
  std::vector<std::string> Australia = {"Australia Oriental", "Indonesia", "Nueva Guinea", "Australia Occidental"};

  std::string salvaNomTerri;

  int conta_terr = 0;
  int cantJ = partidaAct->jugadores.size();
  int eleccion1;
  int eleccion2;
  std::string colJugadores[6] = {"rojo", "azul", "amarillo", "naranja", "verde", "rosado"};
  std::string coltext [6] = {red, blue, yellow, orange, green, magenta};
  std::string auxContis[6] = {"America Del Norte", "America Del Sur", "Asia", "Africa", "Europa", "Australia"};

  std::string aux[cantJ];

  for (int i = 0; i < cantJ; i++)
  {
    aux[i] = colJugadores[i];
  }

  while (conta_terr < 42)
  {
    for (int i = 0; i < cantJ; i++)
    {
      std::cout << "Jugador "<<coltext[i]<<"(" + aux[i]+ ")"<<reset<<" es su turno para:" << std::endl;
      std::cout << "Elijir uno de los siguientes continetes:" << std::endl;
      std::cout << "1. America del Norte" << std::endl;
      std::cout << "2. America del Sur" << std::endl;
      std::cout << "3. Europa" << std::endl;
      std::cout << "4. Africa" << std::endl;
      std::cout << "5. Asia" << std::endl;
      std::cout << "6. Australia" << std::endl;
      std::cout << "Ingrese el numero del continente seleccionado: ";
      std::cin >> eleccion1;
      std::cout << std::endl;

      switch (eleccion1)
      {
        
        case 1:
        {
          if (!tieneTerriDisp(AmericaNorte))
          {
            std::cout << "No hay territorios disponibles en America del Norte." << std::endl;
            std::cout<<std::endl;

            i = i-1;
            break;
          }

          std::cout << "Territorios disponibles en America del Norte:" << std::endl;
          for (size_t j = 0; j < AmericaNorte.size(); j++)
          {
            std::cout << j + 1 << ". " << AmericaNorte[j] << std::endl;
          }

          std::cout << "Ingrese el numero del territorio seleccionado: ";
          std::cin >> eleccion2;

          if (eleccion2 >= 1 && eleccion2 <= AmericaNorte.size())
          {
            salvaNomTerri = AmericaNorte[eleccion2 - 1];
            Jugador *player = partidaAct->buscaJ(aux[i]);

            for(int i = 0; i < 12; i++){
              if (partidaAct->continentes[0]->territorios[i]->nombreTerri == salvaNomTerri)
              {
                partidaAct->continentes[0]->territorios[i]->duenoAct = player;
                player->ejercito = player->ejercito - 1;
                partidaAct->continentes[0]->territorios[i]->uniEjercito = 1;
                break;
              }              
            }

            std::cout<<std::endl;
            std::cout << "Territorio elegido: " << AmericaNorte[eleccion2 - 1] << std::endl;
            std::cout << std::endl;
            AmericaNorte.erase(AmericaNorte.begin() + eleccion2 - 1);
            conta_terr++;
            
            std::cout << "Presione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            system("clear");

          }
          else
          {
            std::cout<<std::endl;
            std::cout << "Numero de territorio invalido." << std::endl;
            std::cout<<std::endl;
            i = i-1;
          }

          break;
        }

        case 2:
        {
          if (!tieneTerriDisp(AmericaSur))
          {
            std::cout << "No hay territorios disponibles en America del Sur." << std::endl;
            std::cout<<std::endl;

            i = i-1;
            break;
          }

          std::cout << "Territorios disponibles en America del Sur:" << std::endl;
          for (size_t j = 0; j < AmericaSur.size(); j++)
          {
            std::cout << j + 1 << ". " << AmericaSur[j] << std::endl;
          }

          std::cout << "Ingrese el numero del territorio seleccionado: ";
          std::cin >> eleccion2;

          if (eleccion2 >= 1 && eleccion2 <= AmericaSur.size())
          {
            salvaNomTerri = AmericaSur[eleccion2 - 1];
            Jugador *player = partidaAct->buscaJ(aux[i]);

            for(int i = 0; i < 4; i++){
              if (partidaAct->continentes[1]->territorios[i]->nombreTerri == salvaNomTerri)
              {
                partidaAct->continentes[1]->territorios[i]->duenoAct = player;
                player->ejercito = player->ejercito - 1;
                partidaAct->continentes[1]->territorios[i]->uniEjercito = 1;
                break;
              }              
            }

            std::cout<<std::endl;
            std::cout << "Territorio elegido: " << AmericaSur[eleccion2 - 1] << std::endl;
            std::cout<<std::endl;

            AmericaSur.erase(AmericaSur.begin() + eleccion2 - 1);
            conta_terr++;

            std::cout << "Presione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            system("clear");
          }
          else
          {
            std::cout<<std::endl;
            std::cout << "Numero de territorio invalido." << std::endl;
            std::cout<<std::endl;
            i = i-1;
          }

          break;
        }

        case 3:
        {
          if (!tieneTerriDisp(Europa))
          {
            std::cout << "No hay territorios disponibles en Europa." << std::endl;
            std::cout<<std::endl;

            i = i-1;
            break;
          }

          std::cout << "Territorios disponibles en Europa:" << std::endl;
          for (size_t j = 0; j < Europa.size(); j++)
          {
            std::cout << j + 1 << ". " << Europa[j] << std::endl;
          }

          std::cout << "Ingrese el numero del territorio seleccionado: ";
          std::cin >> eleccion2;
          if (eleccion2 >= 1 && eleccion2 <= Europa.size())
          {
            salvaNomTerri = Europa[eleccion2 - 1];
            Jugador *player = partidaAct->buscaJ(aux[i]);

            for(int i = 0; i < 7; i++){
              if (partidaAct->continentes[4]->territorios[i]->nombreTerri == salvaNomTerri)
              {
                partidaAct->continentes[4]->territorios[i]->duenoAct = player;
                player->ejercito = player->ejercito - 1;
                partidaAct->continentes[4]->territorios[i]->uniEjercito = 1;
                break;
              }              
            }

            std::cout<<std::endl;
            std::cout << "Territorio elegido: " << Europa[eleccion2 - 1] << std::endl;
            std::cout<<std::endl;

            Europa.erase(Europa.begin() + eleccion2 - 1);
            conta_terr++;

            std::cout << "Presione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            system("clear");
          }
          else
          {
            std::cout<<std::endl;
            std::cout << "Numero de territorio invalido." << std::endl;
            std::cout<<std::endl;
            i = i-1;
          }

          break;
        }

        case 4:
        {
          if (!tieneTerriDisp(Africa))
          {
            std::cout << "No hay territorios disponibles en Africa." << std::endl;
            std::cout<<std::endl;

            i = i-1;
            break;
          }

          std::cout << "Territorios disponibles en Africa:" << std::endl;
          for (size_t j = 0; j < Africa.size(); j++)
          {
            std::cout << j + 1 << ". " << Africa[j] << std::endl;
          }
          std::cout << "Ingrese el numero del territorio seleccionado: ";
          std::cin >> eleccion2;

          if (eleccion2 >= 1 && eleccion2 <= Africa.size())
          {
            salvaNomTerri = Africa[eleccion2 - 1];
            Jugador *player = partidaAct->buscaJ(aux[i]);

            for(int i = 0; i < 6; i++){
              if (partidaAct->continentes[3]->territorios[i]->nombreTerri == salvaNomTerri)
              {
                partidaAct->continentes[3]->territorios[i]->duenoAct = player;
                player->ejercito = player->ejercito - 1;
                partidaAct->continentes[3]->territorios[i]->uniEjercito = 1;
                break;
              }              
            }

            std::cout<<std::endl;
            std::cout << "Territorio elegido: " << Africa[eleccion2 - 1] << std::endl;
            std::cout<<std::endl;

            Africa.erase(Africa.begin() + eleccion2 - 1);
            conta_terr++;

            std::cout << "Presione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            system("clear");
          }
          else
          {
            std::cout<<std::endl;
            std::cout << "Numero de territorio invalido." << std::endl;
            std::cout<<std::endl;
            i = i-1;
          }

          break;
        }

        case 5:
        {
          if (!tieneTerriDisp(Asia))
          {
            std::cout << "No hay territorios disponibles en Asia." << std::endl;
            std::cout<<std::endl;

            i = i-1;
            break;
          }

          std::cout << "Territorios disponibles en Asia:" << std::endl;
          for (size_t j = 0; j < Asia.size(); j++)
          {
            std::cout << j + 1 << ". " << Asia[j] << std::endl;
          }

          std::cout << "Ingrese el numero del territorio seleccionado: ";
          std::cin >> eleccion2;
          if (eleccion2 >= 1 && eleccion2 <= Asia.size())
          {
            salvaNomTerri = Asia[eleccion2 - 1];
            Jugador *player = partidaAct->buscaJ(aux[i]);

            for(int i = 0; i < 12; i++){
              if (partidaAct->continentes[2]->territorios[i]->nombreTerri == salvaNomTerri)
              {
                partidaAct->continentes[2]->territorios[i]->duenoAct = player;
                player->ejercito = player->ejercito - 1;
                partidaAct->continentes[2]->territorios[i]->uniEjercito = 1;
                break;
              }              
            }

            std::cout<<std::endl;
            std::cout << "Territorio elegido: " << Asia[eleccion2 - 1] << std::endl;
            std::cout<<std::endl;

            Asia.erase(Asia.begin() + eleccion2 - 1);
            conta_terr++;

            std::cout << "Presione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            system("clear");
          }
          else
          {
            std::cout<<std::endl;
            std::cout << "Numero de territorio invalido." << std::endl;
            std::cout<<std::endl;
            i = i-1;
          }

          break;
        }

        case 6:
        {
          if (!tieneTerriDisp(Australia))
          {
            std::cout << "No hay territorios disponibles en Australia." << std::endl;
            std::cout<<std::endl;

            i = i-1;
            break;
          }

          std::cout << "Territorios disponibles en Australia:" << std::endl;
          for (size_t j = 0; j < Australia.size(); j++)
          {
            std::cout << j + 1 << ". " << Australia[j] << std::endl;
          }

          std::cout << "Ingrese el numero del territorio seleccionado: ";
          std::cin >> eleccion2;
          if (eleccion2 >= 1 && eleccion2 <= Australia.size())
          {
            salvaNomTerri = Australia[eleccion2 - 1];
            Jugador *player = partidaAct->buscaJ(aux[i]);

            for(int i = 0; i < 4; i++){
              if (partidaAct->continentes[5]->territorios[i]->nombreTerri == salvaNomTerri)
              {
                partidaAct->continentes[5]->territorios[i]->duenoAct = player;
                player->ejercito = player->ejercito - 1;
                partidaAct->continentes[5]->territorios[i]->uniEjercito = 1;
                break;
              }              
            }

            std::cout<<std::endl;
            std::cout << "Territorio elegido: " << Australia[eleccion2 - 1] << std::endl;
            std::cout<<std::endl;

            Australia.erase(Australia.begin() + eleccion2 - 1);
            conta_terr++;

            std::cout << "Presione Enter para continuar..." << std::endl;
            std::cin.ignore();
            std::cin.get();
            system("clear");
          }
          else
          {
            std::cout<<std::endl;
            std::cout << "Numero de territorio invalido." << std::endl;
            std::cout<<std::endl;
            i = i-1;
          }

          break;
        }

        default:
        {
          std::cout << "Continente no valido. Intente nuevamente." << std::endl;
          std::cout<<std::endl;
          i = i-1;

          break;
        }
      }
      //limpiamos el buffer
      std::cin.clear();
    }
  }
  std::cout<<"Se ha inizializado la partida correctamente"<<std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

}

void SistemaApoyo::repartirTropas(Partida *partidaAct)
{
  int cantJ = partidaAct->jugadores.size();
  int asignTrops = 0;
  
  std::string colJugadores[6] = {"rojo", "azul", "amarillo", "naranja", "verde", "rosado"};
  std::string coltext [6] = {red, blue, yellow, orange, green, magenta};
  std::string aux[cantJ];

  for (int i = 0; i < cantJ; i++)
  {
    aux[i] = colJugadores[i];
  }

  std::cout << "Ahora cada jugador debe repartir sus tropas en los territorios que eligio." << std::endl;
  std::cout << std::endl;

  for (int h = 0; h < cantJ; h++)
  {
    std::cout << "Turno del Jugador "<<coltext[h]<<"(" + aux[h]+ ")"<<reset<<" para distribuir tropas en los territorios que eligio:" << std::endl;
    for (int i = 0; i < 6; i++)
    {
      std::cout<<std::endl;
      std::cout << "En el continente " << partidaAct->continentes[i]->nombreCont << " dominas los siguientes territorios: " << std::endl;
      for (int j = 0; j < partidaAct->continentes[i]->territorios.size(); j++) //
      {
        if (partidaAct->continentes[i]->territorios[j]->duenoAct->color == aux[h])
        {

          if (partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito == 0)
          {
            std::cout << "Ya no tienes mas tropas disponibles para repartir." << std::endl;
            std::cout << std::endl;
            break; // si el jugador no tiene mas tropas disponibles, se pasa al siguiente jugador
          }  

          std::cout << std::endl;
          std::cout << "Recuerda que justo ahora tienes en total: " << partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito << " tropas disponibles." << std::endl;

          std::cout << " - " << partidaAct->continentes[i]->territorios[j]->nombreTerri << " tiene: " << partidaAct->continentes[i]->territorios[j]->uniEjercito << " tropas"<< std::endl;
          std::cout << "Ingresa cuantas tropas quieres agregarle a este territorio: ";
          std::cin >> asignTrops;
          std::cout << std::endl;

          while (asignTrops > partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito || asignTrops < 0)
          {
            std::cout << std::endl;
            std::cout << "Cantidad de tropas invalida." << std::endl;
            std::cout << "Recuerda que tienes: " << partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito << " tropas disponibles." << std::endl;
            std::cout << "Ingresa una cantidad de tropas no mayor ni menor a las que tienes disponibles" << std::endl;
            std::cout << std::endl;
            std::cout << " - " << partidaAct->continentes[i]->territorios[j]->nombreTerri << " tiene: " << partidaAct->continentes[i]->territorios[j]->uniEjercito << " tropas"<< std::endl;
          std::cout << "Ingresa cuantas tropas quieres agregarle a este territorio: ";
            std::cin >> asignTrops;
            std::cout << std::endl;
          }          

          partidaAct->continentes[i]->territorios[j]->uniEjercito = partidaAct->continentes[i]->territorios[j]->uniEjercito + asignTrops; // asigna las tropas al territorio
          partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito = partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito - asignTrops; // resta las tropas al jugador

          if (partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito == 0)
          {
            std::cout << "Ya no tienes mas tropas disponibles para repartir." << std::endl;
            std::cout << std::endl;
            break; // si el jugador no tiene mas tropas disponibles, se pasa al siguiente jugador
          }        
          
        }        
      }
      std::cout << std::endl;
      std::cout << "--------------------------------------------------------" << std::endl;
      std::cout << std::endl;
    }
    if (partidaAct->buscaJ(aux[h])->ejercito > 0) // 
    {
      std::cout << "Aun tienes tropas disponibles para repartir." << std::endl;
      std::cout << std::endl;
      std::cout << "Presione Enter para continuar..." << std::endl;
      std::cin.ignore();
      std::cin.get();
      system("clear");
      h = h-1;
    }    
    std::cout << "Presione Enter para continuar..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");
  }

}


void SistemaApoyo::accionesTurno(Partida *partidaAct)
{
  int uniEjerAdicionales = 0;
  int asignTrops = 0;
  
  for(Continente* continente : partidaAct->continentes)
  {
    for(Territorio* territorio : continente->territorios)
    {
      if (partidaAct->jugadorActual->color == territorio->duenoAct->color)
      {
        uniEjerAdicionales++;
      }
    }
  }

  std::cout << std::endl;
  std::cout << "Como actualmente tienes " << uniEjerAdicionales << " continentes conquistados, vas a recibir: ";

  uniEjerAdicionales = uniEjerAdicionales / 3;

  std::cout << uniEjerAdicionales << " tropas adicionales." << std::endl;

  partidaAct->jugadorActual->ejercito = partidaAct->jugadorActual->ejercito + uniEjerAdicionales;

  do
  {
    for (int i = 0; i < 6; i++)
    {
      std::cout << "Del continente: " << partidaAct->continentes[i]->nombreCont << std::endl;
      for (int j = 0; j < partidaAct->continentes[i]->territorios.size(); j++) //
      {
        if (partidaAct->continentes[i]->territorios[j]->duenoAct->color == partidaAct->jugadorActual->color)
        {

          if (partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito == 0)
          {
            std::cout << "Ya no tienes mas tropas disponibles para repartir." << std::endl;
            std::cout << std::endl;
            break; // si el jugador no tiene mas tropas disponibles, se pasa al siguiente jugador
          }  

          std::cout << "Justo ahora tienes en total: " << partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito << " tropas disponibles." << std::endl;
          std::cout << " - El territorio: " << partidaAct->continentes[i]->territorios[j]->nombreTerri << " va a tener " << partidaAct->continentes[i]->territorios[j]->uniEjercito << " + ";
          std::cin >> asignTrops;
          std::cout << std::endl;

          while (asignTrops > partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito || asignTrops < 0)
          {
            std::cout << std::endl;
            std::cout << "Recuerda que tienes: " << partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito << " tropas disponibles." << std::endl;
            std::cout << "Ingresa una cantidad de tropas valida para este territorio." << std::endl;
            std::cout << "- El territorio: " << partidaAct->continentes[i]->territorios[j]->nombreTerri << " va a tener " << partidaAct->continentes[i]->territorios[j]->uniEjercito << " + ";
            std::cin >> asignTrops;
            std::cout << std::endl;
          }          

          partidaAct->continentes[i]->territorios[j]->uniEjercito = partidaAct->continentes[i]->territorios[j]->uniEjercito + asignTrops; // asigna las tropas al territorio
          partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito = partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito - asignTrops; // resta las tropas al jugador

          if (partidaAct->continentes[i]->territorios[j]->duenoAct->ejercito == 0)
          {
            std::cout << "Ya no tienes mas tropas disponibles para repartir." << std::endl;
            std::cout << std::endl;
            break; // si el jugador no tiene mas tropas disponibles, se pasa al siguiente jugador
          }        
          
        }        
      }
      std::cout << std::endl;
      std::cout << "--------------------------------------------------------" << std::endl;
      std::cout << std::endl;
    }

    std::cout << "Aun tienes tropas disponibles para repartir." << std::endl;
    std::cout << "Presione Enter para continuar..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    system("clear");

  } while (partidaAct->jugadorActual->ejercito > 0);

  std::cout << "Ya que recibiste tus tropas adicionales y las repartiste en tus territorios" << std::endl;

  //ciclo para asegurarse que el jugador ingrese una opcion valida
  int eleccion;
  do
  {
    std::cout << "Elije lo que deseas hacer en este turno: " << std::endl;
    std::cout << "1. Atacar" << std::endl;
    std::cout << "2. Fortificar" << std::endl;

    std::cout << "Ingrese el numero de la accion que desea realizar: ";
    std::cin >> eleccion;
    std::cout << std::endl;

    switch (eleccion)
    {
      case 1:
      {
        std::cout << "Atacar" << std::endl;
        partidaAct->atacar();
        break;
      }

      case 2:
      {
        std::cout << "Fortificar" << std::endl;
        partidaAct->fortificar();
        break;
      }

      default:
      {
        std::cout << "Accion no valida. Vuelva aintentarlo" << std::endl;
        break;
      }
    }
  } while (eleccion != 1 && eleccion != 2);


}


bool tieneTerriDisp(const std::vector<std::string> &continente)
{
  return !continente.empty();
}

