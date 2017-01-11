#include <iostream>
#include "constants.h"

using namespace std;

float getBuildingHeight() {
    float height;
    cout << "Please enter the height of the building (in meters): ";
    cin >> height;
    return height;
}

float getDistance(int t) {
    return (initVel * t) + ((gravity * (t * t)) / 2);
}

void printHeight(int t, float height) {
    cout << "At " << t << " seconds, the ball is at height: " << height << " meters" << endl;
}

int main() {
	float initHeight, currentHeight, dist;
    initHeight = getBuildingHeight();
    for (int t = 0; t <= numSecs; t++) {
        currentHeight = initHeight - getDistance(t);
        if (currentHeight > 0) {
            printHeight(t, currentHeight);
        }
        else {
            cout << "At " << t << " seconds, the ball is on the ground" << endl;
            break;
        }
    }
	return 0;
}
