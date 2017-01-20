output: main.o message.o
	g++ main.o message.o -o Salida

main.o: main.cpp
	g++ -c main.cpp

message.o: lib/message/message.cpp
	g++ -c message.cpp
clean:
	rm *.o Salida
