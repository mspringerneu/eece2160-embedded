OBJS = main.o WiimoteAccel.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o: WiimoteAccel.h main.cpp
	$(CC) $(CFLAGS) main.cpp

WiimoteBtns.o: WiimoteAccel.h WiimoteAccel.cpp
	$(CC) $(CFLAGS) WiimoteAccel.cpp

clean:
	rm *.o
	rm main
