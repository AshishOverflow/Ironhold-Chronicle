all: ironhold run

console.o: ./src/console.cpp
	g++ -Wall -c -o console.o ./src/console.cpp

main.o: ./src/main.cpp
	g++ -Wall -c -o main.o ./src/main.cpp

ironhold: console.o main.o
	g++ console.o main.o -o ironhold

run:
	./ironhold

clean:
	rm -f *.o ironhold