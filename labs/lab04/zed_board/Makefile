OBJS = ZedMain.o ZedBoard.o WiimoteAccel.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

ZedMain: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o ZedMain

ZedMain.o: ZedBoard.h WiimoteAccel.h ZedMain.cpp
	$(CC) $(CFLAGS) ZedMain.cpp

ZedBoard.o: ZedBoard.h ZedBoard.cpp
	$(CC) $(CFLAGS) ZedBoard.cpp

WiimoteAccel.o: WiimoteAccel.h WiimoteAccel.cpp
	$(CC) $(CFLAGS) WiimoteAccel.cpp

clean:
	rm *.o
	rm ZedMain
