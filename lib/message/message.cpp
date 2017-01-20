#include <iostream>
#include "message.h"

using namespace std;

void message::printMessage() {
  cout << "Makefile example\n";
}

message::message() {
  cout << "construct\n";
}
