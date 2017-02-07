OBJS = Main.o Furniture.o Table.o Bed.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o Main

Main.o: Table.h Bed.h Main.cpp
	$(CC) $(CFLAGS) Main.cpp

Furniture.o: Furniture.h Furniture.cpp
	$(CC) $(CFLAGS) Furniture.cpp

Table.o: Table.h Table.cpp
	$(CC) $(CFLAGS) Table.cpp

Bed.o: Bed.h Bed.cpp
	$(CC) $(CFLAGS) Bed.cpp

clean:
	rm *.o
	rm Main
