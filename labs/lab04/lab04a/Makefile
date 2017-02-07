OBJS = main.o WiimoteBtns.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o: WiimoteBtns.h main.cpp
	$(CC) $(CFLAGS) main.cpp

WiimoteBtns.o: WiimoteBtns.h WiimoteBtns.cpp
	$(CC) $(CFLAGS) WiimoteBtns.cpp

clean:
	rm *.o
	rm main
