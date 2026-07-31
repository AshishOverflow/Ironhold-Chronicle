all: chronicle

inputbuffer.o: ./src/InputBuffer.cpp
	g++ -Wall -c -I ./include/ -o inputbuffer.o ./src/InputBuffer.cpp

console.o: ./src/console.cpp
	g++ -Wall -c -I ./include/ -o console.o ./src/console.cpp

main.o: ./src/main.cpp
	g++ -Wall -c -I ./include/ -o main.o ./src/main.cpp

chronicle: console.o main.o inputbuffer.o
	g++ console.o main.o inputbuffer.o -o chronicle

clean:
	rm -f *.o chronicle