OBJS = ZedMain.o ZedBoard.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

ZedMain: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o ZedMain

ZedMain.o: ZedBoard.h ZedMain.cpp
	$(CC) $(CFLAGS) ZedMain.cpp

ZedBoard.o: ZedBoard.h ZedBoard.cpp
	$(CC) $(CFLAGS) ZedBoard.cpp

clean:
	rm *.o
	rm ZedMain
