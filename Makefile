PKGS=gtk+-3.0 glib-2.0 gmodule-2.0
CFLAGS=-g3 `pkg-config --cflags $(PKGS)`
LDLIBS=`pkg-config --libs $(PKGS)`
CC=gcc

main: main.o callbacks.o
	$(CC) -o $@ $^ $(LDLIBS)

#Comando de compilacion
#gcc `pkg-config --cflags gtk+-3.0` -o main main.cpp `pkg-config --libs gtk+-3.0` -export-dynamic


#output: main.o jugador.o message.o
#	g++ main.o jugador.o message.o -o Salida

#main.o: main.cpp
#	g++ -c main.cpp

#jugador.o: lib/jugador/jugador.cpp
#	g++ -c lib/jugador/jugador.cpp

#message.o: lib/message/message.cpp
#	g++ -c lib/message/message.cpp

clean:
	rm *.o Salida
