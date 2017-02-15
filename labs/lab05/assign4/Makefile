OBJS = ServoSpeed.o GPIO.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

ServoSpeed: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o ServoSpeed

ServoSpeed.o: GPIO.h ServoSpeed.cpp
	$(CC) $(CFLAGS) ServoSpeed.cpp

GPIO.o: GPIO.h GPIO.cpp
	$(CC) $(CFLAGS) GPIO.cpp

clean:
	rm *.o
	rm ServoSpeed
