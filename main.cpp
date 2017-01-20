#include <iostream>
#include <cstdlib>
#include "lib/message/message.h"

#include "lib/jugador/jugador.h"

using namespace std;
message m;
jugador j;
int main() {
  cout << "Primer aviso, carba paga la coca\n";
  m.printMessage();
}
