#include <iostream>
#include "io.h"

int main() {
	int x, y;
	x = readNumber();
	y = readNumber();
	writeAnswer(x+y);
	return 0;
}
