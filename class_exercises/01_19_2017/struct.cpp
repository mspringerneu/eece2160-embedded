/*
 * Project:   struct.cpp
 * Authors: 	Matthew Springer
 * Date:	    Created on Jan 19, 2017
 * Purpose:	  In class exercise to practice using C++ struct datatype
 */

#include <iostream>
#include <string>

using namespace std;

// struct for holding information about a tv program
struct tv_program {
       string programName;  // the name of the show
       char weekday;        // M, T, W, R, F
       int minutes;         // running time
};

// global variables
int numShows = 5;
tv_program * tvShows = new tv_program[numShows];

/*
 * Function:    GetShowInfo
 * Input:       None
 * Output:      None
 * Purpose:     Creates an array of tv_programs based upon user input
 */
void GetShowInfo() {
     for (int i = 0; i < numShows; i++) {
        tv_program * tvShow = new tv_program;
        cout << endl << "TV SHOW NUMBER " << i+1 << ":" << endl;
        cout << "Enter the name of the TV Program: " << endl;
        cin >> tvShow->programName;
        cout << "Enter the day of the week the show is on (M, T, W, R, or F): " << endl;
        cin >> tvShow->weekday;
        cout << "Enter the running time of the show (in minutes): " << endl;
        cin >> tvShow->minutes;
        tvShows[i] = *tvShow;
        delete tvShow;
    }
}

/*
 * Function:    PrintShowInfo
 * Input:       None
 * Output:      None
 * Purpose:     Prints the information for each of the tv_programs in the array
 */
void PrintShowInfo() {
     for (int i = 0; i < numShows; i++) {
        cout << endl << "TV SHOW " << i+1 << " INFORMATION:" << endl;
        cout << "Program Name :" << tvShows[i].programName << endl;
        cout << "Day of the Week: " << tvShows[i].weekday << endl;
        cout << "Running Time: " << tvShows[i].minutes << " minutes" << endl;
    }
}

/*
 * Function:    SortShows
 * Input:       None
 * Output:      None
 * Purpose:     Sort the array of tv_programs alphabetically by program name
 */
void SortShows() {

}

int main() {
    GetShowInfo();
    PrintShowInfo();
}