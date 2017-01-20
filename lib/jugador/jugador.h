#ifndef JUGADOR_H
#define JUGADOR_H

#define MaxPlayers 40

// Includes

#include <string>
using namespace std;

class jugador {
private:

public:

  jugador();


  // Structs vamos a crear un máximo de 40 jugadores de momento
  struct Player // Esctructura que guarda los dispositivos conectados al ESP, y
                // tenerlos siempre accesibles.
  {
    string _Nombre;
    string _PiernaDominante;
  };

  struct Player PlayerList[MaxPlayers];
};

#endif // ifndef JUGADOR_H
