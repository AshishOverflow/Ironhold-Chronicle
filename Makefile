all: chronicle

CC := g++
CCFLAGS := -Wall -I ./include/ -c

inputbuffer.o: ./src/InputBuffer.cpp
	$(CC) $(CCFLAGS) -o inputbuffer.o ./src/InputBuffer.cpp

console.o: ./src/Console.cpp
	$(CC) $(CCFLAGS) -o console.o ./src/Console.cpp

command.o: ./src/Command.cpp
	$(CC) $(CCFLAGS) -o command.o ./src/Command.cpp

player.o: ./src/Player.cpp
	$(CC) $(CCFLAGS) -o player.o ./src/Player.cpp


worldstate.o: ./src/WorldState.cpp
	$(CC) $(CCFLAGS) -o worldstate.o ./src/WorldState.cpp

main.o: ./src/main.cpp
	$(CC) $(CCFLAGS) -o main.o ./src/main.cpp

chronicle: console.o main.o inputbuffer.o command.o player.o worldstate.o
	g++ console.o main.o inputbuffer.o command.o player.o worldstate.o -o chronicle

clean:
	rm -f *.o chronicle