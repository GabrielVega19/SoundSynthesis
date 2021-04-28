all: KSGuitarSim

KSGuitarSim: CircularBuffer.o StringSound.o KSGuitarSim.o
	g++ StringSound.o KSGuitarSim.o CircularBuffer.o -o KSGuitarSim -lsfml-audio -lsfml-system -lsfml-graphics -lsfml-window 

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	g++ CircularBuffer.cpp -c -g -ansi -Wall -Werror -pedantic -std=c++17

StringSound.o: StringSound.cpp StringSound.h
	g++ StringSound.cpp -c -g -ansi -Wall -Werror -pedantic -std=c++17

KSGuitarSim.o: KSGuitarSim.cpp
	g++ KSGuitarSim.cpp -c -g -ansi -Wall -Werror -pedantic -std=c++17

clean:
	rm *.o KSGuitarSim