gedMain: ZedMain.o ZedBoard.o
	g++ ZedMain.o ZedBoard.o -o ZedMain

ZedMain.o: ZedMain.cpp ZedBoard.h
	g++ -g -Wall -c ZedMain.cpp

ZedBoard.o: ZedBoard.cpp ZedBoard.h
	g++ -g -Wall -c ZedBoard.cpp

clean:
	rm ZedMain.o ZedBoard.o ZedMain
