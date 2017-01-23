LIBS = `pkg-config --libs gtk+-3.0`

CFLAGS = `pkg-config --cflags gtk+-3.0`

output: main.o
	g++ main.o -o Salida


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
