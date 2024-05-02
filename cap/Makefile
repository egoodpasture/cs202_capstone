CXX=        g++
CXXFLAGS=   -g -Wall -std=gnu++11
SHELL=      bash

all:        main

main:   main.o Enemy.o
	$(CXX) $(CXXFLAGS) main.o Enemy.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

CardDeck.o: Enemy.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

clean:
	rm -f *.o main

