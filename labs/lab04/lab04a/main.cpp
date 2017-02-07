#include "WiimoteBtns.h"

int main() {
	WiimoteBtns btnListener = WiimoteBtns();
	btnListener.Listen();
	return 0;
}
