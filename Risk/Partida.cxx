#include "Partida.h"
#include "fstream"
#include "HuffmanArbol.h"
#include <sstream>
#include <map>

Partida::Partida(char _modoJuego, int cantJugadores) : jugadores(), continentes(), modoJuego(_modoJuego) // Constructor de partida
{
  std::string coloresJ[6] = {"rojo", "azul", "amarillo", "naranja", "verde", "rosado"};

  estado = "En Curso"; // Posibles estados: "En Curso", "Terminada"

  for (int i = 0; i < cantJugadores; i++)
  {
    jugadores.push(new Jugador(cantJugadores, modoJuego, coloresJ[i]));
  }

  continentes[0] = new Continente("America Del Norte");
  continentes[1] = new Continente("America Del Sur");
  continentes[2] = new Continente("Asia");
  continentes[3] = new Continente("Africa");
  continentes[4] = new Continente("Europa");
  continentes[5] = new Continente("Australia");

  if (!jugadores.empty())
  {
    jugadorActual = jugadores.front(); // Inicializa el puntero al primer jugador
  }
}

Partida::Partida(int cantJugadores, std::queue<std::string> terrisArchivo, std::queue<int> tropasDeArchivo)  // Constructor de partida
{
  char modoJuego = 'n';
  std::string coloresJ[6] = {"rojo", "azul", "amarillo", "naranja", "verde", "rosado"};

  int tropasANOR[12];
  int tropasASUR[4];
  int tropasASIA[12];
  int tropasAFRC[6];
  int tropasEROP[7];
  int tropasASTR[4];

  std::string terrisANOR[9] = {"Alaska", "Alberta", "America Central", "Estados Unidos Orientales", "Groenlandia", "Territorio Noroccidental", "Ontario", "Quebec", "Estados Unidos Occidentales"};
  std::string terrisASUR[4] = {"Argentina", "Brasil", "Peru", "Venezuela"};
  std::string terrisASIA[12] = {"Afghanistan", "China", "India", "Irkutsk", "Japon", "Kamchatka", "Medio Oriente", "Mongolia", "Siam", "Siberia", "Ural", "Yakutsk"};
  std::string terrisAFRC[6] = {"Congo", "Africa Oriental", "Egipto", "Madagascar", "Africa del Norte", "Africa del Sur"};
  std::string terrisEROP[7] = {"Gran Bretana", "Islandia", "Europa del Norte", "Escandinavia", "Europa del Sur", "Ucrania", "Europa Occidental"};
  std::string terrisASTR[4] = {"Australia Oriental", "Indonesia", "Nueva Guinea", "Australia Occidental"};

  estado = "En Curso"; // Posibles estados: "En Curso", "Terminada"

  for(int i = 0; i < 9; i++)
  {
    if(terrisArchivo.front() == terrisANOR[i]) //Esto es para 
    {
      tropasANOR[i] = tropasDeArchivo.front(); 
    }
    else
    {

      std::string auxNomTerriArchivo = terrisArchivo.front();
      terrisArchivo.pop();
      terrisArchivo.push(auxNomTerriArchivo);
      int auxTropasDeArchivo = tropasDeArchivo.front();
      tropasDeArchivo.pop();     
      tropasDeArchivo.push(auxTropasDeArchivo);


    }
  }

  for(int i = 0; i < 4; i++)
  {
    if(terrisArchivo.front() == terrisASUR[i]) //Esto es para 
    {
      tropasASUR[i] = tropasDeArchivo.front(); 
    }
    else
    {

      std::string auxNomTerriArchivo = terrisArchivo.front();
      terrisArchivo.pop();
      terrisArchivo.push(auxNomTerriArchivo);
      int auxTropasDeArchivo = tropasDeArchivo.front();
      tropasDeArchivo.pop();     
      tropasDeArchivo.push(auxTropasDeArchivo);


    }
  }

  for(int i = 0; i < 12; i++)
  {
    if(terrisArchivo.front() == terrisASIA[i]) //Esto es para 
    {
      tropasASIA[i] = tropasDeArchivo.front(); 
    }
    else
    {

      std::string auxNomTerriArchivo = terrisArchivo.front();
      terrisArchivo.pop();
      terrisArchivo.push(auxNomTerriArchivo);
      int auxTropasDeArchivo = tropasDeArchivo.front();
      tropasDeArchivo.pop();     
      tropasDeArchivo.push(auxTropasDeArchivo);
    }
  }

  for(int i = 0; i < 6; i++)
  {
    if(terrisArchivo.front() == terrisAFRC[i]) //Esto es para 
    {
      tropasAFRC[i] = tropasDeArchivo.front(); 
    }
    else
    {

      std::string auxNomTerriArchivo = terrisArchivo.front();
      terrisArchivo.pop();
      terrisArchivo.push(auxNomTerriArchivo);
      int auxTropasDeArchivo = tropasDeArchivo.front();
      tropasDeArchivo.pop();     
      tropasDeArchivo.push(auxTropasDeArchivo);
    }
  }

  for(int i = 0; i < 7; i++)
  {
    if(terrisArchivo.front() == terrisEROP[i]) //Esto es para 
    {
      tropasEROP[i] = tropasDeArchivo.front(); 
    }
    else
    {

      std::string auxNomTerriArchivo = terrisArchivo.front();
      terrisArchivo.pop();
      terrisArchivo.push(auxNomTerriArchivo);
      int auxTropasDeArchivo = tropasDeArchivo.front();
      tropasDeArchivo.pop();     
      tropasDeArchivo.push(auxTropasDeArchivo);
    }
  }

  for(int i = 0; i < 4; i++)
  {
    if(terrisArchivo.front() == terrisASTR[i]) //Esto es para 
    {
      tropasASTR[i] = tropasDeArchivo.front(); 
    }
    else
    {
      std::string auxNomTerriArchivo = terrisArchivo.front();
      terrisArchivo.pop();
      terrisArchivo.push(auxNomTerriArchivo);
      int auxTropasDeArchivo = tropasDeArchivo.front();
      tropasDeArchivo.pop();     
      tropasDeArchivo.push(auxTropasDeArchivo);
    }
  }





  for (int i = 0; i < cantJugadores; i++)
  {
    jugadores.push(new Jugador(cantJugadores, modoJuego, coloresJ[i]));
  }

  continentes[0] = new Continente("America Del Norte", tropasANOR);; 
  continentes[1] = new Continente("America Del Sur", tropasASUR);
  continentes[2] = new Continente("Asia", tropasASIA);
  continentes[3] = new Continente("Africa", tropasAFRC);
  continentes[4] = new Continente("Europa", tropasEROP);
  continentes[5] = new Continente("Australia", tropasASTR);

  if (!jugadores.empty())
  {
    jugadorActual = jugadores.front(); // Inicializa el puntero al primer jugador
  }


}



Jugador *Partida::buscaJ(const std::string color)
{
  std::queue<Jugador *> jugadoresTemp = jugadores; // Copia la cola original
  while (!jugadoresTemp.empty())
  {
    Jugador *jugadorObj = jugadoresTemp.front();
    if (jugadorObj->color == color)
    {
      return jugadorObj; // Devuelve el puntero al jugador con el color especificado
    }
    jugadoresTemp.pop(); // Desencola el jugador actual
  }

  return NULL; // Si no encuentra el jugador
}

Continente *Partida::buscaC(std::string nombreC)
{
  // Uso de iteradores. en cada iteracion, el puntero contiObj señalara al siguiente puntero a continentes almacenados en "continentes"
  for (Continente *contiObj : continentes)
  {
    if (contiObj && contiObj->nombreCont == nombreC)
    {
      return contiObj; // Devuelve el puntero al continente especificado
    }
  }
  return NULL; // Si no encuentra el continente
}

// funcion que busca un Terriorio dado el nombre del territorio y devuelve el puntero al territorio
Territorio *Partida::buscaT(std::string nombreT)
{
  for (Continente *contiObj : continentes) // Itera sobre los continentes
  {
    for (Territorio *terriObj : contiObj->territorios) // Itera sobre los territorios de cada continente
    {
      if (terriObj && terriObj->nombreTerri == nombreT) // Si el territorio existe y tiene el nombre especificado
      {
        return terriObj; // Devuelve el puntero al territorio especificado
      }
    }
  }
  return NULL; // Si no encuentra el territorio
}

/*
void Partida::asignaTerri(Continente *elConti, std::string nomTerri, Jugador *elPlayer)
{

  //


  Territorio *elTerri = new Territorio(nomTerri);
  elTerri->duenoAct = elPlayer;

  elTerri->uniEjercito = 1;
  elPlayer->ejercito = elPlayer->ejercito - 1;
}
*/

void Partida::fortificar()
{
  std::string leQuitoA;
  std::string lePongoA;
  int cantEjercitos;

  std::cout << std::endl;
  std::cout << "Recuerda que actualmente los territorios que dominas son: " << std::endl;
  // Muestra los territorios del jugador actual y la cantidad de ejercitos que tiene en cada uno
  for (Continente *continente : continentes)
  {
    std::cout << continente->nombreCont << std::endl;
    for (Territorio *territorio : continente->territorios)
    {
      if (jugadorActual->color == territorio->duenoAct->color)
      {
        std::cout << territorio->nombreTerri << " tiene: " << territorio->uniEjercito << " tropas" << std::endl;
      }
    }
  }

  // preguntar al usuario que territorio quiere fortificar (asignarle mas ejercitos), y a cual territorio se los quiere quitar para el traslado
  std::cout << std::endl;
  std::cout << "A cual territorio le quieres quitar tropas? ";
  std::cin >> leQuitoA;
  std::cout << "A que territorio quieres ponerle esas tropas? ";
  std::cin >> lePongoA;
  std::cout << "Cuantas tropas quieres ponerle? ";
  std::cin >> cantEjercitos;

  // Busca el territorio al que se le quitaran ejercitos
  Territorio *terriQuito = buscaT(leQuitoA);
  // Busca el territorio al que se le pondran ejercitos
  Territorio *terriPongo = buscaT(lePongoA);

  // Si se encuentran ambos territorios
  if (terriQuito && terriPongo)
  {
    // Si el territorio al que se le quitan ejercitos es del jugador actual
    if (terriQuito->duenoAct == jugadorActual)
    {
      // Si el territorio al que se le ponen ejercitos es del jugador actual
      if (terriPongo->duenoAct == jugadorActual)
      {
        // Si el territorio al que se le quitan ejercitos tiene mas ejercitos que los que se quieren quitar
        if (terriQuito->uniEjercito > cantEjercitos && cantEjercitos < terriQuito->uniEjercito - 1) // Se le resta 1 porque siempre debe quedar al menos 1 ejercito en el territorio
        {
          // Se le quitan los ejercitos al territorio
          terriQuito->uniEjercito = terriQuito->uniEjercito - cantEjercitos;
          // Se le agregan los ejercitos al territorio
          terriPongo->uniEjercito = terriPongo->uniEjercito + cantEjercitos;
          std::cout << std::endl;
          std::cout << "Ahora el territorio " << terriPongo->nombreTerri << " tiene " << terriPongo->uniEjercito << " tropas" << std::endl;
          std::cout << "Y el territorio " << terriQuito->nombreTerri << " tiene " << terriQuito->uniEjercito << " tropas" << std::endl;
          std::cout << std::endl;

          // actualizar el jugador actual, entonces el siguiente jugador en la cola de jugadores sera el jugador actual y el jugador actual pasara a ser el siguiente jugador en la cola
          Jugador *jugadorTemp = jugadorActual;
          jugadores.pop();
          jugadores.push(jugadorTemp);
          jugadorActual = jugadores.front();

          std::cout << "Presione Enter para continuar..." << std::endl;
          std::cin.ignore();
          std::cin.get();
          //system("clear");	
        }
        else
        {
          if (cantEjercitos > terriQuito->uniEjercito - 1)
          {
            std::cout << std::endl;
            std::cout << "Recuerda que siempre debe quedar al menos 1 ejercito en el territorio" << std::endl;
          }
          std::cout << "No se puede realizar la accion" << std::endl;
          std::cout << std::endl;
        }
      }
      else
      {
        std::cout << std::endl;
        std::cout << "No se puede realizar la accion" << std::endl;
        std::cout << "El territorio al que quieres ponerle tropas no es tuyo" << std::endl;
        std::cout << std::endl;
      }
    }
    else
    {
      std::cout << std::endl;
      std::cout << "No se puede realizar la accion" << std::endl; // Si el territorio al que se le quitan ejercitos no es del jugador actual
      std::cout << "El territorio al que quieres quitarle tropas no es tuyo" << std::endl;
      std::cout << std::endl;
    }
  }
  else
  {
    std::cout << std::endl;
    std::cout << "No se puede realizar la accion" << std::endl; // Si no se encuentran ambos territorios
    std::cout << "Los territorios que ingresaste no existen" << std::endl;
    std::cout << std::endl;
  }
}

void Partida::atacar()
{
  std::string atacoA;
  std::string atacoDesde;
  int cantEjercitos;

  std::queue<Jugador *> jugadoresTemp = jugadores; // Copia la cola original

  std::cout << std::endl;
  std::cout << "Recuerda que actualmente los territorios que dominas son: " << std::endl;
  for (Continente *continente : continentes)
  {
    std::cout << continente->nombreCont << std::endl;
    for (Territorio *territorio : continente->territorios)
    {
      if (jugadorActual->color == territorio->duenoAct->color)
      {
        std::cout << " - " << territorio->nombreTerri << " tiene: " << territorio->uniEjercito << " tropas" << std::endl;
      }
    }
  }

  std::cout << std::endl;
  std::cout << "Presione Enter para continuar..." << std::endl;
  std::cin.ignore();
  std::cin.get();

  std::cout << "Antes de atacar, recuerda que actualmente los territorios se encuentran dominados de la siguiente manera: " << std::endl;

  // Muestra los territorios de los otros jugadores y la cantidad de ejercitos que tiene en cada uno, junto con el nombre del jugador
  // porque el siguiente ciclo no imprime los territorios del jugador actual?
  while (!jugadoresTemp.empty())
  {
    Jugador *jugadorObj = jugadoresTemp.front();
    if (jugadorObj->color != jugadorActual->color)
    {
      std::cout << "El jugador " << jugadorObj->color << " domina: " << std::endl;
      for (Continente *continente : continentes)
      {
        std::cout << continente->nombreCont << std::endl;
        for (Territorio *territorio : continente->territorios)
        {
          if (jugadorObj->color == territorio->duenoAct->color)
          {
            std::cout << " - " << territorio->nombreTerri << " tiene: " << territorio->uniEjercito << " tropas" << std::endl;
          }
        }
      }
    }
    std::cout << std::endl;
    jugadoresTemp.pop(); // Desencola el jugador actual de la copia
  }

  // preguntar al usuario que territorio quiere atacar, y desde que territorio quiere atacar
  std::cout << "Desde que territorio quieres atacar? ";
  std::cin >> atacoDesde;
  std::cout << "A que territorio quieres atacar? ";
  std::cin >> atacoA;

  Jugador *jugadorDefensor = buscaT(atacoA)->duenoAct;

  // Busca el territorio al que se le quitaran ejercitos
  Territorio *terriAtaco = buscaT(atacoA);
  // Busca el territorio al que se le pondran ejercitos
  Territorio *terriAtacoDesde = buscaT(atacoDesde);

  // Si se encuentran ambos territorios
  if (terriAtaco && terriAtacoDesde)
  {
    // Si el territorio desde el que se ataca es del jugador actual
    if (terriAtacoDesde->duenoAct == jugadorActual)
    {
      gestorDados(jugadorActual, jugadorDefensor, terriAtacoDesde, terriAtaco);
      Jugador *jugadorTemp = jugadorActual;
      jugadores.pop();
      jugadores.push(jugadorTemp);
      jugadorActual = jugadores.front();
    }
    else
    {
      std::cout << "No se puede realizar la accion" << std::endl; // Si el territorio desde el que se ataca no es del jugador actual
      std::cout << "El territorio desde el que quieres atacar no es tuyo" << std::endl;
    }
  }
  else
  {
    std::cout << "No se puede realizar la accion" << std::endl; // Si no se encuentran ambos territorios
    std::cout << "Uno o los dos territorios que ingresaste no existen" << std::endl;
  }
}

// funcion para los dados
void Partida::gestorDados(Jugador *jugadorAtacante, Jugador *jugadorDefensor, Territorio *terriAtacoDesde, Territorio *terriAtaco)
{
  int dadosAtac;
  int dadosDefen;
  int cantDados;

  do
  {
    std::cout << "Cuantos dados quieres tirar? ";
    std::cin >> cantDados;
  } while (cantDados < 1 || cantDados > 3);

  // ciclo para determinar cuando termina el ataque
  bool terminaAtaque = false;
  while (terminaAtaque != true)
  {
    int confirmOAtaque;

    if (cantDados == 1)
    {
      dadosAtac = rand() % 6 + 1;
      dadosDefen = rand() % 6 + 1;

      std::cout << "El atacante saco: " << dadosAtac << std::endl;
      std::cout << "El defensor saco: " << dadosDefen << std::endl;
    }
    else if (cantDados == 2)
    {
      dadosAtac = rand() % 6 + 1;
      dadosAtac = dadosAtac + rand() % 6 + 1;
      dadosDefen = rand() % 6 + 1;
      dadosDefen = dadosDefen + rand() % 6 + 1;

      std::cout << "El atacante saco en total: " << dadosAtac << std::endl;
      std::cout << "El defensor saco en total: " << dadosDefen << std::endl;
    }
    else if (cantDados == 3)
    {
      dadosAtac = rand() % 6 + 1;
      dadosAtac = dadosAtac + rand() % 6 + 1;
      dadosAtac = dadosAtac + rand() % 6 + 1;

      dadosDefen = rand() % 6 + 1;
      dadosDefen = dadosDefen + rand() % 6 + 1;
      dadosDefen = dadosDefen + rand() % 6 + 1;

      std::cout << "El atacante saco en total: " << dadosAtac << std::endl;
      std::cout << "El defensor saco en total: " << dadosDefen << std::endl;
    }

    // si el atacante saca mas que el defensor
    if (dadosAtac > dadosDefen)
    {
      terriAtaco->uniEjercito = terriAtaco->uniEjercito - 1;
      // si el defensor tiene mas de 0 ejercitos
      if (terriAtaco->uniEjercito <= 0)
      {
        std::cout << "El atacante gano el combate" << std::endl;
        std::cout << "El territorio " << terriAtaco->nombreTerri << " ahora tiene " << terriAtaco->uniEjercito << " tropas" << std::endl;
        std::cout << "El atacante conquisto el territorio " << terriAtaco->nombreTerri << std::endl;
        terriAtaco->duenoAct = jugadorAtacante;
        terriAtaco->uniEjercito = 1;
        std::cout << "El territorio " << terriAtaco->nombreTerri << " ahora pertenece al jugador " << jugadorAtacante->color << std::endl;
        terminaAtaque = true;
        break;
      }
      else if (terriAtaco->uniEjercito >= 1)
      {

        // terriAtaco->uniEjercito = terriAtaco->uniEjercito - 1;
        std::cout << "El atacante gano el combate" << std::endl;
        std::cout << "El territorio " << terriAtaco->nombreTerri << " ahora tiene " << terriAtaco->uniEjercito << " tropas" << std::endl;
        do
        {
          std::cout << "Quieres seguir atacando? (1 = si, 2 = no) ";
          std::cin >> confirmOAtaque;
        } while (confirmOAtaque < 1 || confirmOAtaque > 2);
        if (confirmOAtaque == 2)
        {
          terminaAtaque = true;
          break;
        }
      }
    }
    // si el defensor saca mas o igual que el atacante
    else if (dadosAtac <= dadosDefen)
    {
      terriAtacoDesde->uniEjercito = terriAtacoDesde->uniEjercito - 1;
      if (terriAtacoDesde->uniEjercito <= 1) // Si el territorio desde el que se ataca tiene mas de 1 ejercito
      {

        std::cout << "El defensor (" << jugadorDefensor->color << ") logro resistir el ataque" << std::endl;
        std::cout << "El territorio " << terriAtacoDesde->nombreTerri << " ahora tiene " << terriAtacoDesde->uniEjercito << " tropas" << std::endl;
        std::cout << "El territorio " << terriAtaco->nombreTerri << " ahora tiene " << terriAtaco->uniEjercito << " tropas" << std::endl;
        terriAtacoDesde->uniEjercito = 1;
        terminaAtaque = true;
        break;
      }
      else if (terriAtacoDesde->uniEjercito > 1)
      {

        // terriAtacoDesde->uniEjercito = terriAtacoDesde->uniEjercito - 1;
        std::cout << "El defensor gano el combate" << std::endl;
        std::cout << "El territorio " << terriAtacoDesde->nombreTerri << " ahora tiene " << terriAtacoDesde->uniEjercito << " tropas" << std::endl;
        do
        {
          std::cout << "Quieres seguir atacando? (1 = si, 2 = no) ";
          std::cin >> confirmOAtaque;
        } while (confirmOAtaque < 1 || confirmOAtaque > 2);
        if (confirmOAtaque == 2)
        {
          terminaAtaque = true;
          break;
        }
      }
    }
  }
}

void Partida::guardarPartida(std::string nombreArchivo)
{
  // crear un archivo.txt con el nombre que recibe por parametro
  std::ofstream archivoDePartida(nombreArchivo + ".txt");
  std::queue<Jugador *> jugadoresTemp = jugadores; // Copia la cola original

  if (!archivoDePartida.is_open())
  {
    std::cout << "No se pudo abrir el archivo" << std::endl;
  }
  else
  {
    std::cout << "El archivo se creo correctamente" << std::endl;
  }

  archivoDePartida << "Partida de Risk" << std::endl;
  archivoDePartida << std::endl;

  // Guardar la informacion de los jugadores
  while (!jugadoresTemp.empty())
  {

    archivoDePartida << "Jugador: " << jugadoresTemp.front()->color << std::endl;

    // Guardar los territorios del jugador y cuantas tropas tiene en cada uno
    for (Continente *contiObj : continentes) // Itera sobre los continentes
    {
      for (Territorio *terriObj : contiObj->territorios) // Itera sobre los territorios de cada continente
      {
        if (jugadoresTemp.front()->color == terriObj->duenoAct->color)
        {
          archivoDePartida << terriObj->nombreTerri << " tiene: " << terriObj->uniEjercito << " tropas" << std::endl;
        }
      }
    }

    archivoDePartida << std::endl;
    jugadoresTemp.pop();
  }

  archivoDePartida.close();
}

void Partida::guardarCompimido(std::string nombreArchivo)
{
  std::ofstream archivoDePartida(nombreArchivo + ".bin", std::ios::binary);

  // hacer copia de la cola de jugadores
  std::queue<Jugador *> jugadoresTemp = jugadores; // Copia la cola original

  if (!archivoDePartida.is_open())
  {
    std::cout << "No se pudo abrir el archivo" << std::endl;
  }
  else
  {
    std::cout << "El archivo se creo correctamente" << std::endl;
  }

  std::stringstream output;

  output << "Partida de Risk" << std::endl;
  output << std::endl;

  // Guardar la información de los jugadores
  while (!jugadoresTemp.empty())
  {

    output << "Jugador: " << jugadoresTemp.front()->color << std::endl;

    // Guardar los territorios del jugador y cuantas tropas tiene en cada uno
    for (Continente *contiObj : continentes)
    {
      for (Territorio *terriObj : contiObj->territorios)
      {
        if (jugadoresTemp.front()->color == terriObj->duenoAct->color)
        {
          output << terriObj->nombreTerri << " tiene: " << terriObj->uniEjercito << " tropas" << std::endl;
        }
      }
    }

    output << std::endl;
    jugadoresTemp.pop();
  }

  std::string resultado = output.str();

  // Crear una cadena de caracteres a partir del resultado formateado
  char *cadena = new char[resultado.length() + 1];
  strcpy(cadena, resultado.c_str());

  // Realizar el cálculo de frecuencia en la cadena formateada
  const int maxCaracteres = 256; // Suponemos un máximo de 256 caracteres (ASCII)
  long frecuencia[maxCaracteres] = {0};
  for (int i = 0; cadena[i] != '\0'; i++)
  {
    frecuencia[static_cast<unsigned char>(cadena[i])]++;
  }
  int tamano = sizeof(frecuencia) / sizeof(frecuencia[0]);

  HuffmanArbol arbolhuffman;
  arbolhuffman.generarArbol(cadena, frecuencia, tamano);

  // Cifrar el resultado formateado
  std::string textoComprimido = arbolhuffman.cifrar(resultado);
  archivoDePartida << textoComprimido;

  archivoDePartida.close();
}


/*
void Partida::iniciarPartidaConArchivo(std::string nombreArchivo)
{
  // Determinar que tipo de archivo es, .txt o .bin
  std::string extension = nombreArchivo.substr(nombreArchivo.find_last_of(".") + 1);

  if (extension == "txt")
  {
    std::ifstream archivoDePartida(nombreArchivo);
    std::string linea;

    if (!archivoDePartida.is_open())
    {
      std::cout << "No se pudo abrir el archivo" << std::endl;
    }
    else
    {
      std::cout << "El archivo se abrio correctamente" << std::endl;
    }

    std::string linea;
    std::vector<Jugador> jugadoresDelArchivo;
    Jugador *jugador_actual;
    int contajugadoresDelArchivo = 0;
    std::queue<std::string> territoriosDelArchivo;
    std:: queue<int> tropasDelArchivo;
    std::queue<int> ordenJugadoresDelArchivo;
    

    while (std::getline(archivoDePartida, linea))
    {
      if (linea.find("Jugador: ") != std::string::npos)
      {
        contajugadoresDelArchivo++;

      }
      else if (linea.find(" tiene: ") != std::string::npos)
      {
        std::string nombre_territorio = linea.substr(0, linea.find(" tiene: "));
        std::string cantidad_tropas = linea.substr(linea.find(" tiene: ") + 8, linea.find(" tropas") - linea.find(" tiene: ") - 8);
        
        int tropas = std::stoi(cantidad_tropas);
        tropasDelArchivo.push(tropas);
        territoriosDelArchivo.push(nombre_territorio);
      }
    }

    if(contajugadoresDelArchivo == 3)
    {
      //llenar las primeras 14 posiciones de la cola ordenJugadoresDelArchivo con el numero 1
      for(int i = 0; i < 14; i++)
      {
        ordenJugadoresDelArchivo.push(1);
      }
      //llenar las siguientes 14 posiciones de la cola ordenJugadoresDelArchivo con el numero 2
      for(int i = 0; i < 14; i++)
      {
        ordenJugadoresDelArchivo.push(2);
      }
      //llenar las ultimas 14 posiciones de la cola ordenJugadoresDelArchivo con el numero 3
      for(int i = 0; i < 14; i++)
      {
        ordenJugadoresDelArchivo.push(3);
      } 
    }
    else if (contajugadoresDelArchivo == 4)
    {

    }
    

    Partida *partida = new Partida('n', contajugadoresDelArchivo);


    archivoDePartida.close();
  }
  else if (extension == "bin")
  {
    std::ifstream archivoDePartida(nombreArchivo, std::ios::binary);
    std::string linea;

    if (!archivoDePartida.is_open())
    {
      std::cout << "No se pudo abrir el archivo" << std::endl;
    }
    else
    {
      std::cout << "El archivo se abrio correctamente" << std::endl;
    }

    archivoDePartida.close();
  }
  else
  {
    std::cout << "El archivo no es valido" << std::endl;
  }
}
*/