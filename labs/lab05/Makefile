OBJS = main.o GPIO.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o: GPIO.h main.cpp
	$(CC) $(CFLAGS) main.cpp

GPIO.o: GPIO.h GPIO.cpp
	$(CC) $(CFLAGS) GPIO.cpp

clean:
	rm *.o
	rm main
