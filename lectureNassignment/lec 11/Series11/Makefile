all: start

start: main.o upper.o
		g++ main.o upper.o -o main
		./main

main.o: main.cpp
		g++ -c main.cpp

upper.o: upper.cpp
		g++ -c upper.cpp