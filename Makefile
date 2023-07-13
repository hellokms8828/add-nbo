#Makefile
all: add-nbo

add-nbo: main.o
	g++ -o add-nbo main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -f sum-test
	rm -f *.o


