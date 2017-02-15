OBJS = ServoPosition.o GPIO.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

ServoPosition: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o ServoPosition

ServoPosition.o: GPIO.h ServoPosition.cpp
	$(CC) $(CFLAGS) ServoPosition.cpp

GPIO.o: GPIO.h GPIO.cpp
	$(CC) $(CFLAGS) GPIO.cpp

clean:
	rm *.o
	rm ServoPosition
