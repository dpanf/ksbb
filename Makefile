all: main

main: main.o Parser.o Solver.o
	g++ main.o Parser.o Solver.o -o main

main.o: main.cpp
	g++ -c main.cpp

Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp Parser.h

Solver.o: Solver.cpp Solver.h
	g++ -c Solver.cpp Solver.h

clean:
	rm -rf *.o main
