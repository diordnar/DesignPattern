all: Memento.exe

Memento.o: Memento.cpp
	g++ -Wall -O2 -c Memento.cpp

Memento.exe: Memento.o
	g++ Memento.o -o Memento.exe

.PHONY: all

.PHONY: clean

clean:
	rm -f Memento.o Memento.exe
