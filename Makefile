CC = g++
CFLAGS = -std=c++11

all: fco

fco: fco.o
	$(CC) $(CFLAGS) main.cpp fco.o -o fco

fco.o: fco.cpp fco.hpp
	$(CC) $(CFLAGS) -c fco.cpp fco.hpp

clean:
	rm *~ *.o fco
