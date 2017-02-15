OBJS = MultiSpeed.o GPIO.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

MultiSpeed: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o MultiSpeed

MultiSpeed.o: GPIO.h MultiSpeed.cpp
	$(CC) $(CFLAGS) MultiSpeed.cpp

GPIO.o: GPIO.h GPIO.cpp
	$(CC) $(CFLAGS) GPIO.cpp

clean:
	rm *.o
	rm MultiSpeed
