#include "WiimoteAccel.h"

int main() {
	WiimoteAccel accelListener = WiimoteAccel();
	accelListener.Listen();
	return 0;
}
