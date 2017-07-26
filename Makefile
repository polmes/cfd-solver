CC = g++-6
CFLAGS = -std=c++14 -I ~/.local/include/eigen3 -g -O3 -c -Wall -pedantic
LFLAGS = -std=c++14 -g
LIBS = -pthread

EXE = cfd

$(EXE): obj/main.o obj/volume.o
	$(CC) $(LFLAGS) obj/*.o -o $(EXE) $(LIBS)

obj/main.o: main.cpp volume.hpp
	$(CC) $(CFLAGS) main.cpp -o obj/main.o $(LIBS)

obj/volume.o: volume.cpp volume.hpp
	$(CC) $(CFLAGS) volume.cpp -o obj/volume.o $(LIBS)

clean:
	rm $(EXE) obj/*
